## State

```mermaid
mindmap
  root((State Diagram))
    States
      "Definition"
        "Conditions during object life"
      "Initial State"
        "Symbol ●"
      "Final State"
        "Symbol ◎"
      "Simple State"
      "Composite State"
      "Substate / Superstate"
      "Entry / Exit Actions"
    Transitions
      "Definition"
        "Movement between states"
      "Trigger"
        "Event that causes transition"
      Guard
        Condition 
          (boolean expression)
      Action
        Executed during transition 
          (/action)
      Notation
        Event + Square bracket + Guard + Square bracket + / Action"
    Pseudostates
      "Initial"
      "Final"
      "Choice"
        "Symbol ◆"
      "Junction"
        "Merge point"
      "History"
        "Symbol H or H*"
    Relationships
      "State to State"
        "Solid arrow"
      "Composite to Substates"
        "Containment"
      "Entry and Exit points"

```
---

## Additional things

### Functor
- is an object of a struct/class that acts like a function due to operation() overloading