# Subclass Registry

## Usage

Given a class heirarchy like:

```cpp
class Base {
};

class Subclass1 : public Base {
};

class Subclass2 : public Base {
};
```

Create a registry by changing it to:

```cpp
#include "subclass_registry.hpp"

class Base {
public:
    virtual ~Base() = default;
};

class Subclass1 : public SubclassRegistrar<Base, Subclass1> {
public:
    Subclass1() { /* CANNOT be `= default` */ }
};

class Subclass2 : public SubclassRegistrar<Base, Subclass2> {
public:
    Subclass2() { /* CANNOT be `= default` */ }
};
```

And access instances of them statically like so:
```cpp
int main(int, char**) {
    for (std::shared_ptr<Base> &subclass : SubclassRegistry<Base>::get_objects()) {
        // Do something with an intance of
        // Subclass1 and Subclass2
    }
}
```