#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <createpage.h>
#include <generatepage.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:

private:
    QTabWidget* m_tabWidget;
    CreatePage* m_createPage;
    GeneratePage* m_generatePage;

};

#endif // MAINWINDOW_H
