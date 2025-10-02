## State

```mermaid
mindmap
  root((State Diagram))
    States
      "Definition (conditions during object life)"
      "Initial State (●)"
      "Final State (◎)"
      "Simple State"
      "Composite State"
      "Substate / Superstate"
      "Entry / Exit Actions"
    Transitions
      "Definition (movement between states)"
      "Trigger (event)"
      "Guard Condition [condition]"
      "Action (/action)"
      "Notation: Event [Guard] / Action"
    Pseudostates
      "Initial"
      "Final"
      "Choice (◆)"
      "Junction (merge)"
      "History (H or H*)"
    Relationships
      "State to State (solid arrow)"
      "Composite to Substates (containment)"
      "Entry and Exit points"

```
---

## Additional things

### Functor
- is an object of a struct/class that acts like a function due to operation() overloading