#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qpaintbox.h>
#include <QDateTime>
#include <QtMath>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*!
     * \brief onQTimer1
     *
     * Recibe la señal timeout de QTimer
     */
    void onQTimer1();

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;

    QTimer *QTimer1;
    QPaintBox *QPaintBox1;


    int counter,k,x,j,i;

};
#endif // MAINWINDOW_H
