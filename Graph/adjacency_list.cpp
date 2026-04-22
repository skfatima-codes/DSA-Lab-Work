#include <iostream>
using namespace std;

// Forward declaration for grp implementation
struct edge;

 
struct vertex
{
    char data;
    vertex *next;
    edge *edgelist;
} *Graph = NULL;


struct edge
{
    vertex *to;
    edge *next;
};


//adding vertexx to a undirected graph
void addVertex(char val)
{
    vertex *newNode = new vertex;

    newNode->data = val;
    newNode->next = NULL;
    newNode->edgelist = NULL;

    if(Graph == NULL)
    {
        Graph = newNode;
    }
    else
    {
        vertex *temp = Graph;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}


// ADDing EDGE  to a UNDIRECTED graph
void addEdge(char from, char toVal)
{
    vertex *fromNode = Graph;
    vertex *toNode = Graph;

    // finding from vertex
    while(fromNode != NULL && fromNode->data != from)
    {
        fromNode = fromNode->next;
    }

    // Finding to vertex V
    while(toNode != NULL && toNode->data != toVal)
    {
        toNode = toNode->next;
    }

    if(fromNode == NULL || toNode == NULL)
    {
        cout << "Vertex not found\n";
        return;
    }

    // Edge from -> to showing edges of graph
    edge *newEdge1 = new edge;
    newEdge1->to = toNode;
    newEdge1->next = fromNode->edgelist;
    fromNode->edgelist = newEdge1;

    // Edge to -> from  UNDIRECTED
    edge *newEdge2 = new edge;
    newEdge2->to = fromNode;
    newEdge2->next = toNode->edgelist;
    toNode->edgelist = newEdge2;
}


// showing graph
void display()
{
    vertex *temp = Graph;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";

        edge *e = temp->edgelist;

        while(e != NULL)
        {
            cout << e->to->data << " ";
            e = e->next;
        }

        cout << endl;

        temp = temp->next;
    }
}


// degree of vertex
void degree(char val)
{
    vertex *v = Graph;

    while(v != NULL && v->data != val)
    {
        v = v->next;
    }

    if(v == NULL)
    {
        cout << "Vertex not found\n";
        return;
    }

    int count = 0;

    edge *temp = v->edgelist;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Degree of " << val << " = " << count << endl;
}



int main()
{
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addVertex('E');
    addVertex('F');
    //connection b/w graphs

    addEdge('A', 'B');
    addEdge('A', 'C');
    addEdge('B', 'D');
    addEdge('C', 'D');
    addEdge('C', 'E');
    addEdge('D', 'E');


    cout << "Adjacency List:\n";
    display();
    //degree of all vertex

    degree('A');
    degree('B');
    degree('C');
    degree('D');
    degree('E');
    degree('F');

    return 0;
}