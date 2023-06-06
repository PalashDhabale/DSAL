/*Company maintains employee information as employee ID, name, designation and salary. Allow user to add, delete information of employee. Display information of particular employee. If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. Use index sequential file to maintain the data.*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct employee
{
    int empid;
    string name;
    string designation;
    float salary;
};

void add_info()
{
    ofstream file;
    file.open("employee1.txt" , ios::app);

    employee info;

    cout<<"**Enter Employee information**"<<endl;
    cout<<"\tEnter Employee id : ";
    cin>>info.empid;
    cin.ignore();
    cout<<"\tEnter Employee name :";
    getline(cin , info.name);
    cout<<"\tEnter Designation : ";
    getline(cin,info.designation);
    cout<<"\tEnter salary : ";
    cin>>info.salary;

    file<<info.empid<<" "<<info.name<<" "<<info.designation<<" "<<info.salary<<endl;

    file.close();
    cout<<"Data inserted successfuly";
}

void delete_info()
{
    ifstream file;
    file.open("employee1.txt");
    ofstream tempfile;
    tempfile.open("temp1.txt");

    int employee_id;
    cout<<"Enter the Employee id to be deleted: ";
    cin>>employee_id;

    employee info;

    bool found = false;

    while(file>>info.empid>>info.name>>info.designation>>info.salary)
    {
        if(info.empid != employee_id)
        {
            tempfile<<info.empid<<info.name<<info.designation<<info.salary<<endl;
        }
        else
            found = true;
    }
    file.close();
    tempfile.close();

    if(found)
    {
        remove("employee.txt");
        rename("temp1.txt" , "employee.txt");
        cout<<"*Employee data Deletd successfully*";
    }
    else
    {
        remove("temp1.txt");
        cout<<"Employee Does not exist"<<endl;
    }

}

void display_info()
{
    ifstream file;
    file.open("employee1.txt" , ios::app);
    int emp_id;
    cout<<"Enter Employee id: ";
    cin>>emp_id;
    employee info;
    bool found = true;
    while(file>>info.empid>>info.name>>info.designation>>info.salary)
    {
        if(info.empid == emp_id)
        {
            cout<<"Employee id :           "<<info.empid<<endl;
            cout<<"Employee name :         "<<info.name<<endl;
            cout<<"Employee Designition :  "<<info.designation<<endl;
            cout<<"Employee salary :       "<<info.salary<<endl;
            break;
        }
        else
            cout<<"Invalid Employee id ";
    }
    file.close();

}

int main()
{
    int choice;
    while(true)
    {
        cout<<"**Employee Database**"<<endl;
        cout<<"\t1. Add Employee data "<<endl;
        cout<<"\t2. Display Employee Data "<<endl;
        cout<<"\t3. Delete Employee Data "<<endl;
        cout<<"\t4. Exit"<<endl;
        cout<<"\t\t Enter your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            add_info();
            break;
        case 2:
            display_info();
            break;
        case 3:
            delete_info();
            break;
        case 4:
            cout<<"Program Exited "<<endl;
        default:
            break;
        }
        cout<<endl;
    }
    return 0;
}