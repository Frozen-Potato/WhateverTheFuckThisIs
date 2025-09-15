#ifndef TEACHER_H
#define TEACHER_H

#include "Member.h"

class Teacher: public Member {
    public:
        using Member::Member;
        int getBorrowLimit() override;
};

#endif