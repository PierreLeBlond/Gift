#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <user.h>
#include "node.h"

class Graph
{
public:
    Graph();
    ~Graph();
    void addUser(User* user);
    void addNode(Node* node);
    void createEdges();
    std::string createMatche(QVector<std::string> save);
    void setUsers(QVector<std::string> users);
    void setAvailable(QVector<std::string> users);
    void setAlreadyTaken(QVector<std::string> users);
    void addTaken(std::string taken);
    Graph* copie();
    bool hasItem(QVector<std::string > vect, std::string item);
    Node* findNode();
    void exportGraph();
    Node* findNodeByName(std::string name);
    void noMoreAvailable(std::string item);
    void killParents(Node* childNode, Node* onlyParent);


private:
    QVector<Node*> m_nodes;
    QVector<std::string> m_users;
    QVector<std::string> m_available;
    QVector<std::string> m_alreadyTaken;
    int m_nbVertex;
};

#endif // GRAPH_H
