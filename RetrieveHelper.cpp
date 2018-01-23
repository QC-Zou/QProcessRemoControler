#include "RetrieveHelper.h"
#include <WinError.h>
#include <tchar.h>

RetrieveHelper::RetrieveHelper(void)
{
	//setApplist();
	setProclist();
}

RetrieveHelper::~RetrieveHelper(void)
{

}

//void ParseProcessInfo(pProcEntry pRecBuffer)
//{
//	static int i=0;
//	int j;
//	int iCountOfProc = 0;
//
//	//如果接受到的进程名字段为空，则接收结束，打印所有进程名
//	if (lstrlen((LPCWSTR)pRecBuffer)==0)
//	{
//		iCountOfProc = i;
//		for(j = 0; j<iCountOfProc; j++)
//		{
//			_tprintf( TEXT("\n=====================================================\n" ));
//			_tprintf( TEXT("\n  PROCESS NAME:  %s"), pProlist[j]->procName );
//			_tprintf( TEXT("\n  Process ID        = 0x%08X"), pProlist[j]->procId );
//			_tprintf( TEXT("\n  Thread count      = %d"),   pProlist[j]->ctThread );
//			_tprintf( TEXT("\n  Parent process ID = 0x%08X"), pProlist[j]->procPid );
//			_tprintf( TEXT("\n  Priority base     = %d"), pProlist[j]->priorBase );
//			_tprintf( TEXT("\n  Priority class    = %d"), pProlist[j]->priorClass );
//			_tprintf( TEXT("\n  Path    = %s"), pProlist[j]->exePath );
//		}
//	}
//	else
//	{
//		pProlist[i] = (pProcEntry)malloc(sizeof(ProcEntry));
//		memset(pProlist[i], 0, sizeof(ProcEntry));
//		memcpy(pProlist[i],pRecBuffer,sizeof(ProcEntry));
//		i++;
//	}
//}


 /* Retrieve the list of process running
 */
void RetrieveHelper::setProclist()
{
	//static int i=0;
	//int j;
	//int iCountOfProc = 0;

	////如果接受到的进程名字段为空，则接收结束，打印所有进程名
	//if (lstrlen((LPCWSTR)pRecBuffer)==0)
	//{
	//	
	//	iCountOfProc = i;
	//	for(j = 0; j<iCountOfProc; j++)
	//	{
	//		/*_tprintf( TEXT("\n=====================================================\n" ));
	//		_tprintf( TEXT("\n  PROCESS NAME:  %s"), pProlist[j]->procName );
	//		_tprintf( TEXT("\n  Process ID        = 0x%08X"), pProlist[j]->procId );
	//		_tprintf( TEXT("\n  Thread count      = %d"),   pProlist[j]->ctThread );
	//		_tprintf( TEXT("\n  Parent process ID = 0x%08X"), pProlist[j]->procPid );
	//		_tprintf( TEXT("\n  Priority base     = %d"), pProlist[j]->priorBase );
	//		_tprintf( TEXT("\n  Priority class    = %d"), pProlist[j]->priorClass );
	//		_tprintf( TEXT("\n  Path    = %s"), pProlist[j]->exePath );*/
	//	}
	//}
	//else
	//{
	//
	//	//memset(Proclist,0,sizeof(Proclist));
	//	Proclist.procName = pRecBuffer->procName;
	//	Proclist.procId =  pRecBuffer->procId;
	//    Proclist.ctThread = pRecBuffer->ctThread;
	//    Proclist.procPid = pRecBuffer->procPid;
	//    Proclist.priorBase = pRecBuffer->priorBase;
	//    Proclist.priorClass = pRecBuffer->priorClass; 
	//	Proclist.exePath = pRecBuffer->exePath;
	//	m_procList.push_back(Proclist);
	//	i++;
	//}
		


}






