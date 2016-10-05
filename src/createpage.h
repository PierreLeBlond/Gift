#ifndef CREATEPAGE_H
#define CREATEPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

class CreatePage : public QWidget
{
    Q_OBJECT
public:
    CreatePage();
    ~CreatePage();

public slots:
    void createUser();

private:
    QGridLayout* m_layout;

        QFormLayout* m_formLayout;
            QLineEdit* m_firstName;
            QLineEdit* m_lastName;
            QLineEdit* m_family;
            QLineEdit* m_godFather;
            QLineEdit* m_godMother;

        QPushButton* m_button;
};

#endif // CREATEPAGE_H
