#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "course.h"
#include "student.h"
#include <map>
#include <string>

using namespace std;

class University {
protected:
  friend class EnrollmentSystem;

public:
  explicit University(const std::string name);

  bool readStudentList(const std::string &filename);

  bool readCourseList(const std::string &filename);

  bool readEnrollmentInfo(const std::string &filename) const;

  bool addCourse(int studentID, const std::string &courseNumber) const;

  bool dropCourse(int studentID, const std::string &courseNumber) const;

  bool isInCourse(int studentID, const std::string &courseNumber) const;

  string getEnrolledCourses(int studentID) const;

  string getClassListByLastName(const std::string &courseNumber) const;

  string getClassListByID(const std::string &courseNumber) const;

  string getCourseTitle(const std::string &courseNumber) const;

  Student *findStudent(int studentID) const;

  string getName() const;

  Course *findCourse(const std::string &courseNumber) const;

  virtual ~University();

private:
  vector<Student *> uniStudents;

  vector<Course *> uniCourses;

  string uniName;
};

#endif