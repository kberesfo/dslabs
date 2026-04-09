// matrix_graph.h
#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <vector>

#include "graph/node.h"

class MatrixGraph
{
private:
    std::vector<int, Node *> nodes;
    std::vector<std::vector<int>> matrix;

public:
    void addNode(int data);
    void addEdge(int fromId, int toId);
    void bfs(int startId);
    void dfs(int startId);
};

#endif