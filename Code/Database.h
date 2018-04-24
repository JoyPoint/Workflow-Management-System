//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_DATABASE_H
#define WMS_DATABASE_H
#include<bits/stdc++.h>
#include "Director.h"

//#include "Undergrads.h"
//#include "Research_scholar.h"
//#include "Faculty.h"
//#include "Hod.h"
//#include "Director.h"
//#include "Administrator.h"
//#include "Supplementary.h"
class Undergrads;
class Research_scholar;
class Faculty;
class Hod;
class Director;
class Administrator;
class Supplementary;
using namespace std;

class Database
{   /* It can interact freely with users
    and is responsible for maintaining
    the data of all users intact.
    */
public:
    map<double,Undergrads> ug_data;
    map<double,Research_scholar> res_data;
    map<double,Hod> hod_data;
    map<string,Hod> hod_department;
    map<double,Faculty> fac_data;
    Director obj;

public:
    Database();
    void addug(Undergrads &p);
    void addres(Research_scholar &p);
    void addfac(Faculty &p);
    void addhod(Hod &p);
    void adddir(Director &p);
    Undergrads& get_ug(double id);
    Research_scholar& get_res(double id);
    Faculty& get_fac(double id);
    Hod& get_hod(double id);
    Hod& get_hod_dep(string dep);
    Director& get_dir(double id);
    Leave leave_obj(double id,string desig);
    Finance finance_obj(double id,string desig);
    bool findug(double id);
    bool findres(double id);
    bool findfac(double id);
    bool findhod(double id);
    bool findhoddep(string dep);
};

extern Database _database;

#endif //WMS_DATABASE_H
