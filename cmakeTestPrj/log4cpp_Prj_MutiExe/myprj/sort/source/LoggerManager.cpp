#include"LoggerManager.h"
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/Priority.hh>

using namespace minilog;
using namespace std;

LoggerManager* LoggerManager::m_loggerManger = NULL;//root 节点
map<std::string,log4cpp::Category &> LoggerManager::mlogger={};
//int count=0;
//std::string LoggerManager::m_name="null";

//获取log指针
LoggerManager& LoggerManager::getInstance( std::string name){
    if ( m_loggerManger == NULL ) {
		m_loggerManger = new LoggerManager();
    }
	
	if(mlogger.find(name)!= mlogger.end())
	{
	}
	else
	{
		log4cpp::Category & m_Instance=log4cpp::Category::getRoot().getInstance(name);
		m_loggerManger->addLoggerCategory(m_Instance);
		mlogger.insert(pair<std::string,log4cpp::Category &>(name, m_Instance));
	}
	
    return *m_loggerManger;
}


//销毁
LoggerManager::~LoggerManager() {
    if (m_loggerManger) {
        m_loggerManger->m_root.info("LoggerManager destroy");
        m_loggerManger->m_root.shutdown();
        delete m_loggerManger;
    }
}

LoggerManager::LoggerManager(): 
    m_root(log4cpp::Category::getRoot()) {
		//    m_ref_(log4cpp::Category::getRoot()),m_root(m_ref_.getInstance(m_name))
	//m_root=m_ref_.getInstance(m_name);
    //自定义输出格式
    log4cpp::PatternLayout *pattern_one = new log4cpp::PatternLayout;
    pattern_one->setConversionPattern("%d{%Y-%m-%d,%H:%M:%S}: %p %c:%m%n");

	//pattern_one->setConversionPattern("%d{%Y-%m-%d,%H:%M:%S}: %p %c %x:%m%n");
	//%c 输出日志信息所属的类目，通常就是所在类的全名
    log4cpp::PatternLayout *pattern_two = new log4cpp::PatternLayout;
    pattern_two->setConversionPattern("%d{%Y-%m-%d,%H:%M:%S}: %p %c:%m%n");

    //获取屏幕输出
    log4cpp::OstreamAppender *os_appender = new log4cpp::OstreamAppender("osAppender",&std::cout);
    os_appender->setLayout(pattern_one);

    //获取文件日志输出 （ 日志文件名:mylog.txt )
    log4cpp::FileAppender *file_appender = new log4cpp::FileAppender("fileAppender","../logs/mylog.txt");
    file_appender->setLayout(pattern_two);

    setPriority(m_root,Priority::DEBUG);
    //m_root.addAppender(os_appender);
   // m_root.addAppender(file_appender);

    //info(m_root,"LoggerManager created!");
}


//构造函数
void LoggerManager::addLoggerCategory(log4cpp::Category &newCategory)
     {
		//    m_ref_(log4cpp::Category::getRoot()),m_root(m_ref_.getInstance(m_name))
	//m_root=m_ref_.getInstance(m_name);
    //自定义输出格式
    log4cpp::PatternLayout *pattern_one = new log4cpp::PatternLayout;
    pattern_one->setConversionPattern("%d{%Y-%m-%d,%H:%M:%S}: %p %c:%m%n");

	//pattern_one->setConversionPattern("%d{%Y-%m-%d,%H:%M:%S}: %p %c %x:%m%n");
	//%c 输出日志信息所属的类目，通常就是所在类的全名
    log4cpp::PatternLayout *pattern_two = new log4cpp::PatternLayout;
    pattern_two->setConversionPattern("%d{%Y-%m-%d,%H:%M:%S}: %p %c:%m%n");

    //获取屏幕输出
    log4cpp::OstreamAppender *os_appender = new log4cpp::OstreamAppender("osAppender",&std::cout);
    os_appender->setLayout(pattern_one);

    //获取文件日志输出 （ 日志文件名:mylog.txt )
    log4cpp::FileAppender *file_appender = new log4cpp::FileAppender("fileAppender","../logs/mylog.txt");
    file_appender->setLayout(pattern_two);

    setPriority(newCategory,Priority::DEBUG);
    newCategory.addAppender(os_appender);
    newCategory.addAppender(file_appender);

    //info(name,"LoggerManager created!");
	
}


//设置优先级
void LoggerManager::setPriority(log4cpp::Category &m,Priority priority) {
    switch (priority) {
        case (ERROR):
            m.setPriority(log4cpp::Priority::ERROR);
            break;
        case (WARN):
            m.setPriority(log4cpp::Priority::WARN);
            break;
        case (INFO):
            m.setPriority(log4cpp::Priority::INFO);
            break;
        case (DEBUG):
            m.setPriority(log4cpp::Priority::DEBUG);
            break;
        default:
            m.setPriority(log4cpp::Priority::DEBUG);
            break;    
    }
}


void LoggerManager::error(log4cpp::Category &m,const char* msg) {
    m.error(msg);
}

void LoggerManager::warn(log4cpp::Category &m,const char* msg) {
    m.warn(msg);
}

void LoggerManager::info(log4cpp::Category &m,const char* msg) {
    m.info(msg);
}

void LoggerManager::debug(log4cpp::Category &m,const char* msg) {
    m.debug(msg);
}
