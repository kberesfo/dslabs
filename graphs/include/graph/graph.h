// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include "graph/node.h"

class Graph
{

protected:
    virtual bool dfs(Node *node, int target, std::unordered_set<int> &visited) const = 0;
    virtual bool bfs(Node *node, int target) const = 0;

public:
    virtual void addNode(int data) = 0;
    virtual void addEdge(int fromId, int toId) = 0;
    virtual bool bfs(int startId, int target) const = 0;
    virtual bool dfs(int startId, int target) const = 0;
    virtual ~Graph() = default;
};

#endif