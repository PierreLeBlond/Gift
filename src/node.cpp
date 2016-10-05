#include "node.h"

Node::Node(User* user)
{
    m_user = user;

}

void Node::createEdges(QVector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        if(m_user->getName() != users[i] && !m_user->isRelative(users[i]))
        {
            m_child.append(users[i]);
        }
    }
}

User* Node::getUser()
{
    return m_user;
}

void Node::setChilds(QVector<std::string> childs)
{
    for(int i = 0;i < childs.size();i++)
    {
        m_child.append(childs[i]);
    }
}

QVector<std::string> Node::getChilds()
{
    return m_child;
}

void Node::killChild(std::string onlyChild)
{
    for(int i = 0;i < m_child.size();i++)
    {
        if(m_child[i] != onlyChild)
            m_child[i] = "";
    }
}

void Node::killOneChild(std::string child)
{
    for(int i = 0;i < m_child.size();i++)
    {
        if(m_child[i] == child)
            m_child[i] = "";
    }
}
