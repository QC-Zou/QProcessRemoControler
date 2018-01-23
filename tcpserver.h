#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "server.h"
#include "qapplist.h"


//��1����ʼ���������˵Ľ��棻��2����������������ʼ��Server�࣬��ʼ����������server::updateServer�ź�,���յ��Ŀͻ���������Ϊ����������TcpServer::updateServer�ۺ��������߸���������˽�����ʾ���յ��Ŀͻ�������
//��3�����пͻ��˷�������ʱ���յ����źţ������ڷ������˽�����ʾ���յ��Ŀͻ�������
class TcpServer : public QDialog
{
    Q_OBJECT
    
public:
    TcpServer(QWidget *parent = 0,Qt::WindowFlags f=0);//���캯�������ڳ�ʼ���������˵Ľ��棬�����Ӵ�����ť�ĵ���źź�slotCreateServer�ۺ���
    ~TcpServer();    
private:
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;
    int port;
    Server *server;
	vector<ProcEntry> m_procList;
signals:
		void receiveOver();
public slots:
    void slotCreateServer();//�ۺ�������CreateBtn��ť����ź����������ڴ�������������ʼ��Server�࣬��ʼ����������server::updateServer�ź�,���յ��Ŀͻ���������Ϊ���������������е�TcpServer::updateServer�ۺ��������߸���������˽�����ʾ���յ��Ŀͻ�������
    void updateServer(QString,int);//�ۺ�����Server���е�updateServer�źŰ󶨣����пͻ��˷�������ʱ���յ����źţ������ڷ������˽�����ʾ���յ��Ŀͻ�������
};

#endif // TCPSERVER_H
