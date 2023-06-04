#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Course;

class Student {
public:
  friend class Course;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Student &student);

  // Student(int id, const string &first, const string &last);
  Student(int identification, string first, string last);

  bool dropCourse(Course *course);
  bool addCourse(Course *course);
  bool isInCourse(Course *course) const;
  virtual ~Student();
  int getStudentID() const;
  const string &getFirstName() const;
  const string &getLastName() const;
  string getFullName() const;
  int getID() const;

private:
  int studentID;
  string firstName;
  string lastName;
  vector<Course *> enrolledCourses;
};

#endif