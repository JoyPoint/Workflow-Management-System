//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_FACULTY_H
#define WMS_FACULTY_H

#include "Employee.h"

using namespace std;

class Faculty: public Employee
{   /* subclass of employees, used by faculty
    section of the institute
    */

private:
    string department;

public:
    //Faculty(string a,double b,string c,string d,Leave l);
    Faculty(string a="",double b=0,string c="",string d="",Leave l=_leave);
    void apply_leave(int,Leave);
    void approve_leave(Leave);
    void approve_finance(Finance);
    string get_department();
    void set_department(string p);
    ~Faculty();
};

#endif //WMS_FACULTY_H
