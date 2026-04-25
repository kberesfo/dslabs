#include <iostream>
#include "graph/list_graph.h"
#include "graph/matrix_graph.h"

using namespace std;


void buildGraph(Graph &g)
{
    g.addNode(10); // ID 0
    g.addNode(20); // ID 1
    g.addNode(30); // ID 2
    g.addNode(40); // ID 3
    g.addNode(50); // ID 4
    g.addNode(60); // ID 5

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
}

void runSearches(Graph &g, const string &label)
{
    cout << "=== " << label << " ===" << endl;
    cout << "BFS from 10: search for 50 -> " << (g.bfs(0, 50) ? "found" : "not found") << endl;
    cout << "BFS from 10: search for 99 -> " << (g.bfs(0, 99) ? "found" : "not found") << endl;
    cout << "DFS from 10: search for 50 -> " << (g.dfs(0, 50) ? "found" : "not found") << endl;
    cout << "DFS from 10: search for 99 -> " << (g.dfs(0, 99) ? "found" : "not found") << endl;
    cout << endl;
}

int main()
{
    // reset node counter just in case
    Node::resetCounter();
    // init graph
    ListGraph listGraph;
    // build the graph with helper function
    buildGraph(listGraph);
    // run predefined search as list graph
    runSearches(listGraph, "Adjacency List (ListGraph)");
    // reset node counter
    Node::resetCounter();
    // init graph
    MatrixGraph matrixGraph;
    // build graph with helper
    buildGraph(matrixGraph);
    // run predefined search as matrix
    runSearches(matrixGraph, "Adjacency Matrix (MatrixGraph)");

    return 0;
}
