#ifndef NODE_H
#define NODE_H

#include "user.h"
#include <QVector>

class Node
{
public:
    Node(User *user);
    void createEdges(QVector<std::string> users);
    User* getUser();
    void setChilds(QVector<std::string> childs);
    QVector<std::string> getChilds();
    void killChild(std::string onlyChild);
    void killOneChild(std::string child);

private:
    User* m_user;
    QVector<std::string> m_child;

};

#endif // NODE_H
