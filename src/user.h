#ifndef USER_H
#define USER_H

#include <string>
#include <QVector>

class User
{
public:
    User(std::string user);
    ~User();
    void removeChild();
    bool isRelative(std::string user);
    std::string getName();
    

private:
    std::string m_name;

    QVector<std::string > m_relative;
};

#endif // USER_H
