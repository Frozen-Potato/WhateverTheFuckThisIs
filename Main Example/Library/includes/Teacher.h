#ifndef TEACHER_H
#define TEACHER_H

#include "Member.h"

class Teacher: public Member {
    private:
        std::string department;
    public:
        using Member::Member;
        std::string getDepartment();
        void setDepartment(std::string& dep);
};

#endif