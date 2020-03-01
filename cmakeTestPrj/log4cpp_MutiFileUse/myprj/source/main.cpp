#include"sort.h"
#include"randomArray.h"
#include"LoggerManager.h"

using namespace algorithm::sort;
using namespace std;
using namespace minilog;


int main()
{
	//randomArray m_randomArray;
	//m_randomArray.myTest();
	
	Sort* mysort= new Sort();

	LoggerManager &mlog = LoggerManager::getInstance("Main");
	logError(mlog,"main Func Test");
	//LoggerManager* my_LoggerManager=new LoggerManager();
	return 0;
}