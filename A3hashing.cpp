#include <iostream>
#include <string.h>
using namespace std;
class Telephone
{
    int hash_address, i, j;
    long long key;
    int x;
    int mobno[10];
    string name[10];

public:
    Telephone()
    {
        for (int i = 0; i < 10; i++)
        {
            mobno[i] = -1;
        }
    }
    void insertRecord_LP()
    {
        cout << "Enter no of record: ";
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            cout << "Enter Telephone no: ";
            cin >> key;
            hash_address = key % 10;
            if (mobno[hash_address] == -1)
            {
                mobno[hash_address] = key;
                cout << "Enter name: ";
                cin >> name[hash_address];
            }
            else // linear probing
            {
                int i = 1;
                while (mobno[hash_address + i] < 10)
                {
                    if (mobno[hash_address + i] == -1)
                    {
                        mobno[hash_address + i] = key;
                        cout << "Enter name : ";
                        cin >> name[hash_address + i];
                        break;
                    }
                    else if (mobno[hash_address + i] != -1)
                    {
                        i++;
                    }
                }
            }
        }
    }
    void insertRecord_QP()
    {
        cout << "Enter no of record: ";
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            cout << "Enter Telephone no: ";
            cin >> key;
            hash_address = key % 10;
            if (mobno[hash_address] == -1)
            {
                mobno[hash_address] = key;
                cout << "Enter name: ";
                cin >> name[hash_address];
            }
            else // quadratic probing
            {
                int i = 1;
                hash_address =(hash_address + (i * i))%10;
                while (mobno[hash_address] < 10)
                {
                    if (mobno[hash_address] == -1)
                    {
                        mobno[hash_address] = key;
                        cout << "Enter name : ";
                        cin >> name[hash_address];
                        break;
                    }
                    else if (mobno[hash_address] != -1)
                    {
                        i++;
                        // hash_address = hash_address + (i * i);
                    hash_address =(hash_address + (i * i))%10;

                    }
                }
            }
        }
    }
    void display()
    {
        for (int address = 0; address < 10; address++)
        {
            cout << address << " " << mobno[address] << " " << name[address] << endl;
        }
    }
};
int main()
{
    Telephone t1;
    int ch;
    do
    {
        cout << "\n1.Insert Record(Linear Probing)";
        cout << "\n2.Insert Record(Quadratic Probing)";
        cout << "\n3.Display";
        cout << "\n4.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            t1.insertRecord_LP();
            break;
        case 2:
            t1.insertRecord_QP();
            break;
        case 3:
            t1.display();
            break;
        case 4:
            exit(0);
            break;
        }
    } while (ch != 4);
    return 0;
}
/*
Output :
1.Insert Record(Linear Probing)
2.Insert Record(Quadratic Probing)
3.Display
4.Exit
Enter your choice:1
Enter no of record: 4
Enter Telephone no: 123
Enter name: A
Enter Telephone no: 234
Enter name: B
Enter Telephone no: 345
Enter name: C
Enter Telephone no: 456
Enter name: D
1.Insert Record(Linear Probing)
2.Insert Record(Quadratic Probing)
3.Display
4.Exit
Enter your choice:3
0 -1
1 -1
2 -1
3 123 A
4 234 B
5 345 C
6 456 D
7 -1
8 -1
9 -1
1.Insert Record(Linear Probing)
2.Insert Record(Quadratic Probing)
3.Display
4.Exit
Enter your choice:2
Enter no of record: 3
Enter Telephone no: 678
Enter name: P
Enter Telephone no: 891
Enter name: Q
Enter Telephone no: 789
Enter name: R
1.Insert Record(Linear Probing)
2.Insert Record(Quadratic Probing)
3.Display
4.Exit
Enter your choice:3
0 -1
1 891 Q
2 -1
3 123 A
4 234 B
5 345 C
6 456 D
7 -1
8 678 P
9 789 R
1.Insert Record(Linear Probing)
2.Insert Record(Quadratic Probing)
3.Display
4.Exit
Enter your choice:4
*/
