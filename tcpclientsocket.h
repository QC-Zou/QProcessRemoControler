#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>

//此类主要用于处理客户端的事件,包括出现客户端连接和连接断开时的事件处理
class TcpClientSocket : public QTcpSocket//实现tcp套接字
{
    Q_OBJECT
public:
    TcpClientSocket(QObject *parent=0);
signals:
    void updateClients(QString,int);//信号函数，
    void disconnected(int);
protected slots:
    void dataReceived();//槽函数，客户端发送数据到服务端时，会触发此函数
    void slotDisconnected();//槽函数，客户端socket连接断开时，会触发此函数
};

#endif // TCPCLIENTSOCKET_H
