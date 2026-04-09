// list_graph.h
#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include <unordered_map>

#include "graph/node.h"

class ListGraph
{
private:
    std::unordered_map<int, Node *> nodes;

public:
    void addNode(int data);
    void addEdge(int fromId, int toId);
    void bfs(int startId);
    void dfs(int startId);
};

#endif