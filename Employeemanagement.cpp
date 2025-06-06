#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

void append();
void view();
void search();
void modify();
void del();

class employee
{
    int empno;
    int salary;
    char name[30];
    char mother_name[30];
    char father_name[30];
    char address[30];

public:
    void set()
    {
        cout << "Enter Employee Name : ";
        cin.getline(name, 30);
        cout << endl;

        cout << "Enter Employee ID : ";
        cin >> empno;
        cout << endl;

        cout << "Enter Employee Salary : ";
        cin >> salary;
        cout << endl;

        cin.ignore();

        cout << "Enter Employee's Mother Name : ";
        cin.getline(mother_name, 30);
        cout << endl;

        cout << "Enter Employee's Father Name : ";
        cin.getline(father_name, 30);
        cout << endl;

        cout << "Enter Employee Address : ";
        cin.getline(address, 30);
        cout << endl;
    }

    void view()
    {
        cout << endl;
        cout << "========================================================================================================================================================" << endl;
        cout.setf(ios::right);
        cout << name << "\t\t" << empno << "\t\t\t" << salary << "\t\t\t" << mother_name << "\t\t\t" << father_name << "\t\t\t" << address << "\t\t\t" << endl;
        cout << endl;
    }

    void modify()
    {
        int choice;

        cout << endl;
        cout << "==================================================================================================================" << endl;
        cout << endl;
        cout << "What Do You Want to change for Employee ?? " << endl;
        cout << " [1] Name " << endl;
        cout << " [2] ID " << endl;
        cout << " [3] Salary " << endl;
        cout << " [4] Mother Name " << endl;
        cout << " [5] Father Name " << endl;
        cout << " [6] Address " << endl;
        cout << " [7] Go Back" << endl;
        cout << "Please Select Your Option : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter New Name : ";
            cin >> name;
            break;

        case 2:
            cout << "Enter New ID : ";
            cin >> empno;
            break;

        case 3:
            cout << "Enter New Salary : ";
            cin >> salary;
            break;

        case 4:
            cout << "Enter New Mother Name : ";
            cin >> mother_name;
            break;

        case 5:
            cout << "Enter New Father Name : ";
            cin >> father_name;
            break;

        case 6:
            cout << "Enter New Address : ";
            cin >> address;
            break;

        case 7:
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }

    int getempno()
    {
        return empno;
    }

    char *getempname()
    {
        return name;
    }

    char *getmothername()
    {
        return mother_name;
    }

    char *getfathername()
    {
        return father_name;
    }
};

void menu()
{
    while (1)
    {
        int choice;

        system("CLS");
        cout << endl;

        cout << "====================================================" << endl;
        cout << "\t{ EMPLOYEE MANAGEMENT SYSTEM }" << endl;
        cout << "====================================================" << endl;

        cout << "\tPlease Choose Any 1 Option From The Menu Below" << endl;
        cout << "\t[1] Append New Employee \n"
             << endl;
        cout << "\t[2] View All Employees \n"
             << endl;
        cout << "\t[3] Search An Employee \n"
             << endl;
        cout << "\t[4] Modify An Employee \n"
             << endl;
        cout << "\t[5] Delete An Employee \n"
             << endl;
        cout << "\t[6] Exit Program \n"
             << endl;
        cout << "====================================================" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            view();
            break;
        case 3:
            search();
            break;
        case 4:
            modify();
            break;
        case 5:
            del();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n \tInvalid Choice, Please Try Again";
        }
        getch();
    }
}

int main()
{
    menu();
    return 0;
}

void append()
{
    int i;
    int n;
    employee e;
    fstream fs;

    fs.open("employeemanagement.dat", ios::app | ios::binary);

    if (!fs)
    {
        cout << "\n\t FILE CREATION WAS FAILED" << endl;
        getch();
        exit(0);
    }

    cout << endl;

    cout << "Enter The Number Of Employees You Want To Add : ";
    cin >> n;
    cin.ignore();

    cout << endl;

    for (i = 0; i < n; i++)
    {
        e.set();
        fs.write((char *)&e, sizeof(e));
        cout << "\n=================================================";
        cout << endl;
    }

    cout << "\n\n\t DATA SAVED SUCCESSFULLY !!";
}

void view()
{
    employee e;
    fstream fs;
    int record = 0;

    system("CLS");

    fs.open("employeemanagement.dat", ios::in | ios::binary);

    if (!fs)
    {
        cout << "\n\t FILE OPENING FAILED" << endl;
        getch();
        exit(0);
    }

    cout << endl;

    cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t" << endl;
    while (fs.read((char *)&e, sizeof(e)))
    {
        e.view();
        cout << endl;
        record++;
    }

    fs.close();

    cout << "\n\t Total Number Of Employees :- " << record << endl;
}

