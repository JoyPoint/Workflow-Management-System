#include "Utility_class.h"

int main()
{   //It calls the utility class

    /*Undergrads ug;
    fstream file;

       file.open("a.txt",ios::in);

    /while(file.read((char*)&ug,sizeof(ug))&&(!file.eof())){
    _database.ug_data.insert(pair<double,Undergrads>(ug.get_id(),ug));}/
    file.read((char*)&_director,sizeof(_director))&&(!file.eof());

    file.close();

    cout<<"hello"<<endl;*/
    read();
    read_adm();
    read_res();
    read_fac(),read_hod(),read_dir();
    _utility.start();
    /*file.open("a.txt",ios::out|ios::app);
    //for(auto &i: _database.ug_data){

    //file.write((char*)&(i.second),sizeof(i.second));

      /map<double,Undergrads>::iterator itr;
      for(itr=_database.ug_data.begin();itr!=_database.ug_data.end();itr++){
    file.write((char*)&(itr->second),sizeof(itr->second));
    }/
    file.write((char*)&_director,sizeof(_director))&&(!file.eof());

    file.close();*/

    return 0;
}