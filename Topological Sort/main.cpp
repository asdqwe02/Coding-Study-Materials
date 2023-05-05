// NOTE: DELETE ALL COMMENT BEFORE SUBMITTING
#include <iostream>
#include <stack>
#include <list>
using namespace std;

// Class to represent a graph
class Graph
{
    // Nnumber of vertices
    int V;

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int> &Stack);

public:
    // Constructor
    Graph(int V);

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.size() != 1)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }

    // delete the borrowed memory space
    delete[] visited;
}

// Driver Code
int main()
{
    int m = -1, n = -1;

    // List of all test cases to print out
    // each test case is a graph with different input edge value
    list<Graph> testCases;
    int caseCount = 1; // DELETE THIS LINE WHEN SUBMIT

    // Initial input
    cout << "test case number: " << caseCount << endl; // DELETE THIS LINE WHEN SUBMIT
    cin >> m >> n;

    // Processing input
    // if both m and n is 0 then quit the while loop
    while (m != 0 || n != 0)
    {
        Graph testCase(m + 1);
        for (int i = 0; i < n; i++)
        {
            int a = 0, b = 0;
            cin >> a >> b;
            testCase.addEdge(a, b);
        }

        // add newly input test case into test case list
        // and increase the test case count
        testCases.push_back(testCase);
        caseCount++;                                       // DELETE THIS LINE WHEN SUBMIT
        cout << "test case number: " << caseCount << endl; // DELETE THIS LINE WHEN SUBMIT
        cin >> m >> n;
    }
    cout << "output:\n"; // DELETE THIS LINE WHEN SUBMIT
    for (Graph g : testCases)
    {
        g.topologicalSort();
        cout << endl;
    }
    return 0;
}