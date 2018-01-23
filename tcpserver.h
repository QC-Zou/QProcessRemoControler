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


//（1）初始化服务器端的界面；（2）创建服务器，初始化Server类，开始监听，建立server::updateServer信号,把收到的客户端数据作为参数，发给TcpServer::updateServer槽函数，后者负责服务器端界面显示接收到的客户端数据
//（3）当有客户端发送数据时会收到此信号，用于在服务器端界面显示接收到的客户端数据
class TcpServer : public QDialog
{
    Q_OBJECT
    
public:
    TcpServer(QWidget *parent = 0,Qt::WindowFlags f=0);//构造函数，用于初始化服务器端的界面，并连接创建按钮的点击信号和slotCreateServer槽函数
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
    void slotCreateServer();//槽函数，和CreateBtn按钮点击信号相连，用于创建服务器，初始化Server类，开始监听，建立server::updateServer信号,把收到的客户端数据作为参数，发给本类中的TcpServer::updateServer槽函数，后者负责服务器端界面显示接收到的客户端数据
    void updateServer(QString,int);//槽函数，Server类中的updateServer信号绑定，当有客户端发送数据时会收到此信号，用于在服务器端界面显示接收到的客户端数据
};

#endif // TCPSERVER_H
