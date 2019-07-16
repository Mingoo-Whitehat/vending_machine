#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbGongcha->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
}


Widget::~Widget()
{
    delete ui;

}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    //QMessageBox msg;
    //msg.information(nullptr, "title", "text");

    if(money < 200)
        ui->pbGongcha->setEnabled(false);
    else
        ui->pbGongcha->setDisabled(false);

    if(money < 150)
        ui->pbTea->setEnabled(false);
    else
        ui->pbTea->setDisabled(false);

    if(money < 100)
        ui->pbCoffee->setEnabled(false);
    else
        ui->pbCoffee->setDisabled(false);
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

void Widget::on_pbShowMeTheMoney_clicked()
{
    QMessageBox msg;

    int won[4] = {0};

    won[0] = money/500;
    money = money - 500*won[0];

    won[1] = money/100;
    money = money - 100*won[1];

    won[2] = money/50;
    money = money - 50*won[2];

    won[3] = money/10;
    money = money - 10*won[3];

    QString::number(won[0]);
    QString::number(won[1]);
    QString::number(won[2]);
    QString::number(won[3]);

    msg.information(nullptr, "your money :D", "500won:"+QString::number(won[0])+"\n100won:"+QString::number(won[1])+"\n50won:"+QString::number(won[2])+"\n10won:"+QString::number(won[3]));

    ui->lcdNumber->display(QString::number(money));
    ui->pbGongcha->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
}
