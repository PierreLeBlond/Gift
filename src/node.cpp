#include <iostream>
#include "node.h"

Node::Node(User* user)
{
    _user = user;

}

void Node::createEdges(std::vector<std::string> users)
{
    for(int i = 0;i < users.size();i++)
    {
        if(_user->getName() != users[i] && !_user->isRelative(users[i]))
        {
            _child.push_back(users[i]);
        }
    }
}

User* Node::getUser()
{
    return _user;
}

void Node::setChilds(std::vector<std::string> childs)
{
    for(int i = 0;i < childs.size();i++)
    {
        _child.push_back(childs[i]);
    }
}

std::vector<std::string> Node::getChilds()
{
    return _child;
}

void Node::killChild(std::string onlyChild)
{
    for(int i = 0;i < _child.size();i++)
    {
        if(_child[i] != onlyChild)
            _child[i] = "";
    }
}

void Node::killOneChild(std::string child)
{
    for(int i = 0;i < _child.size();i++)
    {
        if(_child[i] == child)
            _child[i] = "";
    }
}
