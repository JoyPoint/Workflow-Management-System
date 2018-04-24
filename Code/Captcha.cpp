//
// Created by DELL on 04/15/2018.
//

#include "Captcha.h"

Captcha::Captcha()
{
    captcha="";
    input="";
}

void Captcha::generate_captcha()
{
    srand(time(NULL));
    while(captcha.length()<8)
    {
        int i=rand();
        if((i>=65&&i<=90)||(i>=97&&i<=122)||(i>=48&&i<=57))
        {
            captcha+=(char)(i);
        }
    }
    cout<<"CAPTCHA : "<<captcha<<endl;
}

void Captcha::accept_input()
{
    cout<<"Please enter the captcha shown above to complete the verification: \n";
    cin>>input;
}

bool Captcha::match_captcha() const
{
    return (strcmp(captcha.c_str(),input.c_str())==0)?1:0 ;
}