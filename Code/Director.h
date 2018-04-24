//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_DIRECTOR_H
#define WMS_DIRECTOR_H

#include "Employee.h"

using namespace std;

class Director: public Employee
{   /* subclass of employee, used by director
       of the institute.There is only 1 director
    whose id is '123'.No new director can be created
    only new name can be assigned to him.
    */

	public:
    //Director(string a,double b,string c,Leave l);
    //Director()=default;
	Director(string a="",double b=123,string c="",Leave l=_leave);
    void apply_leave(int,Leave);
    void approve_leave(Leave);
    //~Director();
};

extern Director _director;

#endif //WMS_DIRECTOR_H
