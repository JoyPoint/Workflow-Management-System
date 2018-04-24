//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_CAPTCHA_H
#define WMS_CAPTCHA_H

#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include<time.h>

using namespace std;

class Captcha //Completely Automated Public Turing test to tell Computers and Humans Apart
{
private:
    string captcha;
    string input;
public:
    Captcha();
    void generate_captcha();
    void accept_input();
    bool match_captcha() const;
};

#endif //WMS_CAPTCHA_H
