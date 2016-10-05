#include "graph.h"
#include "node.h"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <QMessageBox>

Graph::Graph()
{
    m_nbVertex = 0;

}

Graph::~Graph()
{

}

void Graph::addUser(User* user)
{
    Node* node = new Node(user);
    node->createEdges(m_users);
    m_nodes.append(node);
    m_nbVertex++;
}

void Graph::addNode(Node* node)
{
    m_nodes.append(node);
}

void Graph::createEdges()
{

}

std::string Graph::createMatche(QVector<std::string> save)
{
    srand(time(NULL));
    Node* node = findNode();
    QVector<std::string> vect;
    QVector<std::string> childs = node->getChilds();
    for(int i = 0;i < childs.size();i++)
    {
        if(!hasItem(save, childs[i]) && hasItem(m_available, childs[i]))
        {
            vect.append(childs[i]);
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
    QMessageBox::information(0, "info", "Job's done !");
    std::ofstream f("../result/2017.txt");

    for(int i = 0;i < m_nodes.size();i++)
    {
        f << m_nodes[i]->getUser()->getName();
        f << "offre à : ";
        QVector<std::string> vect = m_nodes[i]->getChilds();
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
    for(int i = 0;i < m_nodes.size();i++)
    {
        if(m_nodes[i] != childNode && m_nodes[i] != onlyParent)
        {
            m_nodes[i]->killOneChild(childNode->getUser()->getName());
        }
    }
}

Node* Graph::findNodeByName(std::string name)
{
    int i(0);
    while(i < m_nodes.size() && m_nodes[i]->getUser()->getName() != name)
        i++;
    if(i < m_nodes.size())
        return m_nodes[i];
    else
        return NULL;
}

bool Graph::hasItem(QVector<std::string> vect, std::string item)
{
    int i = 0;
    while(i < vect.size() && (vect[i] == "" || vect[i] != item))
        i++;
    return i < vect.size();
}

Node* Graph::findNode()
{
    int j = 0;
    Node* node = m_nodes[0];
    while(hasItem(m_alreadyTaken, m_nodes[j]->getUser()->getName()))
    {
        j++;
        node = m_nodes[j];
    }
    for(int i = j;i < m_nodes.size();i++)
    {
        if(node->getChilds().size() > m_nodes[i]->getChilds().size() && !(hasItem(m_alreadyTaken, m_nodes[i]->getUser()->getName())))
            node = m_nodes[i];
    }
    return node;
}

void Graph::setUsers(QVector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        m_users.append(users[i]);
    }
}

void Graph::setAvailable(QVector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        m_available.append(users[i]);
    }
}

void Graph::setAlreadyTaken(QVector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        m_alreadyTaken.append(users[i]);
    }
}

void Graph::noMoreAvailable(std::string item)
{
    for(int i = 0;i < m_available.size();i++)
    {
        if(m_available[i] == item)
            m_available[i] = "";
    }
}

void Graph::addTaken(std::string taken)
{
    m_alreadyTaken.append(taken);
}

Graph* Graph::copie()
{
    Graph* g = new Graph;
    g->setUsers(m_users);
    g->setAvailable(m_available);
    g->setAlreadyTaken(m_alreadyTaken);
    for(int i = 0;i < m_nodes.size();i++)
    {
        Node* node = new Node(m_nodes[i]->getUser());
        node->setChilds(m_nodes[i]->getChilds());
        g->addNode(node);
        m_nbVertex++;
    }
    return g;
}
