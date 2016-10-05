#include "user.h"
#include <fstream>
#include <QMessageBox>

User::User(std::string user)
{
    m_name = user;
    std::string path = "../data/" + user + ".txt";
    std::ifstream f(path.c_str());

    if(f)
    {
        std::string line;
        while(getline(f, line))
        {
            m_relative.append(line);
        }
    }
    else
        QMessageBox::information(0, "error", "utilisateur introuvable");
}

User::~User()
{
    
}

void User::removeChild()
{

}

bool User::isRelative(std::string user)
{
    int i = 0;
    while(i < m_relative.size() && m_relative[i] != user)
    {
        i++;
    }
    return i < m_relative.size();
}

std::string User::getName()
{
    return m_name;
}
