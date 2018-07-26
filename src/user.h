#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User
{
public:
    User(std::string user);
    void removeChild();
    bool isRelative(std::string user);
    std::string getName();

private:
    std::string _name;

    std::vector<std::string > _relative;
};

#endif // USER_H
