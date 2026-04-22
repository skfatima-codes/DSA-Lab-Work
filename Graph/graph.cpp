#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
int n;

// INPUT MATRIX
void inputMatrix()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter Adjacency Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
}

// DEGREE OF A VERTEX
int degreeVertex(int v)
{
    int degree = 0;

    for(int j = 0; j < n; j++)
    {
        degree += adj[v][j];
    }

    return degree;
}

// SUM OF ALL DEGREES
int sumDegrees()
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum += adj[i][j];
        }
    }

    return sum;
}

// BFS PATH CHECK
void findPath(int source, int dest)
{
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0, rear = 0, found = 0;

    queue[rear++] = source;
    visited[source] = 1;

    while(front < rear)
    {
        int current = queue[front++];

        if(current == dest)
        {
            found = 1;
            break;
        }

        for(int j = 0; j < n; j++)
        {
            if(adj[current][j] == 1 && !visited[j])
            {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }
    }

    if(found)
        cout << "Path Exists.\n";
    else
        cout << "No Path Exists.\n";
}

// MAIN FUNCTION
int main()
{
    inputMatrix();

    int choice;

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Degree of Vertex\n";
        cout << "2. Sum of Degrees\n";
        cout << "3. Find Path\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            int v;
            cout << "Enter Vertex: ";
            cin >> v;

            cout << "Degree = " << degreeVertex(v) << endl;
        }

        else if(choice == 2)
        {
            cout << "Sum of Degrees = " << sumDegrees() << endl;
        }

        else if(choice == 3)
        {
            int s, d;
            cout << "Enter Source: ";
            cin >> s;

            cout << "Enter Destination: ";
            cin >> d;

            findPath(s, d);
        }

        else if(choice == 4)
        {
            cout << "Program Ended.\n";
        }

        else
        {
            cout << "Invalid Choice.\n";
        }

    } while(choice != 4);

    return 0;
}