//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_UTILITY_CLASS_H
#define WMS_UTILITY_CLASS_H

using namespace std;

#define maxfamilyincome 500000
#define maxleaveofabsence 50

#include "Undergrads.h"
#include "Research_scholar.h"
#include "Faculty.h"
#include "Hod.h"
#include "Director.h"
#include "Administrator.h"
#include "Supplementary.h"
#include "Database.h"
#include "File.h"

class Utility_class
{   /* It is the driving class which
    provides us with all the utilities.
    It is the initially called class
    which drivesthe software.
    */
public:
    void Register();
    void login();
    void start();
    void visitug(Undergrads&  obj);
    void visitres(Research_scholar&  obj);
    void visitfac(Faculty& obj);
    void visithod(Hod& obj);
    void visitdir(Director& obj);
    void visitadm();
};

extern Utility_class _utility;

#endif //WMS_UTILITY_CLASS_H
