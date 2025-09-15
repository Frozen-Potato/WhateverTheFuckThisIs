#ifndef STUDENT_H
#define STUDENT_H

#include "Member.h"

class Student: public Member {
    public:
        using Member::Member;
        int getBorrowLimit() override;
};

#endif