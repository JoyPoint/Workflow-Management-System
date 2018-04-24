//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_STUDENT_H
#define WMS_STUDENT_H

#include "User.h"

using namespace std;

class Student : public User {   /* subclass of user class ,to be used by all
    students applying leave and financial
    applications
    */
public:
    Finance finance_obj;

public:
    Student(string a,double b,string c,Leave l,Finance f);
    void apply_finance(double,Finance);
    Finance get_finance_obj();
    void set_finance_obj(Finance f);
    string finance_status();
    ~Student();
    void setincome(double inc);
};

#endif //WMS_STUDENT_H
