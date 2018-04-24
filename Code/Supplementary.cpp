//
// Created by DELL on 04/15/2018.
//

#include "Supplementary.h"
#include "Utility_class.h"

string register_authenticate()
{
    string password;
    password=password_confirm();
    cout<<endl;
    cout<<"Directing for captcha verification in \n";
    for(int i=3; i>0; i--)
    {
        cout<<i<<"\n";
        sleep(1);
    }
    cout<<"0"<<endl;
    cout<<endl;
    while(1)
    {
        Captcha obj; //Captcha obj
        system("CLS");
        //cout<<endl;
        obj.generate_captcha();
        obj.accept_input();
        if(obj.match_captcha())
        {
            cout<<"Captcha verification success.\n";
            system("pause");
            break;
        }
        else
        {
            /* Captcha and input dont match */
            cout<<"Input does not match with captcha.\n";
            cout<<"Try again in 2 seconds !\n\n";
            sleep(2);
            srand(time(NULL));
            continue;
        }
    }
    return password;
}

bool login_authenticate(User &obj)
{
    int error_count=0; //3 trials are given to the user
    string correct_pwd=obj.password;
    char ch;
    while(error_count<3)
    {
        system ("CLS");   //clear screen
        cout<<"User ID : "<<obj.user_id<<endl;
        int i=0;
//        string correct="alphabet";
        cout<<"Password : ";
        string pwd;
        do
        {
            ch=getch();  //accepts a character from the user without displaying to the screen
            if(ch==13)   //carriage return a.k.a. enter key
                break;
            else if (ch==8)  //8-backspace
            {
                i-=1;
                pwd=pwd.substr(0,i);
                system ("CLS");
                cout<<"User ID : "<<obj.get_id()<<endl;
                cout<<"Password : ";
                for(int j=0; j<i; j++)
                    cout<<"*";
            }
            else
            {
                i++;         //maintains track of size of password
                pwd+=ch;
                cout<<"*";
            }
        } while (1);
        cout<<endl;

        if(!strcmp(pwd.c_str(),correct_pwd.c_str()))  //string comparison
        {
            cout<<"Authentication success \n";
            return true;
        }
        else
        {
            cout<<"Authentication failed ! \n";
            if(error_count<2)  //to display try again after 2 sec for the first two trials
            {
                cout<<"Please try again in 2 seconds ! \n\n";
                sleep(2);
            }
            else
            {
                cout<<"\n";
            }
            error_count++;
        }
    }

    cout<<"You have typed the incorrect password 3 times !\n";
    while(1)
    {
        cout<<"Forgot password ? (Y/N) \n";
        char choice;
        cin>>choice;
        if (choice=='Y'||choice=='y')
        {
            //string new_pwd=register_authenticate();
            //obj.password=new_pwd;
            cout<<"Oops! Register again using a different ID!\nInconvinience caused is deeply regretted.\n";
            cout<<"Redirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            /*
			cout<<"Directing to change authentication details .... \n";
            sleep(1);
            cout<<"Verify it's you before changing the password.";
			cout<<obj.security.security_qn;
			string answer;
			int choice;
			do
			{
				cout<<"Answer: (Case sensitive)\n";
	            cin>>answer;
	            //if((answer.c_str()).compare((obj.security.security_ans).c_str()))
	            if(answer.compare(obj.security.security_ans))
				{
					cout<<"1: Type the answer again\n2: Go back\n";
					cin>>choice;
				}
				else
				{
					choice=3;
				}
			}while(choice==1);
			if(choice==3)
			{
			    string new_password=password_confirm();
            	obj.security.password=new_password;
            }
            return true;
            */
            _utility.start();
        }
        else if (choice=='N'||choice=='n')
        {
            cout<<"Do you want to quit? Press Esc to quit else press any key to continue \n";
            char esc;
            esc=getch();
            if(esc==27) // escape key pressed
            {
                cout<<"Thank you\n";
                return false;
            }
            else
            {
                continue;
            }
        }
        else
        {
            cout<<"Invalid Choice ! Please try again ! \n\n";
            continue;
        }
    }
}
string password_confirm()
{
    bool match=false;
    string password;
    while(!match)
    {
        system("CLS");
        //cout<<endl;
        cout<<"Enter a password!\n";
        string pp1;
        do
        {
            static int i=0;
            char ch=getch();  //accepts a character from the user without displaying to the screen
            if(ch==13)   //carriage return a.k.a. enter key
                break;
            else if (ch==8)  //8-backspace
            {
                i-=1;
                pp1=pp1.substr(0,i);
                system ("CLS");
                cout<<"Enter a password!\n";
                for(int j=0; j<i; j++)
                    cout<<"*";
            }
            else
            {
                i++;         //maintains track of size of password
                pp1+=ch;
                cout<<"*";
            }
        } while (1);
        cout<<endl;
        string pp2="";
        cout<<"Confirm password! \n";
        do
        {
            static int i=0;
            char ch=getch();  //accepts a character from the user without displaying to the screen
            if(ch==13)   //carriage return a.k.a. enter key
                break;
            else if (ch==8)  //8-backspace
            {
                i-=1;
                pp2=pp2.substr(0,i);
                system ("CLS");
                cout<<"Enter a password!\n";
                for(int k=0; k<pp1.length(); k++)
                {
                    cout<<"*";
                }
                cout<<"\n";
                cout<<"Confirm password! \n";
                for(int j=0; j<i; j++)
                    cout<<"*";
            }
            else
            {
                i++;         //maintains track of size of password
                pp2+=ch;
                cout<<"*";
            }
        } while (1);
        cout<<endl;
        if(!strcmp(pp1.c_str(),pp2.c_str()))
        {
            password=pp1;
            return password;
        }
        else
        {
            cout<<"No match! Try again! \n";
            system("Pause");
            continue;
        }
    }
}
