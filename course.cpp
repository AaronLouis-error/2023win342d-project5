#include "course.h"
#include "student.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <cassert>
#include <sstream>

using namespace std;

// ostream &operator<<(ostream &out, const Course &course) { return out; }

Course::Course(const string &num, const string &titlename) {
  this->courseNumber = num;
  string tempTitle = titlename;
  boost::trim_left(tempTitle);
  this->courseTitle = tempTitle;
}

const string &Course::getCourseNumber() const { return courseNumber; }

const string &Course::getCourseTitle() const { return courseTitle; }

bool Course::addStudent(Student *student) {
  if (isEnrolled(student)) {
    return false;
  }
  enrolledStudents.push_back(student);
  student->addCourse(this);
  return true;
}

bool Course::removeStudent(Student *student) {
  auto it1 =
      std::find(enrolledStudents.begin(), enrolledStudents.end(), student);
  if (it1 != enrolledStudents.end()) {
    enrolledStudents.erase(it1);
    student->dropCourse(this);
    return true;
  }
  return false;
}

std::vector<Student *> Course::getEnrolledStudents() const {
  return enrolledStudents;
}

bool Course::isEnrolled(const Student *student) const {
  return std::find(enrolledStudents.begin(), enrolledStudents.end(), student) !=
         enrolledStudents.end();
}

bool cmpLastName(Student *first, Student *second) {
  return first->getLastName() < second->getLastName();
}

bool cmpID(Student *first, Student *second) {
  return first->getStudentID() < second->getStudentID();
}

vector<Student *> Course::getClassListByLastName() const {
  vector<Student *> tempVec = enrolledStudents;
  sort(tempVec.begin(), tempVec.end(), cmpLastName);
  return tempVec;
}

string Course::getTitle() const {
  string title = this->courseTitle;
  return title;
}

vector<Student *> Course::getClassListByID() const {
  vector<Student *> tempVec = enrolledStudents;
  sort(tempVec.begin(), tempVec.end(), cmpID);
  return tempVec;
}
