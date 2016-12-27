#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class Student{
int roll;
char name[20];
int marks[10];
char grade;
public:
   void new_student();
   char getGrade(int[],int);
   int retroll();
   void display();
   void report();

};
void welcome(){
cout<<"\n\n\n\n\tWELCOME TO STUDENTS' DATABASE\n\n";
cin.get();
}
char Student::getGrade(int m[],int sub){
int sum =0;
for(int i=0;i<sub;i++){
    sum += m[i];
}
int avg = sum / sub;
switch(avg/10){
case 9:
case 10:
    return 'A';
    break;
case 8:
     return 'B';
     break;
case 7:
   return 'C';
    break;
case 6:
    return 'D';
    break;
default:
    return 'F';
}

}
void Student::new_student(){
    system("cls");
cout<<"\n\n\n\tENTER ROLL: ";
cin>>roll;
cout<<"\n\n\tENTER NAME: ";
cin.ignore();
cin.getline(name,20);
cout<<"\n\n\tENTER NUMBER OF SUBJECTS: ";
int sub;
cin>>sub;
cout<<"\n\n\tENTER MARKS (0-100): ";
for(int i=0;i<sub;i++){
    cin>>marks[i];
    }
 grade = getGrade(marks,sub);

system("cls");
cout<<"\n\n\n\tNEW STUDENT ADDED\n";
 cin.get();
}


void add(){
    Student s;
ofstream outFile;
outFile.open("student.dat",ios::binary|ios::out);
s.new_student();
outFile.write(reinterpret_cast<char*>(&s),sizeof(Student));
outFile.close();
}
int Student::retroll(){
return roll;
}

void Student::display(){
//cin.ignore();
system("cls");
cout<<"\n\n\n\n\tROLL: "<<roll;
cout<<"\n\n\tNAME: "<<name;
cout<<"\n\n\tGRADE: "<<grade;

cin.get();
}

void show(){
int n;
system("cls");
cout<<"\n\n\n\tENTER ROLL NUMBER: ";
cin>>n;
ifstream inFile;
Student s;
inFile.open("student.dat",ios::binary);
inFile.seekg(0,ios::beg);
if(!inFile){
    cout<<"\n\n\n\tFAILED TO OPEN THE FILE. PRESS ANY KEY.....\n\n\n";
}
while(inFile.read(reinterpret_cast<char*>(&s),sizeof(Student))){
    if(s.retroll()==n){
        s.display();
    }
}

inFile.close();
cin.get();
}

void Student::report(){
cout<<roll<<"\t"<<name<<"\t"<<grade<<endl;
}
void display_all(){
    system("cls");
Student s;
ifstream inFile;
inFile.open("student.dat",ios::binary);
cout<<"\n\n-----------------------------------";
cout<<"\nROLL\tNAME\tGRADE\n";
cout<<"---------------------------------------\n";
while(inFile.read(reinterpret_cast<char*>(&s),sizeof(Student))){
    s.report();
}
cin.get();
}

int main(){

welcome();
char ch;
do{
system("cls");
cout<<"\n\n\n\n\tMAIN MENU\n\n";
cout<<"\n\t1: ADD\n";
cout<<"\n\t2: SHOW\n";
cout<<"\n\t3: SEARCH\n";
cout<<"\n\t4: DISPLAY ALL\n";
cout<<"\n\tE/e: EXIT\n\n";
cout<<"\tCHOOSE A OPTION: ";
cin>>ch;
switch(ch){
case '1':
    add();
    break;
case '2':
    show();
    break;
case '3':
    cout<<"\n\n\n\tSEARCH";
    show();
    break;
case '4':
    display_all();
    break;
case 'E':
 case 'e':
     system("cls");
   cout<<"\n\n\n\tTHANK YOU!!!!!!\n\n";
   return 0;
    break;
}
cin.ignore();
}while(ch!='E'||ch!='e');

return 0;
}
