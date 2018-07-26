#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "user.h"
#include "node.h"

class Graph
{
public:
    Graph();
    void addUser(User* user);
    void addNode(Node* node);
    void createEdges();
    std::string createMatche(std::vector<std::string> save);
    void setUsers(std::vector<std::string> users);
    void setAvailable(std::vector<std::string> users);
    void setAlreadyTaken(std::vector<std::string> users);
    void addTaken(std::string taken);
    Graph* copie();
    bool hasItem(std::vector<std::string > vect, std::string item);
    Node* findNode();
    void exportGraph();
    Node* findNodeByName(std::string name);
    void noMoreAvailable(std::string item);
    void killParents(Node* childNode, Node* onlyParent);


private:
    std::vector<Node*>          _nodes;
    std::vector<std::string>    _users;
    std::vector<std::string>    _available;
    std::vector<std::string>    _alreadyTaken;
    int                         _nbVertex;
};

#endif // GRAPH_H