void search()
{
    employee e;
    fstream fs;
    int choice;
    int empno;
    char name[30];
    char mother_name[30];
    char father_name[30];
    char address[30];
    int found = 0;

    system("CLS");

    fs.open("employeemanagement.dat", ios::in | ios::binary);

    if (!fs)
    {
        cout << "\n\t FILE OPENING FAILED" << endl;
        getch();
        exit(0);
    }

    cout << "\n\t You Have The Following Option To Search";
    cout << "\n\t[1] Search By ID ";
    cout << "\n\t[2] Search By Name ";
    cout << "\n\t[3] Search By Mother Name ";
    cout << "\n\t[4] Search By Father Name ";
    cout << "\n========================================================================================================================================================" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << endl;
    cin.ignore();
    cout << endl;

    switch (choice)
    {
    case 1:
        cout << "\n\t Enter The Employee ID You Want To Search : ";
        cin >> empno;

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (e.getempno() == empno)
            {
                cout << "\n\t\t\t EMPLOYEE FOUND !!!" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With ID " << empno << " Was Not Found ";
        }

        fs.close();

        break;
    case 2:
        cout << "\n\tEnter The Employee Name You Want To Search : ";
        cin.getline(name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getempname(), name) == 0)
            {
                cout << "\n\t Employee Found" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With Name " << name << " Was Not Found ";
        }

        fs.close();

        break;
    case 3:
        cout << "\n\tEnter The Employee's Mother Name You Want To Search : ";
        cin.getline(mother_name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getmothername(), mother_name) == 0)
            {
                cout << "\n\t Employee Found" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With Mother Name " << mother_name << " Was Not Found ";
        }

        fs.close();

        break;

    case 4:
        cout << "\n\tEnter The Employee's Father Name You Want To Search : ";
        cin.getline(father_name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getfathername(), father_name) == 0)
            {
                cout << "\n\t Employee Found" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With Father Name " << father_name << " Was Not Found ";
        }

        fs.close();

        break;
    }
}

void modify()
{
    employee e;
    fstream fs;
    int choice;
    int empno;
    char name[30];
    char mother_name[30];
    char father_name[30];
    char address[30];
    int found = 0;

    system("CLS");

    fs.open("employeemanagement.dat", ios::in | ios::out | ios::binary);

    if (!fs)
    {
        cout << "\n\t FILE OPENING FAILED" << endl;
        getch();
        exit(0);
    }

    cout << "First We Will Have To Search The Employee !!" << endl;
    cout << "\n========================================================================================================================================================" << endl;

    cout << "\n\t You Have The Following Option To Search";
    cout << "\n\t[1] Search By ID ";
    cout << "\n\t[2] Search By Name ";
    cout << "\n\t[3] Search By Mother Name ";
    cout << "\n\t[4] Search By Father Name ";
    cout << "\n========================================================================================================================================================" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << endl;
    cin.ignore();
    cout << endl;

    switch (choice)
    {
    case 1:
        cout << "\n\t Enter The Employee ID You Want To Search : ";
        cin >> empno;

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (e.getempno() == empno)
            {
                cout << "\n\t\t\t EMPLOYEE FOUND !!!" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                cout << "\n\t Modifying Record...\n";

                e.modify();

                int pos = fs.tellg() - sizeof(e);
                fs.seekp(pos, ios::beg);
                fs.write((char *)&e, sizeof(e));

                cout << "\n\t\t\t MODIFIED RECORD IS AS FOLLOWS";
                e.view();
                cout << endl;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With ID " << empno << " Was Not Found ";
        }

        fs.close();

        break;
    case 2:
        cout << "\n\tEnter The Employee Name You Want To Search : ";
        cin.getline(name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getempname(), name) == 0)
            {
                cout << "\n\t Employee Found" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                cout << "\n\tEmployee Found. Modifying Record...\n";

                e.modify();

                int pos = fs.tellg() - sizeof(e);
                fs.seekp(pos, ios::beg);
                fs.write((char *)&e, sizeof(e));
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With Name " << name << " Was Not Found ";
        }

        fs.close();

        break;
    case 3:
        cout << "\n\tEnter The Employee's Mother Name You Want To Search : ";
        cin.getline(mother_name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getmothername(), mother_name) == 0)
            {
                cout << "\n\t Employee Found" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                cout << "\n\tEmployee Found. Modifying Record...\n";

                e.modify();

                int pos = fs.tellg() - sizeof(e);
                fs.seekp(pos, ios::beg);
                fs.write((char *)&e, sizeof(e));
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With Mother Name " << mother_name << " Was Not Found ";
        }

        fs.close();

        break;

    case 4:
        cout << "\n\tEnter The Employee's Father Name You Want To Search : ";
        cin.getline(father_name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getfathername(), father_name) == 0)
            {
                cout << "\n\t Employee Found" << endl;
                cout << "\n========================================================================================================================================================" << endl;
                cout << "Name \t\t\t" << "ID \t\t\t" << "Salary \t\t\t" << "Mother Name \t\t\t" << "Father Name \t\t\t" << "Address \t\t\t";
                e.view();
                found = 1;
                cout << "\n\tEmployee Found. Modifying Record...\n";

                e.modify();

                int pos = fs.tellg() - sizeof(e);
                fs.seekp(pos, ios::beg);
                fs.write((char *)&e, sizeof(e));
                break;
            }
        }

        if (found == 0)
        {
            cout << "\n\t Employee With Father Name " << father_name << " Was Not Found ";
        }

        fs.close();

        break;
    }
}

