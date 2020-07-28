#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "QMessageBox"
#include <QtWidgets>
#include <QXmlStreamReader>
#include <QFile>
#include <QHash>
#include <QDebug>
#include <QString>
#include <QXmlSimpleReader>
#include <QDomDocument>
#include <QDomElement>
#include "secwindow.h"

using namespace std;
QString Username;
QString Password;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_clicked();
    ui->lineEdit_2_password->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void outString(string ref1,string ref2)
{

    std::cout << "   Username  = " << ref1 << std::endl;
    std::cout << "   Password = " << ref2 << std::endl;

}

int MainWindow::on_pushButton_Login_clicked()
{

    QString username2 = ui->lineEdit_username->text();
    QString password2 = ui->lineEdit_2_password->text();

    outString(username2.toStdString(),password2.toStdString());
    outString(Username.toStdString(),Password.toStdString());

    SecWindow secondWindow;
    secondWindow.setModal(true);

    for(int i=0 ; i<userID.count() ; i++)
    {
    if(username2 == userID[i] && password2 ==  userPass[i])
    {
        QMessageBox::information(this,"Login","Username and Password is correct");
        hide();
        secondWindow.exec();
        return 0;
    }
    }
        QMessageBox::warning(this,"Login","Username and Password is NOT correct");
        return 1;
}

int MainWindow::on_pushButton_clicked()
{
    // Load xml file as raw data
    QFile f("/home/tarik/Masaüstü/Login.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        return 1;
    }
    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();
    on_pushButton_2_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{

    QDomElement root=xmlBOM.documentElement();

    // Get the first child of the root (Markup COMPONENT is expected)
    QDomElement Information=root.firstChild().toElement();

    // Loop while there is a child
    while(!Information.isNull())
    {
        // Check if the child tag name is Information
        if (Information.tagName()=="Information")
        {

            // Read and display the component ID
            QString ID=Information.attribute("ID","No ID");

            // Get the first child of the component
            QDomElement Child=Information.firstChild().toElement();


            // Read each child of the component node
            while (!Child.isNull())
            {
                // Read Name and value
                if (Child.tagName()=="Username") Username=Child.firstChild().toText().data();
                if (Child.tagName()=="Password") Password=Child.firstChild().toText().data();


                // Next child
                Child = Child.nextSibling().toElement();
            }

            // Display component data
            std::cout << "Information " << ID.toStdString().c_str() << std::endl;
            std::cout << "   Username  = " << Username.toStdString().c_str() << std::endl;
            std::cout << "   Password = " << Password.toStdString().c_str() << std::endl;
            std::cout << std::endl;

            userID.append(Username);
            userPass.append(Password);
        }

        // Next component
        Information = Information.nextSibling().toElement();
    }

}
