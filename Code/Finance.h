//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_FINANCE_H
#define WMS_FINANCE_H

#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<conio.h>

using namespace std;

#define maxfamilyincome 500000


using namespace std;

class Finance
{   /* Details of financial applications
    to be aplied by student
    */
public:
    string status;
    double amount;
    double family_income;
    string designation;
    double id;
    double applied;

public:
    Finance(string st="Not_applied",double am=0,double inc=0,string des="",double i=0,double ap=0);
    void set(string st,double am,double inc,string des,double i,double ap);
    string get_status();
    double check_amount();
    double check_income();
    string get_designation();
    void set_income(double inc);
    void set_amount(double amo);
    void set_status(string st);
    void set_designation(string des);
    double get_id();
    void set_id(double i);
    double get_applied();
    void set_applied(double p);
    void add(double p);
    bool operator ==(Finance obj);
    void operator =(Finance obj);

};

/*friend*/ istream& operator >>(istream& obj,Finance& l);

extern Finance _finance;

#endif //WMS_FINANCE_H
