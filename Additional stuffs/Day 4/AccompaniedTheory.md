## State

```mermaid
mindmap
  root((State Diagram))
    States
      Definition:::def
      Initial State (●)
      Final State (◎)
      Simple State
      Composite State
      Substate / Superstate
      Entry / Exit Actions
    Transitions
      Definition:::def
      Trigger (event)
      Guard Condition [ ]
      Action (/ action)
      Notation: Event [Guard] / Action
    Pseudostates
      Initial
      Final
      Choice (◆)
      Junction (merge)
      History (H, H*)
    Relationships
      State → State (solid arrow)
      Composite → Substates (containment)
      Entry / Exit points
```
---

## Additional things

### Functor
- is an object of a struct/class that acts like a function due to operation() overloading