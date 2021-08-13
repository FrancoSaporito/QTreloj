#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    counter = 0;

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &MainWindow::onQTimer1);

    QPaintBox1 = new QPaintBox(0, 0, ui->widget);


}

MainWindow::~MainWindow()
{
    delete QTimer1;
    delete QPaintBox1;
    delete ui;
}

void MainWindow::onQTimer1(){
    QDateTime dt;


    QPen pen;
    QBrush brush;
    QPainter paint(QPaintBox1->getCanvas());

    int hour, minutes, seconds,mSec,w, h, radius,i,j,x;


    pen.setWidthF(6.75);


    w = QPaintBox1->width();
    h = QPaintBox1->height();


    radius = w/2;
    if(h < w)
        radius = h/2;


   ui->lineEdit->setText(dt.currentDateTime().toString("hh:mm:ss"));
   ui->lineEdit_2->setText(dt.currentDateTime().toString("dd/MM/yyyy"));

    hour = dt.currentDateTime().time().hour();
    minutes = dt.currentDateTime().time().minute();
    seconds = dt.currentDateTime().time().second();
    mSec = dt.currentDateTime().time().msec();

    pen.setColor(Qt::Key_LightBulb);
    paint.setPen(pen);
    brush.setColor(Qt::Key_LightBulb);
    brush.setStyle(Qt::SolidPattern);
    paint.setBrush(brush);
    paint.drawRoundRect(w/2-radius, h/2-radius, 2*radius, 2*radius);

    pen.setColor(Qt::Key_LightBulb);
    paint.setPen(pen);
    brush.setColor(Qt::white);
   // brush.setStyle(Qt::SolidPattern);
    paint.setBrush(brush);
    paint.drawEllipse(w/2-radius, h/2-radius, 2*radius, 2*radius);


     for(x=0;x<60;x++){

         i= w/2+qFloor((radius*15/16)*qCos((6*x-90)*2*M_PI/360));
         j= h/2+qFloor((radius*15/16)*qSin((6*x-90)*2*M_PI/360));
         pen.setWidthF(3);

         pen.setColor(Qt::black);
         paint.setPen(pen);
         paint.drawPoint(i,j);


     }
      pen.setWidthF(6.75);



    if(hour>12){
        hour=hour-12;
    }

    i= w/2+qFloor(70*qCos(((30*hour-90+0.5*minutes)*M_PI/180)+0.5));
    j= h/2+qFloor(70*qSin(((30*hour-90+0.5*minutes)*M_PI/180)+0.5));

    pen.setColor(Qt::red);
    paint.setPen(pen);
    paint.drawLine(w/2,h/2,i,j);
    paint.drawPoint(i,j);

    pen.setWidthF(4);

    i= w/2+qFloor(120*qCos((6*minutes-90+0.5*seconds)*M_PI/180)+0.5);

    j= h/2+qFloor(120*qSin((6*minutes-90+0.5*seconds)*M_PI/180)+0.5);


    pen.setColor(Qt::green);
    paint.setPen(pen);
    paint.drawLine(w/2,h/2,i,j);
    paint.drawPoint(i,j);

    pen.setWidthF(2);

    i= w/2+(160*qCos((6*seconds-90+mSec/150)*M_PI/180)+0.5);

    j= h/2+(160*qSin((6*seconds-90+mSec/150)*M_PI/180)+0.5);


    pen.setColor(Qt::black);
    paint.setPen(pen);
    paint.drawLine(w/2,h/2,i,j);
    paint.drawPoint(i,j);


     QPaintBox1->update();



}


void MainWindow::on_pushButton_clicked()
{

    QDateTime dt;


    if(QTimer1->isActive()){
        QTimer1->stop();
        ui->pushButton->setText("ON");


    }
    else{
       QTimer1->start(10);
        ui->pushButton->setText("OFF");
    }

    QPaintBox1->getCanvas()->fill(Qt::white);
    QPaintBox1->update();
}



