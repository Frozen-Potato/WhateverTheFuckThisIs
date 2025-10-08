# Theory 

- **What a class is**  
  User-defined type bundling data + behavior. Prefer hiding data behind a clear public API.

- **Class vs struct**  
  `class` defaults to **private** members;  
  `struct` defaults to **public** members.  
  Control access with `public:`, `protected:`, `private:`.

- **Access control**  
  - `public`: everywhere  
  - `private`: inside the class + friends  
  - `protected`: class + derived (inherited) classes  
  Keep state private unless there’s a strong reason.

- **Construction & cleanup**  
  - Use constructor *initializer lists* to set members directly.  
  - **Constructor types**:  
    - *Default constructor* : no arguments, makes a "blank" object.  
    - *Parameterized constructor* : takes arguments to set initial values.  
    - *Copy constructor* : makes a new object from another (`T(const T&)`).  
    - *Move constructor* : transfers ownership/resources (`T(T&&)`)
    - *Delegating constructor* : one constructor calls another (`: Class(args)`).  
  - **Big Five** (special members that control copying/moving/cleanup):  
    - Destructor `~T()` : releases resources.  
    - Copy constructor `T(const T&)`.  
    - Copy assignment `T& operator=(const T&)`.  
    - Move constructor `T(T&&) noexcept`.  
    - Move assignment `T& operator=(T&&) noexcept`.  
  - **explicit**:  
    - Use on single-argument constructors to prevent unwanted implicit conversions.  
  - For polymorphic bases, mark destructor `virtual`.

- **Operator overloading**  
  Implement natural semantics (`+`, `==`, `<<`).  
  Prefer non-member (or `friend`) for symmetry.  

- **Static members**  
  `static` data is shared across instances.  
  `static` functions have no `this`.  
  Define out-of-class (or `inline` since C++17, define in header).

- **Inheritance & polymorphism**  
  - Inheritance : class can reuse and extend another (child **is-a** parent).  
  - Polymorphism : same function call behaves differently depending on the object’s actual type.  
  Use `override` for clarity; use `final` to stop further overrides.

- **Friends (sparingly)**  
  `friend` grants privileged access.  
  Use only when it clarifies design (e.g., symmetric operators).

- **Templates / generics**  
  `template<typename T>` enables one definition for many types  
  (basis of STL containers like `vector<T>` or `map<K,V>`).

