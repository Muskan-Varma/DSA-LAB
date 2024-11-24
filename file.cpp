/*Ass 11 --> Department maintains student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular student. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to maintain the data. 

Done by Muskan Varma on 09/05/2023*/

#include <iostream>
#include <fstream>
using namespace std;

struct student
{
          int roll;
          char name[20];
          void getdata(){
                    cout << "\n Enter roll and name :";
                    cin >> roll >> name;
          }
          void putdata(){
                    cout << "\n" << roll << " " << name ;
          }
};

class File
{
          fstream fp; student s;
          public:
          void create(); 
          void display();
          void append();
          void search();
          void update();
          void logicaldelete();
          void physicaldelete();
          void display1();
          void display2();
}; 

void File::create(){
          char ans;
          fp.open("student.dat",ios::out);
          do{
                    s.getdata();
                    fp.write((char*)&s,sizeof(s));
                    cout <<"\n Add more?";
                    cin>> ans;
          }while(ans=='y');
          fp.close(); 
}
void File::display(){
          fp.open("student.dat",ios::in);
          while (!fp.eof()){
                    fp.read((char*)&s,sizeof(s));
                    if (!fp.eof())
                    s.putdata();
          }
          fp.close();
}
void File:: append(){
          char ans;
          fp.open("student.dat",ios::app);
          do{
                    s.getdata();
                    fp.write((char*)&s,sizeof(s));
                    cout <<"\n Add more?";
                    cin>> ans;
          }while(ans=='y');
          fp.close();
}

void File::search(){
          fp.open("student.dat",ios::in); int r;
          cout << "\n Enter roll to be searched :";
          cin >> r;
          while (!fp.eof()){
                    fp.read((char*)&s,sizeof(s));
                    if (!fp.eof() and s.roll==r) {
                              s.putdata();
                              break;
                    }
          }
          fp.close();
}

void File::physicaldelete(){
          int r;
          fstream tfp;
          fp.open("student.dat",ios::in);
          tfp.open("temp",ios::out);
          cout << "\n Enter roll to be deleted :";
          cin >> r;
          while (fp.read((char*)&s,sizeof(s))){
                    if (s.roll==r){
                              cout << "\n Deleting .....\n";
                              s.putdata();
                    }
                    else{
                              tfp.write((char*)&s,sizeof(s));
                    }
          }
          fp.close();
          tfp.close();
          remove("student.dat");
          rename("temp","student.dat");
}

void File::update(){
          int r;
          fp.open("student.dat",ios::in|ios::out);
          cout << "\n Enter roll to be updated :";
          cin >> r;
          while (fp.read((char*)&s,sizeof(s))){
                    if (s.roll==r){
                              cout << "\n Enter name to update:";
                              cin >> s.name;
                              fp.write((char*)&s,sizeof(s));
                              //fp.seekg(0);
                              break;
                    }
          }
          fp.close();
}

void File::display1(){
          fp.open("student.dat",ios::in);
          while (!fp.eof()){
                    fp.read((char*)&s,sizeof(s));
                    if (s.roll !=0){
                              s.putdata();
                    }
          }
          fp.close();
}

int main()
{
          File ob;
          int ch;
          do{
                    cout<<"\n\nSelect :";
                    cout<<"\n1.Create\n2.Search\n3.Update\n4.Append";
                    cout<<"\n5.Physical delete\n6.Display\n7.Exit\n\n";
                    cin>>ch;
                    switch(ch)
                    {
                              case 1:ob.create();
                              break;
                              case 2:ob.search();
                              break;
                              case 3:ob.update();
                              break;
                              case 4:ob.append();
                              break;
                              case 5:ob.physicaldelete();
                              break;
                              case 6:ob.display();
                              break;
                              
                              case 7: exit(0);
                              default:cout<<"\nInvalid !!!!!!\n";
                              break;
                    }
          }while(ch!=10);
          
          
          
          
          
          
          
}




