//
// Created by DELL on 04/15/2018.
//

#include "File.h"

void write()
{
    ofstream file;
    file.open("a.txt");
    //file<<_database.ug_data.size()<<endl;
    map<double,Undergrads>::iterator itr;
    for(itr=_database.ug_data.begin(); itr!=_database.ug_data.end(); itr++)
    {
        file<<(itr->second).get_name()<<endl;
        file<<(itr->second).get_id()<<endl;
        file<<(itr->second).get_designation()<<endl;
        file<<(itr->second).password<<endl;
        Leave l=(itr->second).get_leave_obj();
        file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        Finance f=(itr->second).get_finance_obj();
        file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;

    }
    file.close();
}

void write_res()
{
    ofstream file;
    file.open("d.txt");
    //file<<_database.ug_data.size()<<endl;
    map<double,Research_scholar>::iterator itr;
    for(itr=_database.res_data.begin(); itr!=_database.res_data.end(); itr++)
    {
        file<<(itr->second).get_name()<<endl;
        file<<(itr->second).get_id()<<endl;
        file<<(itr->second).get_designation()<<endl;
        file<<(itr->second).password<<endl;
        file<<(itr->second).get_faculty_id()<<endl;
        Leave l=(itr->second).get_leave_obj();
        file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        Finance f=(itr->second).get_finance_obj();
        file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;

    }
    file.close();
}



void write_adm()
{
    ofstream file;
    file.open("b.txt");
    list <Leave>::iterator it;
    list<Finance>::iterator itr;
    //for(it=_administrator
    //file.write((char *)&(_administrator),sizeof(_administrator));
    for(it=_administrator.leave_pending.begin(); it!=_administrator.leave_pending.end(); it++)
    {   Leave l=(*it);
        file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
    }
    file.close();
    file.open("c.txt");
    for(itr=_administrator.finance_pending.begin(); itr!=_administrator.finance_pending.end(); itr++)
    {   Finance f=(*itr);
        file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;

    }


    file.close();
}


void write_dir()
{
    ofstream file;
    file.open("g.txt");
    //file<<_database.ug_data.size()<<endl;
    //map<double,Faculty>::iterator itr;
    file<<(_director).get_name()<<endl;
    file<<(_director).get_id()<<endl;
    file<<(_director).get_designation()<<endl;
    file<<(_director).password<<endl;
    //file<<(itr->second).get_department()<<endl;
    Leave l=(_director).get_leave_obj();
    file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
    list <Leave>::iterator it;
    list<Finance>::iterator ptr;
    //for(it=_administrator
    //file.write((char *)&(_administrator),sizeof(_administrator));
    file<<(_director).leave_pending.size()<<endl;
    for(it=(_director).leave_pending.begin(); it!=(_director).leave_pending.end(); it++)
    {   Leave l=(*it);
        file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
    }
    file<<(_director).finance_pending.size()<<endl;
    for(ptr=(_director).finance_pending.begin(); ptr!=(_director).finance_pending.end(); ptr++)
    {   Finance f=(*ptr);
        file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;

    }

    file.close();

}



void write_fac()
{
    ofstream file;
    file.open("e.txt");
    //file<<_database.ug_data.size()<<endl;
    map<double,Faculty>::iterator itr;
    for(itr=_database.fac_data.begin(); itr!=_database.fac_data.end(); itr++)
    {
        file<<(itr->second).get_name()<<endl;
        file<<(itr->second).get_id()<<endl;
        file<<(itr->second).get_designation()<<endl;
        file<<(itr->second).password<<endl;
        file<<(itr->second).get_department()<<endl;
        Leave l=(itr->second).get_leave_obj();
        file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        list <Leave>::iterator it;
        list<Finance>::iterator ptr;
        //for(it=_administrator
        //file.write((char *)&(_administrator),sizeof(_administrator));
        file<<(itr->second).leave_pending.size()<<endl;
        for(it=(itr->second).leave_pending.begin(); it!=(itr->second).leave_pending.end(); it++)
        {   Leave l=(*it);
            file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        }
        file<<(itr->second).finance_pending.size()<<endl;
        for(ptr=(itr->second).finance_pending.begin(); ptr!=(itr->second).finance_pending.end(); ptr++)
        {   Finance f=(*ptr);
            file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;

        }
    }
    file.close();

}

