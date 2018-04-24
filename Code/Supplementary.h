//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_SUPPLEMENTARY_H
#define WMS_SUPPLEMENTARY_H

#include "User.h"
#include "Captcha.h"

string register_authenticate();
bool login_authenticate(User &obj);
string password_confirm();

#endif //WMS_SUPPLEMENTARY_H
