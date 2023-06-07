
#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:
    int roll_no;
    char name[50];
    char division;
    char address[50];
    void setdata()
    {
        cout << "Enter the following:" << endl;
        cout << "Enter roll no:" << endl;
        cin >> roll_no;
        cout << "Enter the Name:" << endl;
        cin >> name;
        cout << "Enter the division:" << endl;
        cin >> division;
        cout << "Enter the address:" << endl;
        cin >> address;
    }
    void showdata()
    {
        cout << "Name:" << name << endl;
        cout << "Roll No.:" << roll_no << endl;
        cout << "Division:" << division << endl;
        cout << "Address is" << address << endl;
    }

};
    void write_data()
    {
        ofstream outputfile;
        outputfile.open("student.dat", ios::binary | ios::app);
        student obj;
        obj.setdata();
        outputfile.write((char *)&obj, sizeof(obj));
        outputfile.close();
    }
    void display()
    {
        ifstream file;
        file.open("student.dat", ios::binary);
        student obj;
        while (file.read((char *)&obj, sizeof(obj)))
        {
            obj.showdata();
        }
        file.close();
    }
    int search(int n)
    {
        ifstream inFile;
        inFile.open("student.dat", ios::binary);
        bool flag = false;
        student obj;
        while (inFile.read((char *)&obj, sizeof(obj)))
        {
            if (obj.roll_no == n)
            {
                cout << "Student roll number found" << endl;
                obj.showdata();
                flag == true;
                
                return 1;
            }
           
        }
         if(flag == false)
            {
                cout << "record of rollno not found" << endl;
                return 0;
            }
        inFile.close();
    }
    int delete_record(int n)
    {
        student obj;
        ifstream file("student.dat", ios::binary);
        ofstream outputfile("text.dat", ios::binary | ios::out);
        int a = search(n);
        if (a == 1)
        {
            while (file.read((char *)&obj, sizeof(obj)))
            {
                if (obj.roll_no != n)
                {
                    outputfile.write((char *)&obj, sizeof(obj));
                }
            }
            file.close();
            outputfile.close();
            remove("student.dat");
            // remove("temp.dat");
            rename("text.dat","student.dat");
            return 1;
        }
        else
        {
            cout << "Record Not Found" << endl;
            return 0;
        }

    }
int main()
{
    int ch = 0;
    while (ch != 5)
    {
        cout << "\n1.Add record";
        cout << "\n2.Display Record";
        cout << "\n3.Search Record";
        cout << "\n4.Delete a particular from Record";
        cout << "\nEnter your choice";
        cin>>ch;
        if(ch==1){
            int n;
            cout<<"Enter the number of the records to be added"<<endl;
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                write_data();
            }
            
        }
        else if(ch==2){
            display();
        }
        else if(ch==3){
            int roll;
            cout<<"Enter the roll number to be searched"<<endl;
            cin>>roll;
            search(roll);
        }
        else if(ch==4){
             int roll;
            cout<<"Enter the roll number to be deleted"<<endl;
            cin>>roll;
            delete_record(roll);
        }
        else if(ch==5){
            exit(0);
        }
        else{
            cout<<"Enter approriate choice"<<endl;
        }
    }
    return 0;
}