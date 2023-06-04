#include "university.h"
#include "student.h"

#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

#include <algorithm>

University::University(const std::string name) : uniName(name) {}

University::~University() {
  for (Student *student : uniStudents) {
    delete student;
  }
  for (Course *course : uniCourses) {
    delete course;
  }
}

bool University::readStudentList(const std::string &filename) {
  std::ifstream file(filename);
  if (!file) {
    return false;
  }
  int id1 = 0;
  std::string firstName;
  std::string lastName;
  while (file >> id1 >> firstName >> lastName) {
    uniStudents.push_back(new Student(id1, firstName, lastName));
  }

  file.close();
  return true;
}

bool University::readCourseList(const std::string &filename) {
  std::ifstream file(filename);
  if (!file) {
    return false;
  }

  std::string courseNumber;
  std::string title;

  while (file >> courseNumber) {
    std::getline(file, title);
    uniCourses.push_back(new Course(courseNumber, title));
  }

  file.close();
  return true;
}

bool University::readEnrollmentInfo(const std::string &filename) const {
  std::ifstream file(filename);
  if (!file) {
    return false;
  }
  int studentID = 0;
  std::string courseNumber;

  while (file >> studentID >> courseNumber) {
    Student *student = findStudent(studentID);
    Course *course = findCourse(courseNumber);
    if (student != nullptr && course != nullptr) {
      course->addStudent(student);
    }
  }

  file.close();
  return true;
}

bool University::addCourse(int studentID,
                           const std::string &courseNumber) const {
  Student *student = findStudent(studentID);
  Course *course = findCourse(courseNumber);

  if (student != nullptr && course != nullptr) {
    bool temp = course->addStudent(student);
    return temp;
  }

  return false;
}

bool University::dropCourse(int studentID,
                            const std::string &courseNumber) const {
  Student *student = findStudent(studentID);
  Course *course = findCourse(courseNumber);

  if (student != nullptr && course != nullptr) {
    return course->removeStudent(student);
  }
  return false;
}

bool University::isInCourse(int studentID,
                            const std::string &courseNumber) const {
  Student *student = findStudent(studentID);
  Course *course = findCourse(courseNumber);

  if (student != nullptr && course != nullptr) {
    return course->isEnrolled(student);
  }
  return false;
}

string University::getEnrolledCourses(int studentID) const {
  Student *student = findStudent(studentID);
  if (student == nullptr) {
    return "";
  }
  string enrolledCourses;
  for (const Course *course : uniCourses) {
    if (course->isEnrolled(student)) {
      if (!enrolledCourses.empty()) {
        enrolledCourses += ", ";
        enrolledCourses += course->getCourseNumber();
      } else {
        enrolledCourses += "[";
        enrolledCourses += course->getCourseNumber();
      }
    }
  }
  enrolledCourses += "]";
  return enrolledCourses;
}

std::string
University::getClassListByLastName(const std::string &courseNumber) const {
  Course *course = findCourse(courseNumber);
  if (course == nullptr) {
    return "";
  }
  std::vector<Student *> enrolledStudents = course->getEnrolledStudents();
  std::sort(enrolledStudents.begin(), enrolledStudents.end(), cmpLastName);

  std::string classList = "[";
  for (int i = 0; i < enrolledStudents.size(); i++) {
    if (i != enrolledStudents.size() - 1) {
      classList += enrolledStudents[i]->getLastName() + ", " +
                   enrolledStudents[i]->getFirstName() + " (" +
                   to_string(enrolledStudents[i]->getStudentID()) + "), ";
    } else {
      classList += enrolledStudents[i]->getLastName() + ", " +
                   enrolledStudents[i]->getFirstName() + " (" +
                   to_string(enrolledStudents[i]->getStudentID()) + ")" + "]";
    }
  }

  return classList;
}

std::string
University::getClassListByID(const std::string &courseNumber) const {
  Course *course = findCourse(courseNumber);
  if (course == nullptr) {
    return "";
  }
  std::vector<Student *> enrolledStudents = course->getEnrolledStudents();
  std::sort(enrolledStudents.begin(), enrolledStudents.end(), cmpID);

  std::string classList = "[";
  for (int i = 0; i < enrolledStudents.size(); i++) {
    if (i != enrolledStudents.size() - 1) {
      classList += enrolledStudents[i]->getLastName() + ", " +
                   enrolledStudents[i]->getFirstName() + " (" +
                   to_string(enrolledStudents[i]->getStudentID()) + "), ";
    } else {
      classList += enrolledStudents[i]->getLastName() + ", " +
                   enrolledStudents[i]->getFirstName() + " (" +
                   to_string(enrolledStudents[i]->getStudentID()) + ")" + "]";
    }
  }
  return classList;
}

std::string University::getCourseTitle(const std::string &courseNumber) const {
  Course *course = findCourse(courseNumber);
  if (course == nullptr) {
    return "";
  }
  return course->getTitle();
}

Student *University::findStudent(int studentID) const {
  for (Student *student : uniStudents) {
    if (student->getID() == studentID) {
      return student;
    }
  }
  return nullptr;
}

Course *University::findCourse(const std::string &courseNumber) const {
  for (Course *course : uniCourses) {
    if (course->getCourseNumber() == courseNumber) {
      return course;
    }
  }
  return nullptr;
}

string University::getName() const {
  string name = this->uniName;
  return name;
}

// bool cmpLastName(Student *a, Student *b) {
//   return a->getLastName() < b->getLastName();
// }

// bool cmpID(Student *a, Student *b) {
//   return a->getStudentID() < b->getStudentID();
// }