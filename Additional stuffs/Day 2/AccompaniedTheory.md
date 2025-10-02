## Sequece

```mermaid
mindmap
  root((Sequence Diagram))
    Lifelines
      "Definition (participant in interaction)"
      "Actor (stick figure)"
      "Object (rectangle + dashed line)"
      "Boundary / Control / Entity stereotypes"
    Messages
      "Synchronous (solid arrow, filled head)"
      "Asynchronous (solid arrow, open head)"
      "Return (dashed arrow back)"
      "Create (arrow to lifeline head)"
      "Destroy (X at end of lifeline)"
    Activations
      "Execution bar (thin rectangle on lifeline)"
    Fragments
      "alt (if/else)"
      "loop (repetition)"
      "opt (optional)"
      "par (parallel)"
      "region (critical section)"
    Relationships
      "Time order: top to bottom"
      "Actor to Object (start interaction)"
      "Object to Object (message passing)"
      "Self-call (arrow loops back)"
```

---
## Package

```mermaid
mindmap
  root((Package Diagram))
    Definition
      "Groups UML elements"
      "Shown as a tabbed folder"
    Purpose
      "Organise system into groups"
      "Control visibility"
      "Manage namespaces"
    Elements
      "Classes"
      "Interfaces"
      "Components"
      "Nodes"
      "Use cases"
      "Other packages"
    Rules
      "Unique package names"
      "Owns its elements"
      "Deleting package deletes elements"
    Use Cases
      "System decomposition"
      "Subsystem visualisation"
      "Namespace management"


```

---

## Additional things

### Functor
- is an object of a struct/class that acts like a function due to operation() overloading