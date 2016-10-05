#include "createpage.h"
#include <QMessageBox>
#include <fstream>
#include <string>

CreatePage::CreatePage()
{
    m_layout = new QGridLayout;

    setLayout(m_layout);

    m_formLayout = new QFormLayout;
        m_firstName = new QLineEdit;
        m_lastName = new QLineEdit;
        m_family = new QLineEdit;
        m_godFather = new QLineEdit;
        m_godMother = new QLineEdit;

    m_formLayout->addRow("firstname :", m_firstName);
    m_formLayout->addRow("lastname :", m_lastName);
    m_formLayout->addRow("familly :", m_family);
    m_formLayout->addRow("godfather :", m_godFather);
    m_formLayout->addRow("godmother :", m_godMother);

    m_button = new QPushButton("Confirm");

    m_layout->addLayout(m_formLayout, 0 ,0);
    m_layout->addWidget(m_button, 1, 0);

    connect(m_button, SIGNAL(clicked()), this, SLOT(createUser()));
}

CreatePage::~CreatePage()
{
    delete(m_godMother);
    delete(m_godFather);
    delete(m_family);
    delete(m_lastName);
    delete(m_firstName);

    delete(m_formLayout);

    delete(m_layout);
}

void CreatePage::createUser()
{
    if(m_firstName->text().isEmpty() || m_lastName->text().isEmpty() || m_family->text().isEmpty())
    {
        QMessageBox::information(this, "error", "Please fill the main field");
    }
    else
    {
        std::string path;
        path.append("../data/");

        path.append(m_firstName->text().toStdString().c_str());
        path.append("_");
        path.append(m_lastName->text().toStdString().c_str());
        path.append(".txt");
        std::ifstream test(path.c_str());

        if(test)
        {
            QMessageBox::information(this, "error", "This person already exist.");
        }
        else
        {
            std::ofstream f(path.c_str());
            std::ofstream u("../data/user.txt", std::ios::app);
            if(f && u)
            {
                f << m_firstName->text().toStdString().c_str() << std::endl << m_lastName->text().toStdString().c_str() << std::endl << m_family->text().toStdString().c_str() << " " << m_godFather->text().toStdString().c_str() << " " << m_godMother->text().toStdString().c_str();
                u << std::endl << m_firstName->text().toStdString().c_str() << "_" << m_lastName->text().toStdString().c_str();
            }
            else
                QMessageBox::information(this, "error", "Can't create the file.");
        }
    }
}
