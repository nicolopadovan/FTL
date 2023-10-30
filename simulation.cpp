#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


constexpr uint SET_SIZE = 32;
constexpr uint N_MESSAGES = 100000 ;
constexpr uint MESSAGE_SIZE = 8;

constexpr uint TOTAL_BITS = N_MESSAGES * MESSAGE_SIZE;
constexpr uint QUBITS_USED = TOTAL_BITS * SET_SIZE;

/** 
 * @brief Measure a Qubit
 * @return A bitset representing the Qubit
*/ 
uint8_t measureQubit() {
    return rand() % 2;
}

/**
 * @brief Generate a random message of size MESSAGE_SIZE
 * @return A bitset representing the message
*/
bitset<MESSAGE_SIZE> randomMessage() {
    bitset<MESSAGE_SIZE> message;
    for (int i = 0; i < MESSAGE_SIZE; ++i) {
        message[i] = rand() % 2;
    }
    return message;
}

/**
 * @brief Send a bit using the two sets
 * @param bit The bit to send
 * @param set_a The first set, representing 0
 * @param set_b The second set, representing 1
*/
void sendBit(bitset<1> bit, bitset<SET_SIZE>& set_a, bitset<SET_SIZE>& set_b) {
    // We reset the sets for good measure, but this is not necessary since we are later using the set() and reset() functions
    set_a.reset();
    set_b.reset();

    if (bit == 0) {
        set_a.set(); // set all bits to 1
        set_b.reset(); // set all bits to 0 (random)
    } else {
        set_a.reset(); // set all bits to 0 (random)
        set_b.set(); // set all bits to 1
    }
}

/**
 * @brief Measure a set of qubits
 * @param set The set of qubits to measure
 * @return A bitset representing the result of the measurement
*/
bitset<SET_SIZE> measureSet(const bitset<SET_SIZE>& set) {
    bitset<SET_SIZE> result;
    for (int i = 0; i < SET_SIZE; ++i) {
        if (set[i] == 1) {
            // If the bit is 1, then the result is 1
            result[i] = 1;
        } else {
            // If the bit is 0 (not measured), then the result is random
            result[i] = measureQubit();
        }
    }
    return result;
}

int8_t receiveBit(const bitset<SET_SIZE>& set_a, const bitset<SET_SIZE>& set_b) {
    bitset<SET_SIZE> const set_a_bits = measureSet(set_a);
    bitset<SET_SIZE> const set_b_bits = measureSet(set_b);

    bool set_a_all_ones = (set_a_bits.count() == SET_SIZE);
    bool set_b_all_ones = (set_b_bits.count() == SET_SIZE);

    bool set_a_contains_zero = (set_a_bits.count() < SET_SIZE);
    bool set_b_contains_zero = (set_b_bits.count() < SET_SIZE);

    if (set_a_all_ones && set_b_all_ones) {
        return -1; // ambiguous
    } else if (set_a_contains_zero && set_b_contains_zero) {
        return -2; // no message sent. Not used in current simulation
    } else if (set_a_all_ones && set_b_contains_zero) {
        return 0;
    } else if (set_a_contains_zero && set_b_all_ones) {
        return 1;
    }
    return -1; // ambiguous
}

typedef pair<bitset<MESSAGE_SIZE>, bool> result;

result simulateMessage(
    const bitset<MESSAGE_SIZE>& message,
    bitset<SET_SIZE>& set_a,
    bitset<SET_SIZE>& set_b,
    int& ambiguous_bit_count,
    int& correct_bit_count,
    int& incorrect_bit_count
) {
    bitset<MESSAGE_SIZE> received_message;
    bool ambiguous = false;

    for (int i = 0; i < MESSAGE_SIZE; ++i) {
        bool val = message[i];
        bitset<1> bit(val);
        sendBit(bit, set_a, set_b);
        int received_bit = receiveBit(set_a, set_b);
        
        received_message[i] = received_bit;

        if (received_bit == -1) {
            ambiguous_bit_count++;
            ambiguous = true;
        } else if (received_bit == val) {
            correct_bit_count++;
        } else {
            incorrect_bit_count++;
        }
    }

    return make_pair(received_message, ambiguous);
}

int main() {
    srand(time(NULL));
    bitset<SET_SIZE> set_a, set_b;

    int ambiguous_count = 0;
    int correct_count = 0;
    int incorrect_count = 0;

    int ambiguous_bit_count = 0;
    int correct_bit_count = 0;
    int incorrect_bit_count = 0;

    for (int i = 0; i < N_MESSAGES; ++i) {
        bitset<MESSAGE_SIZE> message = randomMessage();
        result receivedMessageResult = simulateMessage(message, set_a, set_b, ambiguous_bit_count, correct_bit_count, incorrect_bit_count);
        bool ambiguous = receivedMessageResult.second;
        bitset<MESSAGE_SIZE> receivedMessage = receivedMessageResult.first;

        if (receivedMessage == message) {
            correct_count++;
        } else if (ambiguous) {
            ambiguous_count++;
        } else {
            incorrect_count++;
        }
    }

    cout << "Number of qubits used: " << QUBITS_USED << endl;
    cout << "Number of messages sent: " << N_MESSAGES << endl;
    cout << "Number of bits sent: " << TOTAL_BITS << endl;
    cout << "Message size: " << MESSAGE_SIZE << endl;

    cout << endl;

    cout << "Correct messages: " << correct_count << endl;
    cout << "Ambiguous messages: " << ambiguous_count << endl;
    cout << "Percentage of ambiguous message: " << 100 * (double) ambiguous_count / N_MESSAGES << "%" << endl;

    cout << endl;

    cout << "Correct bits: " << correct_bit_count << endl;
    cout << "Ambiguous bits: " << ambiguous_bit_count << endl;
    cout << "Incorrect bits: " << incorrect_bit_count << " (Control) " << endl;
    cout << "Percentage of ambiguous bit result: " << 100 * (double) ambiguous_bit_count / TOTAL_BITS << "%" << endl;

    cout << endl; 

    cout << "Theoretical probability of ambiguous bit result: " << 100 * pow(0.5, SET_SIZE) << "%" << endl;
    cout << "Or " << pow(0.5, SET_SIZE) * TOTAL_BITS << " out of " << TOTAL_BITS << endl;

    return 0;
}
