#include "server.h"


//��Server����Ҫ���ڣ���1�������ͻ������ӣ���2���Ѵӿͻ����յ������ݷַ��������ͻ��ˣ���3���ѿͻ��˶Ͽ�����Ϣ�ַ��������ͻ���
Server::Server(QObject *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}


//�������ӵ���ʱ��QTcpServer�ᴥ���˺�������Server��̳��˴��࣬�������յ����ź�
void Server::incomingConnection(int socketDescriptor)//socketDescriptorָ��������socket������
{
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this);

	//TcpClientSocket���źź�Server�еĲۺ�����
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));//���ź���TcpClientSocket::dataReceived()�з��������������ݵ���󷢳�
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));//���ź���TcpClientSocket::slotDisconnected()�з����������пͻ��˶Ͽ�����ʱ����

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    tcpClientSocketList.append(tcpClientSocket);
}


//slot�ۺ�������TcpClientSocket::dataReceived()�յ����ݲ�����֮���͵��˲ۺ������˺������ڰѴӿͻ����յ������ݷַ��������ͻ���
void Server::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);//����updateServer�źţ����źŶ�Ӧ�Ĳۺ���TcpServer::updateServer���ѽ��յ��Ŀͻ������ݷ��͸��ۺ���
   /* for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }*/
}

//slot�ۺ�������TcpClientSocket::slotDisconnected()�յ��Ͽ�����Ϣ�󷢰��źŷ��͵��˲ۺ������˺������ڰѿͻ��˶Ͽ�����Ϣ�ַ��������ͻ���
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
