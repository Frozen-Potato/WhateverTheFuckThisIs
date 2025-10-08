#ifndef STUDENT_H
#define STUDENT_H

#include "Member.h"

class Student: public Member {
    private:
        int grade;
    public:
        using Member::Member;
        int getGrade();
        void setGrade(int& gr);
};

#endif