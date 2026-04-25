// list_graph.h
#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include <unordered_map>
#include <unordered_set>

#include "graph/node.h"
#include "graph/graph.h"

class ListGraph : public Graph
{
private:
    std::unordered_map<int, Node *> nodes;

protected:
    bool dfs(Node *node, int target, std::unordered_set<int> &visited) const override;
    bool bfs(Node *node, int target) const override;

public:
    ListGraph() = default;
    ~ListGraph()
    {
        for (auto &[id, node] : nodes)
            delete node;
    };

    bool bfs(int startId, int target) const override;
    bool dfs(int startId, int target) const override;
    void addNode(int data) override;
    void addEdge(int fromId, int toId) override;
};

#endif