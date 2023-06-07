#include <iostream>
using namespace std;
class node
{
public:
    char label[50];
    int child_count;
    node *child[10];
};

class tree
{
public:
    node *root;
    void create()
    {
        root = new node();
        cout << "enter the name of book:";
        cin >> root->label;
        cin.ignore();
        cout << "\nHow many chapters does the book Has: ";
        cin >> root->child_count;
        for (int i = 0; i < root->child_count; i++)
        {
            root->child[i] = new node();
            cout << "Enter the name of the chapter :" << endl;
            cin >> root->child[i]->label;
            cout << "How many sections are there :" << endl;
            cin >> root->child[i]->child_count;
            for (int j = 0; j < root->child[i]->child_count; j++)
            {
                root->child[i]->child[j] = new node();
                cout << "\nEnter the name of the section :" << endl;
                cin >> root->child[i]->child[j]->label;
                cout << "\nHow many sub sections are there :" << endl;
                cin >> root->child[i]->child[j]->child_count;
                for (int k = 0; k < root->child[i]->child[j]->child_count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node();
                    cout << "\nEnter the Name of Sub-Section " << k + 1 << ": ";
                    cin >> root->child[i]->child[j]->child[k]->label;
                    
                }
            }
        }
    }
        void display()
    {
        node *temp;
        temp = root;
        cout << "book name:" << root->label;
        cout << "\n";
        for (int i = 0; i < temp->child_count; i++)
        {
            cout << "\nChapter " << i + 1 << ": " << root->child[i]->label;
            for (int j = 0; j < root->child[i]->child_count; j++)
            {

                cout << "\n\t\tSection " << j + 1 << ":" << root->child[i]->child[j]->label;
                for (int k = 0; k < root->child[i]->child[j]->child_count; k++)
                {
                    cout << "\n\t\t\t\tSub-Section " << k + 1 << ": " << root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
    };
    int main(){

        tree book;
        book.create();
        book.display();
    }