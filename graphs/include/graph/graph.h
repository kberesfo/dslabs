// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include "graph/node.h"

class Graph
{
public:
    virtual void addNode(int data) = 0;
    virtual void addEdge(int fromId, int toId) = 0;
    virtual void bfs(int startId) = 0;
    virtual void dfs(int startId) = 0;
    virtual ~Graph() = default;
};

#endif