//
// Created by DELL on 04/15/2018.
//

#include "Utility_class.h"

Utility_class _utility;

void Utility_class:: start()
{
    //_director.get_leave_obj().set_status("Director");
    _database.adddir(_director);
    int count=0;
    b:
    system("CLS");
    //cout<<endl;
    if(!count++)
        cout<<"Welcome! What would you like to do?\n";
    else
        cout<<"Welcome back! What would you like to do?\n";
    cout<<"1.Register"<<endl<<"2.Login"<<endl<<"3.exit"<<endl;
    int choice;
    cin>>choice;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }

    switch(choice)
    {   //startup menu for user interface
        case 1:
            cout<<"\nDirecting for Registration in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            system("CLS");
            //cout<<endl;
            Utility_class::Register();
            goto b;
            break;
        case 2:
            cout<<"\nDirecting for Login in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            system("CLS");
            //cout<<endl;
            login();
            goto b;
            break;
        case 3:
            write();
            write_adm();
            write_res();
            write_fac();
            write_res();
            write_dir();
            write_hod();
            exit(0);
            break;
        default:
            cout<<"Wrong choice\n\n";
            cout<<"Redirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            system("CLS");
            //cout<<endl;
            _utility.start();
            break;
    }
}

void Utility_class::Register()
{
    string name,desig;
    int opt;
    double id;
    c:
    cout<<"Register as\n"<<"1.Undergrads\n"<<"2.Research scholar\n"<<"3.Faculty\n"<<"4.Hod\n"<<"5.Director\n"<<"6.Exit\n";
    cout<<"Enter the choice of your designation"<<endl;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    if(opt>6||opt<1)
    {
        cout<<"Wrong Choice!\n\n";
        cout<<"Try again in \n";
        for(int i=3; i>0; i--)
        {
            cout<<i<<"\n";
            sleep(1);
        }
        system("CLS");
        //cout<<endl;
        goto c;
    }
    else if(opt==6)
    {
        cout<<"\nRedirecting in \n";
        for(int i=3; i>0; i--)
        {
            cout<<i<<"\n";
            sleep(1);
        }
        return;
    }
    cout<<"Enter name\n";
    cin>>name;
    cout<<"Enter userid\n";
    cin>>id;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    string password;
    password=register_authenticate();
    cout<<"\n";
    /* registers the user based on
    designation and also makes sure
    that the id used for registration
    is non existing
    */
    if(opt==1)
    {
        if(!_database.findug(id))
        {
            cout<<"Id already exists\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        desig= "Undergrads";
        double income;
        cout<<"Enter family income\n";
        cin>>income;
        Undergrads obj(name,id,desig);
        obj.password=password;
        obj.setincome(income);
        _database.addug(obj);
    }
    else if(opt==2)
    {
        if(!_database.findres(id))
        {
            cout<<"Id already exists\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        desig="Research_scholar";
        double income, facid;
        cout<<"enter family income\n";
        cin>>income;
        cout<<"enter faculty id under which you are working\n";
        cin>>facid;
        if(_database.findfac(facid))
        {   /* makes sure that the faculty under which
               he works exists in the institute
            */
            cout<<"Concerned faculty not found..retry\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        Research_scholar obj(name,id,desig,facid);
        obj.password=password;
        obj.setincome(income);
        _database.addres(obj);
    }
    else if(opt==3)
    {
        if(!_database.findfac(id))
        {
            cout<<"Id already exists\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        desig="Faculty";
        string department;
        cout<<"Enter your department\n";
        cin>>department;
        if(_database.findhoddep(department))
        {   /* makes sure that the hod under which
               he works exists in the institute
            */
            cout<<"Concerned Hod not found...retry\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        Faculty obj(name,id,desig,department);
        obj.password=password;
        _database.addfac(obj);
    }
    else if(opt==4)
    {
        if(!_database.findhod(id))
        {
            cout<<"Id already exists\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        desig="Hod";
        string department;
        cout<<"Enter your department\n";
        cin>>department;
        Hod obj(name,id,desig,department);
        obj.password=password;
        _database.addhod(obj);
    }
    else if(opt==5)
    {
        desig="Director";
        if(id!=_director.get_id())
        {
            cout<<"Wrong id..director exists\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            return;
        }
        Director obj(name,id,desig);
        obj.password=password;
        _database.adddir(obj);
    }
    cout<<"Successfully registered!\n\nRedirecting in \n";
    for(int i=3; i>0; i--)
    {
        cout<<i<<"\n";
        sleep(1);
    }
}

void Utility_class::login()
{   //interface for logging in which verifies your designation and id if they are registered
    string desig;
    double id;
    int opt;
    c:
    cout<<"Login as\n"<<"1.Undergrads\n"<<"2.Research scholar\n"<<"3.Faculty\n"<<"4.Hod\n"  //
        <<"5.Director\n"<<"6.Administrator\n"<<"7.Exit\n";
    cout<<"Enter the choice of your designation"<<endl;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    if(opt>7||opt<1)
    {
        cout<<"Wrong Choice!\n\n";
        cout<<"Try again in \n";
        for(int i=3; i>0; i--)
        {
            cout<<i<<"\n";
            sleep(1);
        }
        system("CLS");
        //cout<<endl;
        goto c;
    }
    else if(opt==7)
    {
        cout<<"\nRedirecting in \n";
        for(int i=3; i>0; i--)
        {
            cout<<i<<"\n";
            sleep(1);
        }
        return;
    }
    cout<<"Enter your id\n";
    cin>>id;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    if(opt==1)
    {
        try
        {
            Undergrads obj=_database.get_ug(id);
            if(login_authenticate(obj))
            {
                cout<<"\nLogging in in \n";
                for(int i=3; i>0; i--)
                {
                    cout<<i<<"\n";
                    sleep(1);
                }
                this->Utility_class::visitug(obj);
            }
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            cout<<"\n";
            system("Pause");
        }
    }
    else if(opt==2)
    {
        try
        {
            Research_scholar obj=_database.get_res(id);
            if(login_authenticate(obj))
            {
                cout<<"\nLogging in in \n";
                for(int i=3; i>0; i--)
                {
                    cout<<i<<"\n";
                    sleep(1);
                }
                this->Utility_class::visitres(obj);
            }
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            cout<<"\n";
            system("Pause");
        }
    }
    else if(opt==3)
    {
        try
        {
            Faculty obj=_database.get_fac(id);
            if(login_authenticate(obj))
            {
                cout<<"\nLogging in in \n";
                for(int i=3; i>0; i--)
                {
                    cout<<i<<"\n";
                    sleep(1);
                }
                this->Utility_class::visitfac(obj);
            }
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            cout<<"\n";
            system("Pause");
        }
    }
    else if(opt==4)
    {
        try
        {
            Hod obj=_database.get_hod(id);
            if(login_authenticate(obj))
            {
                cout<<"\nLogging in in \n";
                for(int i=3; i>0; i--)
                {
                    cout<<i<<"\n";
                    sleep(1);
                }
                this->Utility_class::visithod(obj);
            }
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            cout<<"\n";
            system("Pause");
        }
    }
    else if(opt==5)
    {
        try
        {
            Director obj=_database.get_dir(id);
            if(login_authenticate(obj))
            {
                cout<<"\nLogging in in \n";
                for(int i=3; i>0; i--)
                {
                    cout<<i<<"\n";
                    sleep(1);
                }
                this->Utility_class::visitdir(obj);
            }
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            cout<<"\n";
            system("Pause");
        }
    }
    else if(opt==6)
    {
        if(id==_administrator.get_id())
        {
            cout<<"\nLogging in in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            this->Utility_class::visitadm();
        }
        else
        {
            cout<<"Id Not found\n";
            cout<<"\n";
            system("Pause");
        }
    }
}


void Utility_class::visitug(Undergrads &obj)
{   //interface after logging in as undergrad
    b:
    system("CLS");
    //cout<<obj.password<<endl;
    //cout<<endl;
    cout<<"Hi "<<obj.get_name()<<" !\n";
    cout<<"1.apply for leave\n"<<"2.apply for financial assistance\n"<<"3.check leave status\n"<<"4.check finance status\n"<<"5. exit\n";
    int opt;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    switch(opt)
    {
        case 1: {
            int days;
            cout<<"Enter no. of days of leave required\n";
            cin>>days;
            obj.apply_leave(days,obj.get_leave_obj());
        }
            obj=_database.get_ug(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 2: {
            int amount;
            cout<<"Enter amount required\n";
            cin>>amount;
            obj.apply_finance(amount,obj.get_finance_obj());
        }
            obj=_database.get_ug(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 3:
            cout<<(obj.get_leave_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 4:
            cout<<(obj.get_finance_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 5:
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;

        default:
            cout<<"Wrong choice\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;
    }
}


void Utility_class::visitres(Research_scholar& obj)
{   //interface after logging in as research scholar
    b:
    system("CLS");
    //cout<<endl;
    cout<<"Hi "<<obj.get_name()<<" !\n";
    cout<<"1.apply for leave\n"<<"2.apply for financial assistance\n"<<"3.check leave status\n"<<"4.check finance status\n"<<"5. exit\n";
    int opt;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    switch(opt)
    {
        case 1: {
            int days;
            cout<<"Enter no. of days of leave required\n";
            cin>>days;
            obj.apply_leave(days,obj.get_leave_obj());
        }
            obj=_database.get_res(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 2: {
            int amount;
            cout<<"Enter amount required\n";
            cin>>amount;
            obj.apply_finance(amount,obj.get_finance_obj());
        }
            obj=_database.get_res(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 3:
            cout<<(obj.get_leave_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 4:
            cout<<(obj.get_finance_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 5:
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;

        default:
            cout<<"wrong choice\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;
    }
}


void Utility_class::visitfac(Faculty &obj)
{   //interface after logging in as faculty
    b:
    system("CLS");
    //cout<<endl;
    cout<<"Hi "<<obj.get_name()<<" !\n";
    cout<<"1.apply for leave\n"<<"2.approve pending leaves\n"<<"3.check leave status\n"<<"4.approve pending finances\n"<<"5. exit\n";
    int opt;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    switch(opt)
    {
        case 1: {
            int days;
            cout<<"Enter no. of days of leave required\n";
            cin>>days;
            obj.apply_leave(days,obj.get_leave_obj());
        }
            obj=_database.get_fac(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 2: {
            if(!obj.check_empty_leave())
            {
                obj.show_leave();
                double id;
                string desig;
                cout<<"enter id\n";
                cin>>id;
                cout<<"enter designation of leave applicant\n";
                cin>>desig;
                try
                {
                    obj.approve_leave(_database.leave_obj(id,desig));
                }
                catch(...)
                {
                    cout<<"Not found\n";
                }
            }
            else
            {
                cout<<"No applications pending for approval";
            }
        }
            obj=_database.get_fac(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 3:
            cout<<(obj.get_leave_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 4: {
            if(!obj.check_empty_finance())
            {
                obj.show_finance();
                double id;
                string desig;
                cout<<"enter id\n";
                cin>>id;
                cout<<"enter designation of leave applicant\n";
                cin>>desig;
                try
                {
                    obj.approve_finance(_database.finance_obj(id,desig));
                }
                catch(...)
                {
                    cout<<"Not found\n";
                }
            }
            else
            {
                cout<<"No applications pending for approval";
            }
        }
            obj=_database.get_fac(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 5:
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;

        default:
            cout<<"wrong choice\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;
    }
}


void Utility_class::visithod(Hod &obj)
{   //interface after logging in as Hod
    b:
    system("CLS");
    //cout<<endl;
    cout<<"Hi "<<obj.get_name()<<" !\n";
    cout<<"1.apply for leave\n"<<"2.approve leave\n"<<"3.check leave status\n"<<"4. exit\n";
    int opt;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    switch(opt)
    {
        case 1: {
            int days;
            cout<<"Enter no. of days of leave required\n";
            cin>>days;
            obj.apply_leave(days,obj.get_leave_obj());
        }
            obj=_database.get_hod(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 2: {
            if(!obj.check_empty_leave())
            {
                obj.show_leave();
                double id;
                string desig;
                cout<<"enter id\n";
                cin>>id;
                cout<<"enter designation of leave applicant\n";
                cin>>desig;
                try
                {
                    obj.approve_leave(_database.leave_obj(id,desig));
                }
                catch(...)
                {
                    cout<<"Not found\n";
                }
            }
            else
            {
                cout<<"No applications pending for approval";
            }
        }
            obj=_database.get_hod(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 3:
            cout<<(obj.get_leave_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 4:
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;

        default:
            cout<<"wrong choice\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;
    }
}


void Utility_class::visitdir(Director& obj)
{   //interface after logging in as director
    b:
    system("CLS");
    //cout<<endl;
    cout<<"Hi Director!\n";
    cout<<"1.apply for leave\n"<<"2.approve leave\n"<<"3.check leave status\n"<<"4.exit\n";
    int opt;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() ad cin.clear()
    }
    switch(opt)
    {
        case 1: {
            int days;
            cout<<"Enter no. of days of leave required\n";
            cin>>days;
            obj.apply_leave(days,obj.get_leave_obj());
        }
            obj=_database.get_dir(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 2: {
            if(!obj.check_empty_leave())
            {
                obj.show_leave();
                double id;
                string desig;
                cout<<"enter id\n";
                cin>>id;
                cout<<"enter designation of leave applicant\n";
                cin>>desig;
                try
                {
                    obj.approve_leave(_database.leave_obj(id,desig));
                }
                catch(...)
                {
                    cout<<"Not found\n";
                }
            }
            else
            {
                cout<<"No applications pending for approval";
            }
        }
            obj=_database.get_dir(obj.get_id());
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 3:
            cout<<(obj.get_leave_obj()).get_status()<<endl;
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 4:
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;

        default:
            cout<<"wrong choice\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;
    }
}


void Utility_class::visitadm()
{   //interface after logging in as administrator
    b:
    system("CLS");
    //cout<<endl;
    cout<<"Hi Admin!\n";
    cout<<"1.approve pending leaves\n"<<"2.approve pending finances\n"<<"3.exit\n";
    int opt;
    cin>>opt;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //if the choice entered is not an integer the situation is handled using cin.fail() and cin.clear()
    }
    switch(opt)
    {
        case 1: {
            if(!_administrator.check_empty_leave())
            {
                _administrator.show_leave();
                double id;
                string desig;
                cout<<"enter id\n";
                cin>>id;
                cout<<"enter designation of leave applicant\n";
                cin>>desig;
                try
                {
                    _administrator.approve_leave(_database.leave_obj(id,desig));
                }
                catch(...)
                {
                    cout<<"Not found\n";
                }
            }
            else
            {
                cout<<"No applications pending for approval";
            }
        }
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 2: {
            if(!_administrator.check_empty_finance())
            {
                _administrator.show_finance();
                double id;
                string desig;
                cout<<"enter id\n";
                cin>>id;
                cout<<"enter designation of leave applicant\n";
                cin>>desig;
                try
                {
                    _administrator.approve_finance(_database.finance_obj(id,desig));
                }
                catch(...)
                {
                    cout<<"Not found\n";
                }
            }
            else
            {
                cout<<"No applications pending for approval";
            }
        }
            cout<<"\n";
            system("Pause");
            goto b;
            break;

        case 3:
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;

        default:
            cout<<"wrong choice entered\n";
            cout<<"\nRedirecting in \n";
            for(int i=3; i>0; i--)
            {
                cout<<i<<"\n";
                sleep(1);
            }
            _utility.start();
            break;
    }
}
