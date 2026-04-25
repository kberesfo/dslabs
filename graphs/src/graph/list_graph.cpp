#include "graph/list_graph.h"
#include <queue>

int Node::counter = 0;

bool ListGraph::dfs(int startId, int target) const
{
    if (nodes.find(startId) == nodes.end())
        return false;

    std::unordered_set<int> visited;

    return dfs(nodes.at(startId), target, visited);
}

bool ListGraph::dfs(Node *node, int target, std::unordered_set<int> &visited) const
{
    if (node == nullptr)
        return false;

    if (!visited.insert(node->getId()).second)
        return false;

    if (node->data == target)
        return true;

    for (Node *neighbor : node->neighbors)
    {
        if (dfs(neighbor, target, visited))
            return true;
    }

    return false;
}

bool ListGraph::bfs(int startId, int target) const
{
    if (nodes.find(startId) == nodes.end())
        return false;

    return bfs(nodes.at(startId), target);
}

bool ListGraph::bfs(Node *node, int target) const
{
    std::unordered_set<int> visited;
    std::queue<Node *> queue;

    visited.insert(node->getId());
    queue.push(node);

    while (!queue.empty())
    {
        Node *currentNode = queue.front();
        queue.pop();

        if (currentNode->data == target)
            return true;

        for (Node *neighbor : currentNode->neighbors)
        {
            if (neighbor != nullptr && visited.insert(neighbor->getId()).second)
                queue.push(neighbor);
        }
    }
    return false;
}

void ListGraph::addNode(int data)
{
    // create a new node
    Node *node = new Node(data);
    // add it to the nodes map using id as key
    nodes[node->getId()] = node;

    return;
}

void ListGraph::addEdge(int fromId, int toId)
{
    // get the nodes
    auto fromIt = nodes.find(fromId);
    auto toIt = nodes.find(toId);
    // if the edge already exists return
    if (fromIt == nodes.end() || toIt == nodes.end())
        return;
    // add edge to->from
    fromIt->second->neighbors.insert(toIt->second);
    // add inverse edge from->to
    toIt->second->neighbors.insert(fromIt->second);
}