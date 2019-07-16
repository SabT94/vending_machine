#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbGongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }else{
        ui->pbCoffee->setEnabled(false);
    }
    if(money>=150){
        ui->pbTea->setEnabled(true);
    }else{
        ui->pbTea->setEnabled(false);
    }
    if(money>=200){
        ui->pbGongcha->setEnabled(true);
    }else{

        ui->pbGongcha->setEnabled(false);
    }
}
void Widget::messageBoxOutput(int n){
    int buf[4]={0};
    if(n>=500){
        buf[0]=n/500;
        n = n%500;
    }
    if(n>=100){
        buf[1]=n/100;
        n = n%100;
    }
    if(n>=50){
        buf[2]=n/50;
        n = n%50;
    }

    buf[3]=n/10;
    n = n%10;
    QString str500 = QString::number(buf[0]);
    QString str100 = QString::number(buf[1]);
    QString str50 = QString::number(buf[2]);
    QString str10 = QString::number(buf[3]);
    QString str = QString("500 = %1 100 = %2 50 = %3 10 = %4").arg(str500).arg(str100).arg(str50).arg(str10);
    QMessageBox msg;
    msg.information(nullptr,"return money",str);
    money=0;
    ui->lcdNumber->display(QString::number(money));
    exit(false);
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_re_money_clicked()
{
    messageBoxOutput(money);
}