void del()
{
    employee e;
    fstream fs;
    fstream o;
    int choice;
    int empno;
    char name[30];
    char mother_name[30];
    char father_name[30];
    int found = 0;
    char ch;

    fs.open("employeemanagement.dat", ios::in | ios::binary);

    if (!fs)
    {
        cout << "\n\t FILE OPENING FAILED" << endl;
        getch();
        exit(0);
    }

    cout << "\n\t You Have The Following Option To Search";
    cout << "\n\t[1] Search By ID ";
    cout << "\n\t[2] Search By Name ";
    cout << "\n\t[3] Search By Mother Name ";
    cout << "\n\t[4] Search By Father Name ";
    cout << "\n========================================================================================================================================================" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        cout << "\n\t Enter The Employee ID You Want To Delete : ";
        cin >> empno;

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (e.getempno() == empno)
            {
                cout << "\n\t Employee Found";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            cout << "\n\tDo You Want To Delete This Record (Y/N)? ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                fs.clear();
                fs.seekg(0);
                o.open("new.dat", ios::out | ios::binary);

                while (fs.read((char *)&e, sizeof(e)))
                {
                    if (e.getempno() != empno)
                    {
                        o.write((char *)&e, sizeof(e));
                    }
                }

                fs.close();
                o.close();
                remove("employeemanagement.dat");
                rename("new.dat", "employeemanagement.dat");
                system("CLS");
                cout << "\n\t DELETION SUCCESSFUL !!";
            }
            else
            {
                cout << "\n\tRecord Not Deleted !";
            }
        }
        else
        {
            cout << "\n\t Employee With ID " << empno << " Was Not Found ";
        }
        fs.close();
        break;

    case 2:
        cout << "\n\tEnter The Employee Name You Want To Delete : ";
        cin.getline(name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getempname(), name) == 0)
            {
                cout << "\n\t Employee Found";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            cout << "\n\tDo You Want To Delete This Record (Y/N)? ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                fs.clear();
                fs.seekg(0);
                o.open("new.dat", ios::out | ios::binary);

                while (fs.read((char *)&e, sizeof(e)))
                {
                    if (strcmp(e.getempname(), name) != 0)
                    {
                        o.write((char *)&e, sizeof(e));
                    }
                }

                fs.close();
                o.close();
                remove("employeemanagement.dat");
                rename("new.dat", "employeemanagement.dat");
                system("CLS");
                cout << "\n\t DELETION SUCCESSFUL !!";
            }
            else
            {
                cout << "\n\tRecord Not Deleted !";
            }
        }
        else
        {
            cout << "\n\t Employee With Name " << name << " Was Not Found ";
        }
        fs.close();
        break;

    case 3:
        cout << "\n\tEnter The Employee's Mother Name You Want To Delete : ";
        cin.getline(mother_name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getmothername(), mother_name) == 0)
            {
                cout << "\n\t Employee Found";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            cout << "\n\tDo You Want To Delete This Record (Y/N)? ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                fs.clear();
                fs.seekg(0);
                o.open("new.dat", ios::out | ios::binary);

                while (fs.read((char *)&e, sizeof(e)))
                {
                    if (strcmp(e.getmothername(), mother_name) != 0)
                    {
                        o.write((char *)&e, sizeof(e));
                    }
                }

                fs.close();
                o.close();
                remove("employeemanagement.dat");
                rename("new.dat", "employeemanagement.dat");
                system("CLS");
                cout << "\n\t DELETION SUCCESSFUL !!";
            }
            else
            {
                cout << "\n\tRecord Not Deleted !";
            }
        }
        else
        {
            cout << "\n\t Employee With Mother Name " << mother_name << " Was Not Found ";
        }
        fs.close();
        break;

    case 4:
        cout << "\n\tEnter The Employee's Father Name You Want To Delete : ";
        cin.getline(father_name, 30);

        while (fs.read((char *)&e, sizeof(e)))
        {
            if (strcmp(e.getfathername(), father_name) == 0)
            {
                cout << "\n\t Employee Found";
                e.view();
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            cout << "\n\tDo You Want To Delete This Record (Y/N)? ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                fs.clear();
                fs.seekg(0);
                o.open("new.dat", ios::out | ios::binary);

                while (fs.read((char *)&e, sizeof(e)))
                {
                    if (strcmp(e.getfathername(), father_name) != 0)
                    {
                        o.write((char *)&e, sizeof(e));
                    }
                }

                fs.close();
                o.close();
                remove("employeemanagement.dat");
                rename("new.dat", "employeemanagement.dat");
                system("CLS");
                cout << "\n\t DELETION SUCCESSFUL !!";
            }
            else
            {
                cout << "\n\tRecord Not Deleted !";
            }
        }
        else
        {
            cout << "\n\t Employee With Father Name " << father_name << " Was Not Found ";
        }
        fs.close();
        break;
    }
}
