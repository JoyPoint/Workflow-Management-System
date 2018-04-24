//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_RESEARCH_SCHOLAR_H
#define WMS_RESEARCH_SCHOLAR_H

#include "Student.h"

class Research_scholar : public Student {   /* subclass of students, used by research scholars
    working under a particular faculty advior
     of the institute
    */
public:
    double faculty_id;
    //Research_scholar(string a,double b,string c,double id,Leave l,Finance f);
    Research_scholar(string a="",double b=0,string c="",double id=0,
                                   Leave l=_leave,Finance f=_finance);
    double get_faculty_id();
    void set_faculty_id(double d);
    void apply_leave(int,Leave);
    void apply_finance(double,Finance);
    ~Research_scholar();
};

#endif //WMS_RESEARCH_SCHOLAR_H
