#ifndef PERSON_HPP
#define PERSON_HPP

class Person {
public:
  Person(const char *name);
  void PrintName() const;
  virtual void PrintData() const;

private:
  const char *name_;
};

#endif