#ifndef NODE_H
#define NODE_H

#include <vector>

#include "user.h"

class Node
{
public:
    Node(User *user);
    void createEdges(std::vector<std::string> users);
    User* getUser();
    void setChilds(std::vector<std::string> childs);
    std::vector<std::string> getChilds();
    void killChild(std::string onlyChild);
    void killOneChild(std::string child);

private:
    User* _user;
    std::vector<std::string> _child;

};

#endif // NODE_H
