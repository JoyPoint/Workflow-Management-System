//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_UNDERGRADS_H
#define WMS_UNDERGRADS_H

#include "Student.h"

using namespace std;

class Undergrads : public Student {   /* subclass of students, used by undergraduates
    section of the institute
    */
public:
    //Undergrads(string a,double b,string c,Leave l,Finance f);
    Undergrads(string a="",double b=0,string c="",Leave l=_leave,Finance f=_finance);
    void apply_leave(int,Leave);
    void apply_finance(double,Finance);
    ~Undergrads();
};

#endif //WMS_UNDERGRADS_H
