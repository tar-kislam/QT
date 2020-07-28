#include "secwindow.h"
#include "ui_secwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QIODevice>
#include <QTime>
#include <QThread>

SecWindow::SecWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecWindow)
{
    ui->setupUi(this);
}

SecWindow::~SecWindow()
{
    delete ui;
}

void SecWindow::myFunction()
{
    SecWindow::searchFunc(word1);
}
void SecWindow::myFunction2()
{
     SecWindow::searchFunc2(word2);
}

int SecWindow::on_pushButton_search_clicked()
{
    word1 = ui->s1Txt->text();
    QTimer::singleShot(1000,this,SLOT(myFunction()));

}

int SecWindow::on_pushButton_search2_clicked()
{
    word2 = ui->s2Txt->text();
    QTimer::singleShot(1000,this,SLOT(myFunction2()));
//    ui->s2Lbl->setText(QString(searchFunc2(ui->s2Txt->text())));
//    qDebug() << searchFunc2(ui->s2Txt->text());
}
int SecWindow::searchFunc(QString text){
    int counter = 0;
    QFile MyFile("/home/tarik/Masaüstü/TheLordOfTheRings");
    QThread::sleep(1);
    MyFile.open(QIODevice::ReadWrite);
    QTextStream in (&MyFile);
    QString content;
    while (!MyFile.atEnd()) {

            content = MyFile.readLine();
            if(content.contains(text))
            {
                counter++;
            }

        }
    MyFile.close();
    QString s = QString::number(counter);
    ui->s1Lbl->setText("Count : "  + s);
    return counter;
}

int SecWindow::searchFunc2(QString text){
    int counter = 0;
    QFile MyFile("/home/tarik/Masaüstü/TheLordOfTheRings");

    MyFile.open(QIODevice::ReadWrite);
    QTextStream in (&MyFile);
    QString content;
    while (!MyFile.atEnd()) {
            content = MyFile.readLine();
            if(content.contains(text))
            {
                counter++;

//                ui->s2Lbl->setText("Count: "+ QLocale().toString(counter));
            }

        }

    MyFile.close();
    QString s = QString::number(counter);
    ui->s2Lbl->setText("Count : "  + s);
    return counter;
}





//void SecWindow::myFunction(){
//    qDebug() << "Update...";
//}




//void WordCount::countSingleThreaded()
//  {
//      // Mark the application as active
//      m_active = true;
//      emit activeChanged();

//      // Start to measure the time
//      QTime time;
//      time.start();

//      // Count the words single threaded
//      const WordCountMap total = singleThreadedWordCount(m_files);

//      // Update the measured time
//      m_elapsedTime = time.elapsed();
//      emit elapsedTimeChanged();

//      // Accumulate the per-file word counts to the total word count
//      const QList<int> counts = total.values();
//      m_wordCount = std::accumulate(counts.begin(), counts.end(), 0);
//      emit wordCountChanged();

//      // Mark the application as inactive
//      m_active = false;
//      emit activeChanged();
//  }
//WordCountMap singleThreadedWordCount(const QStringList &files)
//    {
//        WordCountMap wordCount;

//        foreach (const QString &fileName, files) {
//            QFile file("/home/tarik/Masaüstü/TheLordOfTheRings");
//            file.open(QIODevice::ReadOnly);
//            QTextStream textStream(&file);
//            while (textStream.atEnd() == false) {
//                foreach(const QString &word, textStream.readLine().split(" "))
//                    wordCount[word] += 1;
//            }
//        }

//        return wordCount;
//    }


