#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class SecWindow;
}

class SecWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecWindow(QWidget *parent = 0);
    ~SecWindow();

    int count1;
    QString word1;
    QString word2;
public slots:
     void myFunction();
     void myFunction2();

private slots:

    int on_pushButton_search_clicked();
    int searchFunc(QString text);
    int on_pushButton_search2_clicked();
    int searchFunc2(QString text);

private:
    Ui::SecWindow *ui;
//    QTimer *timer;
};

#endif // SECWINDOW_H
