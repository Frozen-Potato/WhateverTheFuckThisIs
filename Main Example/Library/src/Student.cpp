#include "Student.h"

int Student::getGrade(){
    return grade;
}

void Student::setGrade(int& gr){
    grade = std::move(gr);
}
