#include "student.h"
#include "course.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// ostream &operator<<(ostream &out, const Student &student) { return out; }

// Student::Student(int id, const string &first, const string &last)
//     : studentID(id), firstName(first), lastName(last) {}

Student::Student(int identification, string first, string last) {
  this->studentID = identification;
  this->firstName = first;
  this->lastName = last;
}

int Student::getStudentID() const { return studentID; }

const string &Student::getFirstName() const { return firstName; }

const string &Student::getLastName() const { return lastName; }

bool Student::addCourse(Course *course) {
  if (isInCourse(course)) {
    return false;
  }
  enrolledCourses.push_back(course);
  return true;
}

bool Student::dropCourse(Course *course) {
  auto it1 = std::find(enrolledCourses.begin(), enrolledCourses.end(), course);
  if (it1 != enrolledCourses.end()) {
    enrolledCourses.erase(it1);
    return true;
  }
  return false;
}

int Student::getID() const {
  int id1 = this->studentID;
  return id1;
}

string Student::getFullName() const {
  string name = this->firstName + " " + this->lastName;
  return name;
}

bool Student::isInCourse(Course *course) const {
  return find(enrolledCourses.begin(), enrolledCourses.end(), course) !=
         enrolledCourses.end();
}

Student::~Student() { delete this; }
