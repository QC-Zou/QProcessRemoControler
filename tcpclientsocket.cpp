#include "tcpclientsocket.h"


//此类主要用于处理客户端的事件,包括出现客户端连接和连接断开时的事件处理
TcpClientSocket::TcpClientSocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}


//槽函数，客户端发送数据到服务端时，会触发此函数
void TcpClientSocket::dataReceived()
{
    while(bytesAvailable()>0) //如果数据不为空
    {
        int length = bytesAvailable();
        char buf[2048];
        read(buf,length);

        QString msg=buf;
        emit updateClients(msg,length);//发送updateClients信号，把接收到的数据作为信号的参数传递给Server类中的updateClients槽函数
    }
}

//槽函数，客户端socket连接断开时，会触发此函数
void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());//发送disconnected信号，传递给Server类中slotDisconnected槽函数
}
