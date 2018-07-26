#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "graph.h"

std::stack<Graph*> graphs;
std::stack<std::vector<std::string>> save;
std::vector<std::string> users;

void nextStep() {
    Graph* g = graphs.top();
    Graph* h = g->copie();

    std::string newMatche = h->createMatche(save.top());
    if(newMatche == "")
    {
        graphs.pop();
        save.pop();
        nextStep();
    }
    else
    {
        save.top().push_back(newMatche);
        std::vector<std::string > vect;
        save.push(vect);
        h->noMoreAvailable(newMatche);
        graphs.push(h);
        std::cout << users.size() << "   " << graphs.size() << std::endl;
        if(users.size() > graphs.size() - 1)
            nextStep();
        else
            h->exportGraph();
    }
}

Graph* startGraph()
{
    Graph* g = new Graph;
    std::ifstream f("../data/user.txt");

    std::string line;
    if(f)
    {
        while(std::getline(f, line))
        {
            users.push_back(line);
        }
        g->setUsers(users);
        g->setAvailable(users);

        for(int i = 0;i < users.size(); i++)
        {
            User* user = new User(users[i]);
            g->addUser(user);
        }
    }
    else
        std::cerr << "No user file." << std::endl;
    return g;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> vect;
    save.push(vect);
    Graph* g = startGraph();
    graphs.push(g);
    nextStep();
}
