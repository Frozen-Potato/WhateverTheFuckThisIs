```mermaid
mindmap
Basic Structural Modeling
  Classes
    Definition: set of objects with attributes, operations, relationships
    Attributes
    Operations
    (public +, private -, protected #)
    Abstract (italic) vs Concrete Classes
    Active Classes
  Relationships
    Association (straight line)
      Multiplicity
        one to one
        one to many
        many to many
      Roles (verb on line)
      Aggregation (straight line, unfilled diamond)
      Composition (straight line, filled diamond)
    Generalization
      Inheritance (straight line, empty arrow toward parent)
      Abstract Parent (italic name)
    Dependency (dash to dependant, solid arrow)
    Realization (dash to interface, solid arrow)
  Common Mechanisms
    Specifications
    Adornments
      Visibility markers
      Constraints
    Common Divisions
      Interface vs Implementation
      Type vs Role
    Extensibility Mechanisms
      Stereotypes
      Tagged Values
      Constraints
  Diagrams
    Purpose: visual representation of model elements
    Types of Diagrams
      Structural
      Behavioral
      Architectural
    Notation conventions
    Well-formedness rules
  Class Diagrams
    Elements
      Classes
      Interfaces
      Associations
      Generalizations
      Dependencies
    Features
      Multiplicity
      Navigability
      Constraints
    Uses
      Modeling vocabulary of system
      Blueprint for design
      Reverse/forward engineering
```

---

## Additional things

### Lambda
- Form : []() *spec* {};
    - [] : captures;
    - () : params;
    - *spec* :
        - mutable
        - constexpr
    - {} : do something;

- []:
    - [&] : capture used variable by reference.
    - [=] : capture used variable by copy.
    - [x] : pass a specific variable(x), can be &x to pass by reference.
    - [this] : capturing the pointer to the current object (subject to variable changes)
    - [*this] : capturing a snapshot (copy) of the current state of the current object. 