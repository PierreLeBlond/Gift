#include "generatepage.h"
#include <fstream>
#include <QMessageBox>

GeneratePage::GeneratePage()
{
    m_layout = new QGridLayout();
    setLayout(m_layout);

    m_button = new QPushButton("Generate");
    connect(m_button, SIGNAL(clicked()), this, SLOT(generate()));

    m_layout->addWidget(m_button, 0, 0);

}

GeneratePage::~GeneratePage()
{
    delete(m_button);
    delete(m_layout);
}

void GeneratePage::generate()
{
    QVector<std::string > vect;
    m_save.push(vect);
    Graph* g = startGraph();
    m_graphs.push(g);
    nextStep();
}

void GeneratePage::nextStep()
{
    Graph* g = m_graphs.top();
    Graph* h = g->copie();

    std::string newMatche = h->createMatche(m_save.top());
    if(newMatche == "")
    {
        m_graphs.pop();
        m_save.pop();
        nextStep();
    }
    else
    {
        m_save.top().append(newMatche);
        QVector<std::string > vect;
        m_save.push(vect);
        h->noMoreAvailable(newMatche);
        m_graphs.push(h);
        if(m_users.size() > m_graphs.size() - 1)
            nextStep();
        else
            h->exportGraph();
    }
}

Graph* GeneratePage::startGraph()
{
    Graph* g = new Graph;
    std::ifstream f("../data/user.txt");

    std::string line;
    if(f)
    {
        while(std::getline(f, line))
        {
            m_users.append(line);
        }
        g->setUsers(m_users);
        g->setAvailable(m_users);

        for(int i = 0;i < m_users.size(); i++)
        {
            User* user = new User(m_users[i]);
            g->addUser(user);
        }
    }
    else
        QMessageBox::information(this, "error", "No user file.");
    return g;
}
