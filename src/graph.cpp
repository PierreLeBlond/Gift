#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "graph.h"
#include "node.h"

Graph::Graph()
{
    _nbVertex = 0;
}

void Graph::addUser(User* user)
{
    Node* node = new Node(user);
    node->createEdges(_users);
    _nodes.push_back(node);
    _nbVertex++;
}

void Graph::addNode(Node* node)
{
    _nodes.push_back(node);
}

void Graph::createEdges()
{

}

std::string Graph::createMatche(std::vector<std::string> save)
{
    srand(time(NULL));
    Node* node = findNode();
    std::vector<std::string> vect;
    std::vector<std::string> childs = node->getChilds();
    for(int i = 0;i < childs.size();i++)
    {
        if(!hasItem(save, childs[i]) && hasItem(_available, childs[i]))
        {
            vect.push_back(childs[i]);
        }
    }
    if(vect.size() == 0)
        return "";
    else
    {
        int r = rand() % vect.size();
        addTaken(node->getUser()->getName());
        Node* childNode = findNodeByName(vect[r]);
        if(childNode)
        {
        killParents(childNode, node);
        node->killChild(vect[r]);
        }
        return vect[r];
    }
}

void Graph::exportGraph()
{
    std::cout << "Job's done !" << std::endl;
    std::ofstream f("../result/2018.txt");

    for(int i = 0;i < _nodes.size();i++)
    {
        f << _nodes[i]->getUser()->getName();
        f << "offre à : ";
        std::vector<std::string> vect = _nodes[i]->getChilds();
        for(int j = 0;j< vect.size();j++)
        {
            if(vect[j] != "")
                f << vect[j];
        }
        f << std::endl;
    }
}

void Graph::killParents(Node* childNode, Node* onlyParent)
{
    for(int i = 0;i < _nodes.size();i++)
    {
        if(_nodes[i] != childNode && _nodes[i] != onlyParent)
        {
            _nodes[i]->killOneChild(childNode->getUser()->getName());
        }
    }
}

Node* Graph::findNodeByName(std::string name)
{
    int i(0);
    while(i < _nodes.size() && _nodes[i]->getUser()->getName() != name)
        i++;
    if(i < _nodes.size())
        return _nodes[i];
    else
        return NULL;
}

bool Graph::hasItem(std::vector<std::string> vect, std::string item)
{
    int i = 0;
    while(i < vect.size() && (vect[i] == "" || vect[i] != item))
        i++;
    return i < vect.size();
}

Node* Graph::findNode()
{
    int j = 0;
    Node* node = _nodes[0];
    while(hasItem(_alreadyTaken, _nodes[j]->getUser()->getName()))
    {
        j++;
        node = _nodes[j];
    }
    for(int i = j;i < _nodes.size();i++)
    {
        if(node->getChilds().size() > _nodes[i]->getChilds().size() && !(hasItem(_alreadyTaken, _nodes[i]->getUser()->getName())))
            node = _nodes[i];
    }
    return node;
}

void Graph::setUsers(std::vector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        _users.push_back(users[i]);
    }
}

void Graph::setAvailable(std::vector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        _available.push_back(users[i]);
    }
}

void Graph::setAlreadyTaken(std::vector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        _alreadyTaken.push_back(users[i]);
    }
}

void Graph::noMoreAvailable(std::string item)
{
    for(int i = 0;i < _available.size();i++)
    {
        if(_available[i] == item)
            _available[i] = "";
    }
}

void Graph::addTaken(std::string taken)
{
    _alreadyTaken.push_back(taken);
}

Graph* Graph::copie()
{
    Graph* g = new Graph;
    g->setUsers(_users);
    g->setAvailable(_available);
    g->setAlreadyTaken(_alreadyTaken);
    for(int i = 0;i < _nodes.size();i++)
    {
        Node* node = new Node(_nodes[i]->getUser());
        node->setChilds(_nodes[i]->getChilds());
        g->addNode(node);
        _nbVertex++;
    }
    return g;
}
