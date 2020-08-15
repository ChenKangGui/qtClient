#ifndef SMARTCLIENT_H
#define SMARTCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class SmartClient;
}

class SmartClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit SmartClient(QWidget *parent = 0);
    ~SmartClient();



private slots:
    void recv_data();
    void on_connect_btn_clicked();

    void on_Send_btn_clicked();

private:
    QTcpSocket *socketfd;

    Ui::SmartClient *ui;
};

#endif // SMARTCLIENT_H
