#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "tcpclientsocket.h"


//��Server����Ҫ���ڣ���1�������ͻ������ӣ���2���Ѵӿͻ����յ������ݷַ��������ͻ��ˣ���3������updateServer�źţ��Ѵӿͻ����յ�������ͬʱ���µ������������ϣ���4���ѿͻ��˶Ͽ�����Ϣ�ַ��������ͻ���
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,int port=0);//��1�������ͻ������ӣ�
    QList<TcpClientSocket*> tcpClientSocketList;
signals:
    void updateServer(QString,int);//��3)��void updateClients�з���updateServer�źţ����źŶ�Ӧ�Ĳۺ���TcpServer::updateServer���ѽ��յ��Ŀͻ������ݷ��͸��ۺ��������յ�������ͬʱ���µ�������������
public slots:
    void updateClients(QString,int);//��2���Ѵӿͻ����յ������ݷַ��������ͻ��ˣ�
    void slotDisconnected(int);//��4���ѿͻ��˶Ͽ�����Ϣ�ַ��������ͻ���
protected:
    void incomingConnection(int socketDescriptor);//�˷����̳���QTcpServer�࣬�����µ�����ʱ�ᴥ��
};

#endif // SERVER_H
