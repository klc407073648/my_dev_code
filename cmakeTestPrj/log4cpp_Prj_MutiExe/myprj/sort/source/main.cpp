#include"sort.h"
#include"randomArray.h"
#include"LoggerManager.h"

using namespace algorithm::sort;
using namespace std;
using namespace minilog;
using namespace std;
//CREATE_LOG(MAIN);
int main()
{
	//randomArray m_randomArray;
	//m_randomArray.myTest();
	
	Sort mysort;
	//CREATE_LOG(MAIN);
	LoggerManager::getInstance("MAIN11");
	map<std::string,log4cpp::Category &>::iterator iter;
	
	for(iter = LoggerManager::getLogger().begin();iter!= LoggerManager::getLogger().end();iter++)
	{
		cout<<"size:"<<LoggerManager::getLogger().size()<<endl;//还待解决  不加这一句 后续logError不输出
		//cout<<"________________"<<endl;
		if( iter->first == "MAIN11")
		{
			logError(iter->second,"main Func Test");
			break;
		}
	}
	//logError(LoggerManager::getLogger("MAIN11"),"main Func Test");
	//LoggerManager* my_LoggerManager=new LoggerManager();
	return 0;
}