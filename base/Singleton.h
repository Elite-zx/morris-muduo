#ifndef MORRIS_BASE_SINGLETON_H
#define MORRIS_BASE_SINGLETON_H

template <typename T>
class Singleton {
 public:
  static T& get_instance() {
    /* local static */
    static T instance;
    return instance;
  }

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

 private:
  Singleton();
  ~Singleton();
};

#endif
