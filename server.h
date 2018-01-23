#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "tcpclientsocket.h"


//此Server类主要用于：（1）监听客户端连接；（2）把从客户端收到的数据分发给其他客户端；（3）发送updateServer信号，把从客户端收到的数据同时更新到服务器界面上；（4）把客户端断开的信息分发给其他客户端
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,int port=0);//（1）监听客户端连接；
    QList<TcpClientSocket*> tcpClientSocketList;
signals:
    void updateServer(QString,int);//（3)在void updateClients中发送updateServer信号，此信号对应的槽函数TcpServer::updateServer，把接收到的客户端数据发送给槽函数，把收到的数据同时更新到服务器界面上
public slots:
    void updateClients(QString,int);//（2）把从客户端收到的数据分发给其他客户端；
    void slotDisconnected(int);//（4）把客户端断开的信息分发给其他客户端
protected:
    void incomingConnection(int socketDescriptor);//此方法继承自QTcpServer类，当有新的连接时会触发
};

#endif // SERVER_H