void write_hod()
{
    ofstream file;
    file.open("f.txt");
    //file<<_database.ug_data.size()<<endl;
    map<double,Hod>::iterator itr;
    for(itr=_database.hod_data.begin(); itr!=_database.hod_data.end(); itr++)
    {
        file<<(itr->second).get_name()<<endl;
        file<<(itr->second).get_id()<<endl;
        file<<(itr->second).get_designation()<<endl;
        file<<(itr->second).password<<endl;
        file<<(itr->second).get_department()<<endl;
        Leave l=(itr->second).get_leave_obj();
        file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        list <Leave>::iterator it;
        list<Finance>::iterator ptr;
        //for(it=_administrator
        //file.write((char *)&(_administrator),sizeof(_administrator));
        file<<(itr->second).leave_pending.size()<<endl;
        for(it=(itr->second).leave_pending.begin(); it!=(itr->second).leave_pending.end(); it++)
        {   Leave l=(*it);
            file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        }
        file<<(itr->second).finance_pending.size()<<endl;
        for(ptr=(itr->second).finance_pending.begin(); ptr!=(itr->second).finance_pending.end(); ptr++)
        {   Finance f=(*ptr);
            file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;

        }
    }
    file.close();

}


void read_adm()
{
    ifstream file;
    file.open("b.txt");
    //file.read((char *)&(_administrator),sizeof(_administrator));
    if(!file)return;
    Leave l;
    while(file>>l.status>>l.number>>l.designation>>l.id>>l.applied)
    {
        _administrator.add_leave(l);
    }
    file.close();

    file.open("c.txt");
    //file.read((char *)&(_administrator),sizeof(_administrator));
    if(!file)return;
    Finance f;
    while(file>>f.status>>f.amount>>f.family_income>>f.designation>>f.id>>f.applied) {
        _administrator.add_finance(f);
    }
    file.close();
}



void read()
{
    ifstream file;
    file.open("a.txt");
    if(!file)return;
    int size;
    //file>>size;
    //cout<<"hello\n";//
    map<double,Undergrads>::iterator itr;
    string name,designation,password;
    double id;
    //for(int i=0;i<size;i++){
    while(file>>name>>id>>designation>>password)
    {
        //string name;file>>name;//file<<(itr->second).get_name()<<endl;
        //double id;file>>id;//file<<(itr->second).get_id()<<endl;
        //string designation;file>>designation;//file<<(itr->second).get_designation()<<endl;
        Leave l;//Leave l=(itr->second).get_leave_obj();
        //file>>l;//file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        file>>l.status;
        file>>l.number;
        file>>l.designation;
        file>>l.id;
        file>>l.applied;
        Finance f;//Finance f=(itr->second).get_finance_obj();
        file>>f.status;
        file>>f.amount;
        file>>f.family_income;
        file>>f.designation;
        file>>f.id;
        file>>f.applied;
        //file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;
        Undergrads ug(name,id,designation,l,f);
        ug.password=password;
        _database.addug(ug);


    }
    file.close();
}

void read_res()
{
    ifstream file;
    file.open("d.txt");
    if(!file)return;
    int size;
    //file>>size;
    //cout<<"hello\n";//
    map<double,Undergrads>::iterator itr;
    string name,designation,password;
    double id,faculty_id;
    //for(int i=0;i<size;i++){
    while(file>>name>>id>>designation>>password>>faculty_id)
    {
        //string name;file>>name;//file<<(itr->second).get_name()<<endl;
        //double id;file>>id;//file<<(itr->second).get_id()<<endl;
        //string designation;file>>designation;//file<<(itr->second).get_designation()<<endl;
        Leave l;//Leave l=(itr->second).get_leave_obj();
        //file>>l;//file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        file>>l.status;
        file>>l.number;
        file>>l.designation;
        file>>l.id;
        file>>l.applied;
        Finance f;//Finance f=(itr->second).get_finance_obj();
        file>>f.status;
        file>>f.amount;
        file>>f.family_income;
        file>>f.designation;
        file>>f.id;
        file>>f.applied;
        //file<<f.get_status()<<endl<<f.check_amount()<<endl<<f.check_income()<<endl<<f.get_designation()<<endl<<f.get_id()<<endl<<f.get_applied()<<endl;
        Research_scholar ug(name,id,designation,faculty_id,l,f);
        ug.password=password;
        _database.addres(ug);


    }
    file.close();
}

