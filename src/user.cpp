#include <fstream>
#include <iostream>

#include "user.h"

User::User(std::string user)
{
    _name = user;
    std::string path = "../data/" + user + ".txt";
    std::ifstream f(path.c_str());

    if(f)
    {
        std::string line;
        while(getline(f, line))
        {
            _relative.push_back(line);
        }
    }
    else
        std::cerr << "utilisateur introuvable" << std::endl;
}

void User::removeChild()
{

}

bool User::isRelative(std::string user)
{
    int i = 0;
    while(i < _relative.size() && _relative[i] != user)
    {
        i++;
    }
    return i < _relative.size();
}

std::string User::getName()
{
    return _name;
}
