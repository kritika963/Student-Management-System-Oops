#include <iostream>       // input-output header file
#include <fstream>        // read data from file and write data to the file
#include <thread>
#include <chrono>     //specifically for sleep function
#include <cstdio>
using namespace std;

class Student {
    private : 
    string Name, Branch;
    int RollNo, Current_sem, Marks_Maths, Marks_C, Marks_Phy;
    public :
    Student() : Name(""), Branch(""), RollNo(), Marks_Maths(), Marks_C(), Marks_Phy(), Current_sem(){}

    void setStudentData(){         //use of the setter function
        cout << "Enter name of student: "; 
        cin >>  Name;
        cout << "Enter Branch: ";
        cin >> Branch;
        cout << "Enter roll no. of student: ";
        cin >> RollNo;
        cout << "Current semester: ";
        cin >> Current_sem;
        cout << "Enter marks of Maths of student: ";
        cin >> Marks_Maths;
        cout << "Enter marks of C of student: ";
        cin >> Marks_C;
        cout << "Enter marks of Physics of student: ";
        cin >> Marks_Phy;

    }
    void displayStudentData(){
        cout << "\n\t\t\t ___________________________________"<< endl;
        cout << "\tName of student is: " << Name << endl;
        cout << "\tRoll no. of student is: " << RollNo << endl;
        cout << "\tMarks of Maths of student is: " << Marks_Maths << endl;
        cout << "\tMarks of C of student is: " << Marks_C << endl;
        cout << "\tMarks of Physics of student is: " << Marks_Phy << endl;
        cout << "\tCurrent Semester is: " << Current_sem << endl;
    }
    int getRollNo(){               //use of the getter function
        return RollNo; }
    int getMarks_Maths(){
        return Marks_Maths; }
    int getMarks_C(){
        return Marks_C; }
    int getMarks_Phy(){
        return Marks_Phy; }
    int getCurrent_sem(){
        return Current_sem;
    }
    string getName(){
    return Name;}
    string getBranch(){
    return Branch;}
};
int main(){         //menu
    system("clear");
    while(true){
        int chose;
        cout << "\n\t\t\t ___________________________________"<< endl;
        cout << "\t\t\t\t\t STUDENT MANAGEMENT SYSTEM"<< endl;
        cout << "\t\t\t ___________________________________"<< endl;
        cout << "\t\t\t\t\t 1. Insert student data"<< endl;
        cout << "\t\t\t\t\t 2. Display student data"<< endl;
        cout << "\t\t\t\t\t 3. Search student data"<< endl;
        cout << "\t\t\t\t\t 4. Delete student data"<< endl;
        cout << "\t\t\t\t\t 5.  Update student data"<< endl;
        cout << "Chose any one option: " ;
        cin >> chose;       //ab jo b option user chose krega hum uski further coding krenge using switch-case statements
        switch(chose){
            case 1:
            {
                Student s;      //we have created an object 
                s.setStudentData();      //insert mein we want ki student data liya jaye user se toh we will use set vala function
                //jese hi yeh function call hoga (setter vala) toh user se woh sari details maangi jayengi
                //ab data toh aagya hai isko file mein store krwana hai permanantly so that we can use it later
                //we will use ofstream (output - file - flow of data)
                ofstream ofs; //iski help se we will open a file jismein data insert kiya jaa ske
                ofs.open("student.txt", ios::app);     //complier will create this file and inserts the data in it
                //ios::app (append) mtlb jb new data add ho toh previous vala delete na ho
                ofs << s.getName() << " "
                    << s.getBranch() << " "
                    << s.getRollNo() << " "
                    << s.getCurrent_sem() << " "
                    << s.getMarks_Maths() << " "
                    << s.getMarks_C() << " "
                    << s.getMarks_Phy() << endl;
                ofs.close();
                cout <<"\t Record Inserted Successfully" << endl;
                cout << "\t Enter any key to continue! "<< endl;
                cin.ignore();
                cin.get();
                break;
            }
            case 2:
            {
                ifstream ifs;
                ifs.open("student.txt");
                if (!ifs){
                cout << "Error: File could not be opened!" << endl;
                break;}
                string Name, Branch;
                int RollNo, Current_sem, Marks_Maths, Marks_C, Marks_Phy;
                while (ifs >> Name >> Branch >> RollNo >> Current_sem >> Marks_Maths >> Marks_C >> Marks_Phy)
                {
                  cout << "\nName: " << Name << endl;
                  cout << "Branch: " << Branch <<endl;
                  cout << "Roll No: " << RollNo << endl;
                  cout << "Semester: " << Current_sem << endl;
                  cout << "Maths: " << Marks_Maths << endl;
                  cout << "C: " << Marks_C << endl;
                  cout << "Physics: " << Marks_Phy << endl;
                }

                 ifs.close();
                 break;
            }
            case 3: {
                int searchRoll;
                bool found = false;
                cout << "Enter Roll No. to search student data: " ;
                cin >> searchRoll;
                ifstream ifs("student.txt");
                string Name, Branch;
                int RollNo, Current_sem, Marks_Maths, Marks_C, Marks_Phy;
                while (ifs >> Name >> Branch >> RollNo >> Current_sem >> Marks_Maths >> Marks_C >> Marks_Phy){
                if(RollNo == searchRoll){
                    cout << "\n\t\tStudent Found Successfully!" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Name      : " << Name << endl;
                    cout << "Branch    : " << Branch << endl;
                    cout << "Roll No   : " << RollNo << endl;
                    cout << "Semester  : " << Current_sem << endl;
                    cout << "Maths     : " << Marks_Maths << endl;
                    cout << "C         : " << Marks_C << endl;
                    cout << "Physics   : " << Marks_Phy << endl;
                    cout << "----------------------------------------" << endl;

                found = true;
                break;
                }
            }
                if(!found){
                    cout << "\n Student not found!" << endl;
                }
                break;
            }
            case 4:
            {
            int deleteRoll;
            bool found = false;
            cout << "Enter Roll Number to Delete: ";
            cin >> deleteRoll;
            ifstream ifs("student.txt");

            if (!ifs)
    {
        cout << "File not found!" << endl;
        break;
    }
           ofstream ofs("temp.txt");

           string Name, Branch;
           int RollNo, Current_sem, Marks_Maths, Marks_C, Marks_Phy;
           while (ifs >> Name >> Branch >> RollNo >> Current_sem >> Marks_Maths >> Marks_C >> Marks_Phy)
    {
        if (RollNo == deleteRoll)
        {
            found = true;
            continue;
        }

        ofs << Name << " "
            << Branch << " "
            << RollNo << " "
            << Current_sem << " "
            << Marks_Maths << " "
            << Marks_C << " "
            << Marks_Phy << endl;
    }

    ifs.close();
    ofs.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
    {
        cout << "\nStudent Deleted Successfully!" << endl;
    }
    else
    {
        cout << "\nStudent Not Found!" << endl;
    }

    break;
}
case 5:
{
    int updateRoll;
    bool found = false;

    cout << "Enter Roll Number to Update: ";
    cin >> updateRoll;

    ifstream ifs("student.txt");

    if (!ifs)
    {
        cout << "File not found!" << endl;
        break;
    }

    ofstream ofs("temp.txt");

    string Name, Branch;
    int RollNo, Current_sem, Marks_Maths, Marks_C, Marks_Phy;

    while (ifs >> Name >> Branch >> RollNo >> Current_sem >> Marks_Maths >> Marks_C >> Marks_Phy)
    {
        if (RollNo == updateRoll)
        {
            found = true;

            cout << "\nEnter Updated Details\n";

            cout << "Enter Name: ";
            cin >> Name;

            cout << "Enter Branch: ";
            cin >> Branch;

            cout << "Enter Semester: ";
            cin >> Current_sem;

            cout << "Enter Maths Marks: ";
            cin >> Marks_Maths;

            cout << "Enter C Marks: ";
            cin >> Marks_C;

            cout << "Enter Physics Marks: ";
            cin >> Marks_Phy;
        }

        ofs << Name << " "
            << Branch << " "
            << RollNo << " "
            << Current_sem << " "
            << Marks_Maths << " "
            << Marks_C << " "
            << Marks_Phy << endl;
    }

    ifs.close();
    ofs.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "\nStudent Updated Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";

    break;
}
            }
        }
    return 0;
};