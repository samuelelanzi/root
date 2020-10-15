#include "Person.hpp"
#include "Student.hpp"
#include <iostream>

int main() {
  Person *test[2];
  test[0] = new Person("tizio");
  test[1] = new Student("caio", 223344);
  for (int i = 0; i < 2; i++) {
    test[i].PrintData();
  }
}
