## Sequece

```mermaid
mindmap
  root((Sequence Diagram))
    Definition
      "Interaction diagram"
      "Emphasises time ordering of messages"
    Elements
      "Objects"
      "Lifelines"
      "Messages"
      "Constraints: new, destroyed, transient"
    Uses
      "Show dynamic behaviour"
      "Model creation/modification/destruction"
      "Capture scenarios and flows"
    Features
      "Vertical axis = time"
      "Horizontal axis = objects"
      "Clear visual cue to control flow"
    Notes
      "Best for message order"
      "Complementary to collaboration diagrams"

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