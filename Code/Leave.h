//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_LEAVE_H
#define WMS_LEAVE_H

#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<conio.h>

using namespace std;

#define maxleaveofabsence 50

using namespace std;

class Leave
{   /* Details of leave applications
    to be aplied by user
    */
public:
    string status;
    int number;
    string designation;
    double id;
    int applied;

public:
    Leave(string a="Not_applied",int b=50,string c="",double d=0,int ap=0);
    void set(string a,int b,string c,double d,int ap);
    string get_status();
    int check_number();
    void deduct(int a);
    string get_designation();
    void set_number(int a);
    void set_status(string p);
    void set_designation(string p);
    double get_id();
    void set_id(double d);
    int get_applied();
    void set_applied(int p);
    bool operator ==(Leave obj);
    bool operator !=(Leave obj);
    void operator =(Leave obj);
};

/*friend*/ istream& operator >>(istream& obj,Leave& l);

extern Leave _leave;

#endif //WMS_LEAVE_H
