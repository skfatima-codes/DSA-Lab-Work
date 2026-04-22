#include <iostream>

using namespace std;

#define MAX 10  // Maximum number of vertices


struct vertex {
    int data; 
};

//
struct vertex Graph[MAX];

// : Boolean 2-D array for edges
int adj_matrix[MAX][MAX]; 

int n; // Current number of vertices in the graph

// Function to initialize the graph
void initGraph(int vertices) {
    n = vertices;
    for (int i = 0; i < n; i++) {
        Graph[i].data = i; // Assigning simple data to each vertex
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0; // Initialize matrix with 0 (no edges)
        }
    }
}

// 
void addEdge(int u, int v) {
    if (u < n && v < n) {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1; // Assuming Undirected Graph
    }
}

// Degree of a vertex
int getDegree(int v) {
    int degree = 0;
    for (int i = 0; i < n; i++) {
        if (adj_matrix[v][i] == 1) {
            degree++;
        }
    }
    return degree;
}

//  Sum of degrees
int sumOfDegrees() {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += getDegree(i);
    }
    return total;
}

//  Finding Path (Source to Destination)
bool visited[MAX]; // Global visited array for pathfinding

bool hasPath(int src, int dest) {
    if (src == dest) return true;

    visited[src] = true;

    for (int i = 0; i < n; i++) {
        // If connected and not visited
        if (adj_matrix[src][i] == 1 && visited[i] == false) {
            if (hasPath(i, dest)) return true;
        }
    }
    return false;
}

int main() {
    // Initialize graph with 5 vertices
    initGraph(5);

    // Add some edges
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);

    // Display Degree
    cout << "Degree of Vertex 1: " << getDegree(1) << endl;

    // Display Sum of Degrees
    cout << "Sum of all Degrees: " << sumOfDegrees() << endl;

    // Check Path from 0 to 4
    // Reset visited array before searching
    for(int i = 0; i < MAX; i++) visited[i] = false;

    if (hasPath(0, 4)) {
        cout << "Path found from 0 to 4!" << endl;
    } else {
        cout << "No path exists between 0 and 4." << endl;
    }

    return 0;
}