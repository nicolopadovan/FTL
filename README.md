# Innovative Utilizations of Non-Communication in Quantum Entanglement Within a Simplified Framework: Theoretical Explorations in Superluminal Information Transmission via Specially-Prepared Binary Qubit Systems

## Abstract
This paper introduces a groundbreaking approach to Faster-Than-Light (FTL) communication, operating within a constrained quantum framework. By utilizing uniquely prepared entangled qubits, we propose a communication system that, while sometimes ambiguous, guarantees against the transmission of false information.

## Background
The quest for FTL communication has been a long-standing ambition in the realm of theoretical physics and advanced communication systems. Quantum mechanics, with its peculiar properties, has shown glimpses of promise in this direction. The framework detailed in this paper proposes a quantum communication model that harnesses certain properties of entangled qubits for potential FTL communication.

## Introduction
Our method aims to simplify and make feasible the concept of FTL communication by introducing a quantum model, defined within particular constraints. This paper delineates this model and elaborates on its functioning and implications.

## System Constraints
Integral to our conceptualization are the following assumptions:

1. **Qubit Stability**: Assumes negligible decay of entanglement and minimal interference.
2. **Binary Entanglement**: Qubits shared between Sender (S) and Receiver (R) are binary entangled, ensuring a mirrored state collapse.
3. **Qubit Preparation**: Qubits, when measured by S, collapse predictably to an UP state.
4. **Pre-agreed Timing**: Both parties pre-determine the communication's timing.
5. **Binary Representation**: Simplified representation equates UP state to binary '1' and DOWN to binary '0'.

## Proposed Communication Model
Envision two distinct sets of qubits: A and B, each comprising 8 qubits. Both sets operate under the previously defined constraints, with A and B symbolizing binary states 0 and 1, respectively.

**Protocol**:
- To convey a '1', S measures every qubit in Set B, ensuring their collapse to state 1, while Set A remains unmeasured.
- Post-operation, each qubit in Set B is recorded as 1. Conversely, qubits in Set A present a 50% likelihood for either state.
- R then can infer:
  - A definite measurement in Set B (all '1's) coupled with even a single '0' in Set A confirms B's measurement and A's non-measurement.
  - Identical states across sets result in ambiguity.

Critically, this process ensures the receiver never misconstrues the sender's intended message. Although potential ambiguity exists, false information transmission is impossible.

## Scalability & Reliability
The model's effectiveness hinges on the set size, influencing the probability of message ambiguity:
- 2 qubits/set leads to 25% ambiguity.
- 4 qubits/set results in 6.25% ambiguity.
- 8 qubits/set experiences 0.390625% ambiguity.
- 16 qubits/set reduces ambiguity to 0.00152588%.

Expanding the set size directly reduces ambiguity, thereby boosting communication reliability.

## Note on the No-Communication Theorem and the Proposed Model
The no-communication theorem, a well-established principle in quantum mechanics, states that two parties sharing entangled particles cannot use the act of measurement alone to send information between them without a classical channel of communication. The proposed FTL communication model does not challenge or violate this theorem; rather, it works within its confines and employs a creative twist.

To clarify:

**Pre-established Communication**

Our model necessitates a classical communication between the sender (S) and the receiver (R) prior to any quantum "FTL" communication. During this classical communication, both parties agree upon a specific date (or time) when the quantum communication will take place. This pre-established communication aligns with the requirements of the no-communication theorem.

**Utilizing "Non-information"**

The genius of the model lies in its utilization of what might be termed "non-information." Instead of trying to send a definitive message through quantum means (which would directly contravene the no-communication theorem), the sender merely decides whether or not to measure a set of qubits. The receiver's subsequent measurements can then provide a certainty about what the sender didn't do, rather than what they did. It's this absence of action—a definite non-measurement of a specific set—that conveys the information.

**Not a Conventional Message**

The proposed system does not send messages in the traditional sense. It doesn't convey specific quantum states or utilize the entangled particles to encode information. Rather, it's the deliberate non-action by the sender, combined with the pre-agreed upon timing, that allows the receiver to infer a binary message.

In essence, the model respects the principles of the no-communication theorem while proposing a unique workaround: using inaction, rather than action, in combination with prior classical communication to convey information.

## Note on Qubit Preparation and Measurement in Entanglement:
**Initial Entanglement**

It's entirely feasible to entangle two qubits such that each one, when measured independently and without any prior manipulation post-entanglement, has a 50% chance of collapsing to either the UP (|0⟩) or DOWN (|1⟩) state. This is a standard outcome when using a gate like the Hadamard gate on a qubit prepared in the |0⟩ state and then using a controlled gate to entangle it with another qubit.

**Deterministic State Collapse**

Forcing a qubit to collapse to a deterministic state isn't about "forcing" in the literal sense, but more about preparing or manipulating the qubit's superposition. If we have a qubit that's in an equal superposition (like after passing it through a Hadamard gate), it has equal probabilities of collapsing to |0⟩ or |1⟩ upon measurement. However, using specific quantum gates, we can manipulate this superposition such that the qubit is virtually in the |0⟩ or |1⟩ state. When measured, it will collapse to that specific state with near certainty.

**Behavior of the Entangled Partner**

The crux of quantum entanglement is that the state of one entangled qubit immediately determines the state of its partner, regardless of the distance between them. If one qubit of an entangled pair is manipulated (not just measured) to be in a specific state, the other qubit's state is determined correspondingly. However, if the first qubit isn't measured, and we don't have any information about its state, the second qubit retains its original probabilistic nature from when they were first entangled. This means that observing the second qubit, without any knowledge of the first qubit's measurement, still results in a 50% chance of being UP or DOWN.

This behavior upholds the principle of quantum mechanics where the act of measurement collapses the qubit's state. Until such measurement occurs, qubits remain in their superposition, and their entangled partners mirror this behavior.

## Note on Causality, Special Relativity, and the FTL Communication Model
The proposed quantum FTL communication model, especially when conveying genuinely unexpected information to the receiver, introduces pronounced concerns related to both causality and the principles of special relativity:

**Causality Implications**

Transmitting information faster than light could result in scenarios where cause and effect relationships become muddled or reversed. For example, if the receiver acts upon a message before its cause (sender's action or inaction) has "classically" transpired, it gives rise to potential temporal paradoxes or causal loops.

**Challenges to Special Relativity**

Einstein's theory of special relativity posits that the speed of light is the upper limit for the transfer of information. The proposed model, which suggests FTL communication, challenges this fundamental postulate. It raises critical questions about how the model could coexist with, or modify our understanding of, established relativistic principles.

**Interplay of Quantum Mechanics and Relativity**

The system underscores the already complex relationship between quantum mechanics and relativity. While quantum mechanics is grounded in probabilities and uncertainties, relativity emphasizes the constancy of the speed of light. The proposed model sits at this intersection, highlighting areas that might need reconsideration or redefinition.

**Operational Concerns**

Beyond the theoretical challenges, operationalizing such a system, given these implications, demands extreme caution. Any real-world implementation would need to address not only the technical hurdles but also the profound implications for our understanding of time, space, and reality.

In light of these considerations, it is essential to approach the proposed FTL communication model with both curiosity and caution. While it presents a fascinating avenue for exploration, the potential ramifications necessitate rigorous scrutiny, interdisciplinary dialogue, and further empirical investigation.
