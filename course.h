#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Student;

class Course {

public:
  friend class Student;

  friend class University;

  friend class EnrollmentSystem;

  friend ostream &operator<<(ostream &out, const Course &course);

  Course(const string &number, const string &title);

  const string &getCourseNumber() const;

  const string &getCourseTitle() const;

  bool addStudent(Student *student);

  bool removeStudent(Student *student);

  bool isEnrolled(const Student *student) const;

  vector<Student *> getEnrolledStudents() const;

  vector<Student *> getClassListByLastName() const;

  vector<Student *> getClassListByID() const;

  // std::vector<Student *> getEnrolledStudents() const;

  string getTitle() const;

private:
  string courseNumber;
  string courseTitle;
  vector<Student *> enrolledStudents;
};

bool cmpLastName(Student *first, Student *second);

bool cmpID(Student *first, Student *second);

#endif