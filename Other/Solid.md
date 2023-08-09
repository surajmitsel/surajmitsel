## Solid Principle ##

- Single Responsibility Principle
- Open-Closed Principle
- Liskov Substitution Principle
- Interface Segregation Principle
- Dependency Inversion Principle


### Single Responsibility Principle ### 
- a class should do one thing and therefore it should have only a single reason to change.

### Open-Closed Principle ###
- classes should be open for extension and closed to modification. Modification means changing the code of an existing class, and extension means adding new functionality.

### Liskov Substitution Principle ###
- The Liskov Substitution Principle states that subclasses should be substitutable for their base classes.
- This means that, given that class B is a subclass of class A, we should be able to pass an object of class B to any method that expects an object of class A and the method should not give any weird output in that case.

### Interface Segregation Principle ###
- Segregation means keeping things separated, and the Interface Segregation Principle is about separating the interfaces.
- The principle states that many client-specific interfaces are better than one general-purpose interface. Clients should not be forced to implement a function they do no need.

### Dependency Inversion Principle ###
- The Dependency Inversion principle states that our classes should depend upon interfaces or abstract classes instead of concrete classes and functions.
