#include "tcpclientsocket.h"


//������Ҫ���ڴ���ͻ��˵��¼�,�������ֿͻ������Ӻ����ӶϿ�ʱ���¼�����
TcpClientSocket::TcpClientSocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}


//�ۺ������ͻ��˷������ݵ������ʱ���ᴥ���˺���
void TcpClientSocket::dataReceived()
{
    while(bytesAvailable()>0) //������ݲ�Ϊ��
    {
        int length = bytesAvailable();
        char buf[2048];
        read(buf,length);

        QString msg=buf;
        emit updateClients(msg,length);//����updateClients�źţ��ѽ��յ���������Ϊ�źŵĲ������ݸ�Server���е�updateClients�ۺ���
    }
}

//�ۺ������ͻ���socket���ӶϿ�ʱ���ᴥ���˺���
void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());//����disconnected�źţ����ݸ�Server����slotDisconnected�ۺ���
}
