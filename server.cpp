#include "server.h"


//此Server类主要用于：（1）监听客户端连接；（2）把从客户端收到的数据分发给其他客户端；（3）把客户端断开的信息分发给其他客户端
Server::Server(QObject *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}


//当有连接到达时，QTcpServer会触发此函数，而Server类继承了此类，所以能收到此信号
void Server::incomingConnection(int socketDescriptor)//socketDescriptor指定了连接socket描述符
{
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this);

	//TcpClientSocket的信号和Server中的槽函数绑定
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));//此信号在TcpClientSocket::dataReceived()中发出，即在有数据到达后发出
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));//此信号在TcpClientSocket::slotDisconnected()中发出，即在有客户端断开连接时发出

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    tcpClientSocketList.append(tcpClientSocket);
}


//slot槽函数，在TcpClientSocket::dataReceived()收到数据并处理之后发送到此槽函数，此函数用于把从客户端收到的数据分发给其他客户端
void Server::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);//发送updateServer信号，此信号对应的槽函数TcpServer::updateServer，把接收到的客户端数据发送给槽函数
   /* for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }*/
}

//slot槽函数，在TcpClientSocket::slotDisconnected()收到断开的信息后发把信号发送到此槽函数，此函数用于把客户端断开的信息分发给其他客户端
void Server::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
