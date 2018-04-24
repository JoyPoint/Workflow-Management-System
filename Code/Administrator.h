//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_ADMINISTRATOR_H
#define WMS_ADMINISTRATOR_H

#include "Employee.h"

using namespace std;

class Administrator: public Employee
{   /* it is the final approving authority
    concerned with approving leave or
    financial applications of its users.
    There is 1 fixed administrator with
    id '1234'.No new administrator can be created.
    */
public:
    //Administrator(string a,double b,string c,Leave l);
    Administrator(string a="",double b=1234,string c="",Leave l=_leave);
    void approve_leave(Leave);
    void approve_finance(Finance);
    ~Administrator();
};

extern Administrator _administrator;

#endif //WMS_ADMINISTRATOR_H
