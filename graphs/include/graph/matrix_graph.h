// matrix_graph.h
#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "graph/node.h"
#include "graph/graph.h"

class MatrixGraph : public Graph
{
private:
    std::vector<Node *> nodes;
    std::unordered_map<int, int> idToIndex;
    std::vector<std::vector<int>> matrix;

protected:
    bool dfs(Node *node, int target, std::unordered_set<int> &visited) const override;
    bool bfs(Node *node, int target) const override;

public:
    MatrixGraph() = default;
    ~MatrixGraph()
    {
        for (Node *node : nodes)
            delete node;
    }

    bool bfs(int startId, int target) const override;
    bool dfs(int startId, int target) const override;
    void addNode(int data) override;
    void addEdge(int fromId, int toId) override;
};

#endif
