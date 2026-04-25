#include "graph/matrix_graph.h"
#include <queue>

void MatrixGraph::addNode(int data)
{

    // init node
    Node *node = new Node(data);
    // get the idx from the size of the vec
    int idx = (int)nodes.size();
    // use node id as key to mat and the idx as val
    idToIndex[node->getId()] = idx;
    // add to nodes vec
    nodes.push_back(node);
    // add column
    for (auto &row : matrix)
        row.push_back(0);
    // add row
    matrix.push_back(std::vector<int>(nodes.size(), 0));
}

void MatrixGraph::addEdge(int fromId, int toId)
{
    // find the from
    auto fromIt = idToIndex.find(fromId);
    // find the to
    auto toIt = idToIndex.find(toId);
    // if its already and edge exit
    if (fromIt == idToIndex.end() || toIt == idToIndex.end())
        return;
    // add the edge in the adjacency matrix
    int f = fromIt->second, t = toIt->second;
    matrix[f][t] = 1;
    matrix[t][f] = 1;
}

bool MatrixGraph::dfs(int startId, int target) const
{
    // find the start
    auto it = idToIndex.find(startId);
    // find the end
    if (it == idToIndex.end())
        return false;
    // init the visited set
    std::unordered_set<int> visited;
    // kick off the dfs
    return dfs(nodes[it->second], target, visited);
}

bool MatrixGraph::dfs(Node *node, int target, std::unordered_set<int> &visited) const
{
    // base case shouldn't be possible because only valid pointers should be inserted
    if (node == nullptr)
        return false;
    // if not in visited add it // if visited return false
    if (!visited.insert(node->getId()).second)
        return false;
    // if its what we are looking for return true
    if (node->data == target)
        return true;
    // get the idx of the node from the map
    int idx = idToIndex.at(node->getId());
    // iterate over the row, and recursively call dfs on nodes with edges
    for (int i = 0; i < (int)nodes.size(); i++)
    {
        if (matrix[idx][i] && dfs(nodes[i], target, visited))
            return true;
    }
    // lastly retrun false
    return false;
}

bool MatrixGraph::bfs(int startId, int target) const
{
    // find the start
    auto it = idToIndex.find(startId);
    // end
    if (it == idToIndex.end())
        return false;
    // kick off bfs
    return bfs(nodes[it->second], target);
}

bool MatrixGraph::bfs(Node *node, int target) const
{
    // init set and node queue
    std::unordered_set<int> visited;
    std::queue<Node *> queue;
    // insert current node into queue & set
    visited.insert(node->getId());
    queue.push(node);
    // process while queue isn't empty
    while (!queue.empty())
    {
        // get the current node
        Node *current = queue.front();
        // remove current node
        queue.pop();
        // if we found what we are looking for short circuit
        if (current->data == target)
            return true;
        // get the current idx
        int idx = idToIndex.at(current->getId());
        // iterate over the row and check visited
        for (int i = 0; i < (int)nodes.size(); i++)
        {
            // check if there is an edge && insert node id into visited
            if (matrix[idx][i] && visited.insert(nodes[i]->getId()).second)
                // push to queue
                queue.push(nodes[i]);
        }
    }
    // return false over all the nodes
    return false;
}
