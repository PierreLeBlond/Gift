#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setFixedSize(600, 400);

    m_tabWidget = new QTabWidget;
    setCentralWidget(m_tabWidget);

    m_createPage = new CreatePage;
    m_generatePage = new GeneratePage;

    //m_tabWidget->addTab(m_createPage, "Creation");
    m_tabWidget->addTab(m_generatePage, "Generation");


}

MainWindow::~MainWindow()
{
    delete(m_generatePage);
    delete(m_createPage);
    delete(m_tabWidget);
}
