/*
Problem Statement : There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph Check whether the graph is connected or not. Justify the storage representation used.
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string city[20];
    int adj_matrix[50][50] = {0, 0};
    cout << "Enter the no. of cities : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of city " << i + 1 << ":";
        cin >> city[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter the time required to travel from city " << city[i] << " to the " << city[j] << " " << endl;
            cin >> adj_matrix[i][j];
            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << city[i] << "\t";
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << city[i] << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << adj_matrix[i][j] << "\t";
        }
    }
}
/*
Output :
Enter the no. of cities : 4
Enter the name of city 1:A
Enter the name of city 2:B
Enter the name of city 3:C
Enter the name of city 4:D
Enter the time required to travel from city A to the B
20
Enter the time required to travel from city A to the C
30
Enter the time required to travel from city A to the D
40
Enter the time required to travel from city B to the C
35
Enter the time required to travel from city B to the D
45
Enter the time required to travel from city C to the D
50
 A B C D
A 0 20 30 40
B 20 0 35 45
C 30 35 0 50
D 40 45 50 0
*/
