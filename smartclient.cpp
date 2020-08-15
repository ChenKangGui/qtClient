#include "smartclient.h"
#include "ui_smartclient.h"
#include <QHostAddress>

SmartClient::SmartClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmartClient)
{
    ui->setupUi(this);

    socketfd = new QTcpSocket(this);
}

SmartClient::~SmartClient()
{
    delete ui;
}

void SmartClient::recv_data()
{
    QByteArray data = socketfd->readAll();

    ui->recv_label->setText(data);
}



void SmartClient::on_connect_btn_clicked()
{
    QString ip = ui->ip_label->text();
    int   port = ui->Port_label->text().toInt();

    socketfd->connectToHost(ip, port, QTcpSocket::ReadWrite);
    if(socketfd->waitForConnected())
    {
        qDebug() << "success";
        connect(socketfd, SIGNAL(readyRead()), this, SLOT(recv_data()));
        ui->connect_btn->setVisible(false);
        QString ip = (socketfd->peerAddress()).toString();
        qDebug() << ip;
    }
    else
    {
        qDebug() << "connect fail";
    }
}

void SmartClient::on_Send_btn_clicked()
{
    char buf[1024] = {0};
    QString data = ui->send_label->toPlainText();

    strcpy_s(buf, data.toStdString().c_str());
    socketfd->write(buf, strlen(buf));
}
