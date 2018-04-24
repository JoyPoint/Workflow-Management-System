//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_EMPLOYEE_H
#define WMS_EMPLOYEE_H

#include<bits/stdc++.h>
#include "User.h"

class Employee: public User
{   /* a user subclass used by employyes of the
    institute eligible to approve applications
    of students and are themselves eligible to
    apply for leaves
    */
public:
    list<Leave> leave_pending;
    list<Finance> finance_pending;

public:
    //Employee(string a,double b,string c,Leave l);
    Employee(string a="",double b=0,string c="",Leave l=_leave);
//    Employee()=default;
    void approve_leave(Leave);
    void approve_finance(Finance);
    void add_leave(Leave);
    void add_finance(Finance);
    void remove_leave(Leave);
    void remove_finance(Finance);
    void show_leave();
    void show_finance();
    bool check_empty_leave();
    bool check_empty_finance();
    bool find_leave(Leave obj);
    bool find_finance(Finance obj);
    ~Employee();
};

#endif //WMS_EMPLOYEE_H
