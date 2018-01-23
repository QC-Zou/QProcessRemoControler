#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>

//������Ҫ���ڴ���ͻ��˵��¼�,�������ֿͻ������Ӻ����ӶϿ�ʱ���¼�����
class TcpClientSocket : public QTcpSocket//ʵ��tcp�׽���
{
    Q_OBJECT
public:
    TcpClientSocket(QObject *parent=0);
signals:
    void updateClients(QString,int);//�źź�����
    void disconnected(int);
protected slots:
    void dataReceived();//�ۺ������ͻ��˷������ݵ������ʱ���ᴥ���˺���
    void slotDisconnected();//�ۺ������ͻ���socket���ӶϿ�ʱ���ᴥ���˺���
};

#endif // TCPCLIENTSOCKET_H
