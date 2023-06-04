#include "enrollmentsystem.h"
#include "university.h"

#include <cassert>
#include <map>
#include <vector>

using namespace std;

EnrollmentSystem::EnrollmentSystem() : currentUniversity(nullptr) {}

bool EnrollmentSystem::addUniversity(const std::string &name) {
  if (findUniversity(name) != nullptr) {
    return false;
  }
  universities.push_back(new University(name));
  return true;
}

bool EnrollmentSystem::setCurrentUniversity(const std::string &name) {
  University *university = findUniversity(name);
  if (university != nullptr) {
    currentUniversity = university;
    return true;
  }
  return false;
}

std::string EnrollmentSystem::getUniversityName() const {
  if (currentUniversity != nullptr) {
    return currentUniversity->getName();
  }
  return "";
}

bool EnrollmentSystem::readStudentList(const std::string &filename) {
  if (currentUniversity != nullptr) {
    return currentUniversity->readStudentList(filename);
  }
  return false;
}

bool EnrollmentSystem::readCourseList(const std::string &filename) {
  if (currentUniversity != nullptr) {
    return currentUniversity->readCourseList(filename);
  }
  return false;
}

bool EnrollmentSystem::readEnrollmentInfo(const std::string &filename) {
  if (currentUniversity != nullptr) {
    return currentUniversity->readEnrollmentInfo(filename);
  }
  return false;
}

bool EnrollmentSystem::dropCourse(int studentID,
                                  const std::string &courseNumber) {
  if (currentUniversity != nullptr) {
    return currentUniversity->dropCourse(studentID, courseNumber);
  }
  return false;
}

bool EnrollmentSystem::addCourse(int studentID,
                                 const std::string &courseNumber) {
  if (currentUniversity != nullptr) {
    return currentUniversity->addCourse(studentID, courseNumber);
  }
  return false;
}

bool EnrollmentSystem::isInCourse(int studentID,
                                  const std::string &courseNumber) const {
  if (currentUniversity != nullptr) {
    return currentUniversity->isInCourse(studentID, courseNumber);
  }
  return false;
}

std::string EnrollmentSystem::getEnrolledCourses(int studentID) const {
  if (currentUniversity != nullptr) {
    return currentUniversity->getEnrolledCourses(studentID);
  }
  return "";
}

std::string EnrollmentSystem::getCourseTitle(const std::string &courseNumber) {
  if (currentUniversity != nullptr) {
    return currentUniversity->getCourseTitle(courseNumber);
  }
  return "";
}

std::string EnrollmentSystem::getClassListByLastName(
    const std::string &courseNumber) const {
  if (currentUniversity != nullptr) {
    return currentUniversity->getClassListByLastName(courseNumber);
  }
  return "";
}

std::string
EnrollmentSystem::getClassListByID(const std::string &courseNumber) const {
  if (currentUniversity != nullptr) {
    return currentUniversity->getClassListByID(courseNumber);
  }
  return "";
}

University *EnrollmentSystem::findUniversity(const std::string &name) const {
  for (University *university : universities) {
    if (university->getName() == name) {
      return university;
    }
  }
  return nullptr;
}
