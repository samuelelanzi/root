#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.h"

class Student : public Person {
public:
  Student(const char *name, int code);
  void PrintData() const;

private:
  int code_;
};

#endif