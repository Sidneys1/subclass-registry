#include <iostream>
#include <memory>

#include "subclass_registry.hpp"

/* Base Class */
class Base {
public:
  virtual void impl_me() = 0;
  virtual ~Base() = default;
};

/* Subclasses */
class Subclass1 : public SubclassRegistrar<Base, Subclass1> {
public:
  Subclass1() { /* CANNOT be `= default` */ }

  void impl_me() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Subclass2 : public SubclassRegistrar<Base, Subclass2> {
public:
  Subclass2() { /* CANNOT be `= default` */ }

  void impl_me() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

/* Entrypoint */
int main(int /*unused*/, char *[] /*unused*/) {
  for (std::shared_ptr<Base> &sub : SubclassRegistry<Base>::get_objects())
    sub->impl_me();
  return 0;
}