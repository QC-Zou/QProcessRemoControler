#include "tcpserver.h"
#include "RetrieveHelper.h"


//构造函数，用于初始化服务器端的界面，并连接创建按钮的点击信号和slotCreateServer槽函数
TcpServer::TcpServer(QWidget *parent,Qt::WindowFlags f)
	: QDialog(parent,f)
{
	//setWindowTitle(tr("TCP Server"));

	//ContentListWidget = new QListWidget;

	/* PortLabel = new QLabel(tr("端口:"));
	PortLineEdit = new QLineEdit;*/

	//CreateBtn = new QPushButton(tr("create chat room"));


	port=10005;

	emit slotCreateServer();
}

TcpServer::~TcpServer()
{

}

//槽函数，和CreateBtn按钮点击信号相连，用于创建服务器，初始化Server类，开始监听，建立server：：updateServer信号用于把收到的客户端数据发给TcpServer::updateServer槽函数的连接，后者负责服务器端界面显示接收到的客户端数据
void TcpServer::slotCreateServer()
{
	server = new Server(this,port);//Server类构造函数中只有一条监听的语句，此时服务器开始监听客户端的连接
	//把server类中的updateServer信号和此类（TcpServer）中的updateServer方法连接。server：：updateServer信号用于把收到的客户端数据发给TcpServer::updateServer槽函数，后者负责服务器端界面显示接收到的客户端数据
	connect(server,SIGNAL( updateServer(QString,int)),this,SLOT(updateServer(QString,int)));

	// CreateBtn->setEnabled(false);
}


//用于在服务器端界面显示接收到的客户端数据
void TcpServer::updateServer(QString msg,int length)
{
	int i;
	char buf[532];
	char*  ch;
	ProcEntry entry;
	pProcEntry p;
	QByteArray ba = msg.toLatin1();    
    ch=ba.data();
    

	//把收到的数据加入到容器中，如果进程信息收完，则开始在界面中显示
	if(length)
	{
		memcpy(p,ch,532);

		entry.procName = p->procName;
	/*	entry.procId =  pe32.th32ProcessID;
		entry.ctThread = pe32.cntThreads;
		entry.procPid = pe32.th32ParentProcessID;
		entry.priorBase = pe32.pcPriClassBase;*/
		//如果接受完毕
		m_procList.push_back(entry);
	}
	else
	{
		emit receiveOver();
	}

	/*QListWidgetItem* lst1 = new QListWidgetItem("data", ContentListWidget);  
	ContentListWidget->insertItem(1, lst1);  */
	//ContentListWidget->addItem(msg.left(length));
}
