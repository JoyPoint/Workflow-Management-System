//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_USER_H
#define WMS_USER_H

#include<bits/stdc++.h>
#include "Leave.h"
#include "Finance.h"
//#include "Database.h"

using namespace std;

class User
{   /* user class: super class for any applicant
    accessing the software
     */
public:
    string name;
    string password;
    double user_id;
    string designation;
    Leave leave_obj;

public:
    User(string a="",double b=0,string c="",Leave l=_leave);
    string get_designation();
    string leave_status();
    string get_name();
    double get_id();
    Leave get_leave_obj();
    void apply_leave(int,Leave);
    void set_name(string n);
    void set_id(double d);
    void set_leave_obj(Leave obj);
    void add_leave(Leave);
    void add_finance(Finance);
};

#endif //WMS_USER_H