void read_fac()
{
    ifstream file;
    file.open("e.txt");
    if(!file)return;
    int size;
    //file>>size;
    //cout<<"hello\n";//
    map<double,Faculty>::iterator itr;
    string name,designation,department,password;
    double id;
    //for(int i=0;i<size;i++){
    while(file>>name>>id>>designation>>password>>department)
    {
        //string name;file>>name;//file<<(itr->second).get_name()<<endl;
        //double id;file>>id;//file<<(itr->second).get_id()<<endl;
        //string designation;file>>designation;//file<<(itr->second).get_designation()<<endl;
        Leave l;//Leave l=(itr->second).get_leave_obj();
        //file>>l;//file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        file>>l.status;
        file>>l.number;
        file>>l.designation;
        file>>l.id;
        file>>l.applied;

        Faculty ug(name,id,designation,department,l);
        int count,tag;
        file>>count;
        Leave p;
        while(count&&(file>>p.status>>p.number>>p.designation>>p.id>>p.applied)) {
            count--;
            ug.add_leave(p);
        }
        file>>tag;
        Finance f;
        while(tag&&(file>>f.status>>f.amount>>f.family_income>>f.designation>>f.id>>f.applied)) {
            tag--;
            ug.add_finance(f);
        }
        ug.password=password;
        _database.addfac(ug);
    }
    file.close();
}


void read_hod()
{
    ifstream file;
    file.open("f.txt");
    if(!file)return;
    int size;
    //file>>size;
    //cout<<"hello\n";//
    //map<double,Faculty>::iterator itr;
    string name,designation,department,password;
    double id;
    //for(int i=0;i<size;i++){
    while(file>>name>>id>>designation>>password>>department)
    {
        //string name;file>>name;//file<<(itr->second).get_name()<<endl;
        //double id;file>>id;//file<<(itr->second).get_id()<<endl;
        //string designation;file>>designation;//file<<(itr->second).get_designation()<<endl;
        Leave l;//Leave l=(itr->second).get_leave_obj();
        //file>>l;//file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        file>>l.status;
        file>>l.number;
        file>>l.designation;
        file>>l.id;
        file>>l.applied;

        Hod ug(name,id,designation,department,l);
        int count,tag;
        file>>count;
        Leave p;
        while(count&&(file>>p.status>>p.number>>p.designation>>p.id>>p.applied)) {
            count--;
            ug.add_leave(p);
        }
        file>>tag;
        Finance f;
        while(tag&&(file>>f.status>>f.amount>>f.family_income>>f.designation>>f.id>>f.applied)) {
            tag--;
            ug.add_finance(f);
        }
        ug.password=password;
        _database.addhod(ug);
    }
    file.close();
}


void read_dir()
{
    ifstream file;
    file.open("g.txt");
    if(!file)return;
    int size;
    //file>>size;
    //cout<<"hello\n";//
    //map<double,Faculty>::iterator itr;
    string name,designation,password;
    double id;
    //for(int i=0;i<size;i++){
    while(file>>name>>id>>designation>>password) {
        //string name;file>>name;//file<<(itr->second).get_name()<<endl;
        //double id;file>>id;//file<<(itr->second).get_id()<<endl;
        //string designation;file>>designation;//file<<(itr->second).get_designation()<<endl;
        Leave l;//Leave l=(itr->second).get_leave_obj();
        //file>>l;//file<<l.get_status()<<endl<<l.check_number()<<endl<<l.get_designation()<<endl<<l.get_id()<<endl<<l.get_applied()<<endl;
        file>>l.status;
        file>>l.number;
        file>>l.designation;
        file>>l.id;
        file>>l.applied;

        Director ug(name,id,designation,l);
        int count,tag;
        file>>count;
        Leave p;
        while(count&&(file>>p.status>>p.number>>p.designation>>p.id>>p.applied)) {
            count--;
            ug.add_leave(p);
        }
        file>>tag;
        Finance f;
        while(tag&&(file>>f.status>>f.amount>>f.family_income>>f.designation>>f.id>>f.applied)) {
            tag--;
            ug.add_finance(f);
        }
        ug.password=password;
        _database.adddir(ug);
    }
    file.close();
}
