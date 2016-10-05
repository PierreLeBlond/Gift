#ifndef GENERATEPAGE_H
#define GENERATEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <user.h>
#include <stack>
#include <graph.h>

class GeneratePage : public QWidget
{
    Q_OBJECT
public:
    GeneratePage();
    ~GeneratePage();

public slots:
    void generate();
    Graph* startGraph();
    void nextStep();



private:
    QPushButton* m_button;
    QGridLayout* m_layout;

    std::stack<Graph*> m_graphs;
    std::stack<QVector<std::string > > m_save;
    QVector<std::string> m_users;
};

#endif // GENERATEPAGE_H
