#pragma once

#include <memory>
#include <vector>

template <typename T> class SubclassRegistry {
public:
  explicit SubclassRegistry(const std::shared_ptr<T> val) { add_object(val); }

  static std::vector<std::shared_ptr<T>> &get_objects() {
    static std::vector<std::shared_ptr<T>> theSet;
    return theSet;
  }
private:
  static void add_object(const std::shared_ptr<T> val) { get_objects().push_back(val); }
};

template <typename B, typename T> class SubclassRegistrar : public B {
private:
  static SubclassRegistry<B> m;

protected:
  SubclassRegistrar() { (void)m; }
};

template <typename B, typename T>
SubclassRegistry<B> SubclassRegistrar<B, T>::m =
    SubclassRegistry<B>(std::shared_ptr<B>(new T()));