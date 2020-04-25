#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>


#define FILE_LOG "./myfile.log"

int main()
{
  //log4cpp::Layout* layout =  new log4cpp::BasicLayout();
  
  // 1. 初始化一个pLayout 对象
  log4cpp::PatternLayout *pLayout = new log4cpp::PatternLayout();
  pLayout->setConversionPattern("%d: %p %c %x: %m%n");
  
   // 2. 初始化一个appender 对象
  log4cpp::Appender* appender = new log4cpp::FileAppender("FileAppender",FILE_LOG);
    // 3. 把layout对象附着在appender对象上
  appender->setLayout(pLayout);
  // 4. 实例化一个category对象
  log4cpp::Category& info_log = log4cpp::Category::getInstance("myinfo");
  // 5. 设置additivity为false，替换已有的appender
  info_log.setAdditivity(false);
  // 5. 把appender对象附到category上
  info_log.setAppender(appender);
  // 6. 设置category的优先级，低于此优先级的日志不被记录
  info_log.setPriority(log4cpp::Priority::INFO);
  // 记录一些日志
  info_log.info("test info log");
  info_log.debug("test debug log");//不会输出

  // 其他记录日志方式
  info_log.log(log4cpp::Priority::ERROR, "test error log");
  log4cpp::Priority::PriorityLevel priority;
  bool this_is_critical = true;
  if(this_is_critical)
       priority = log4cpp::Priority::CRIT;
  else
       priority = log4cpp::Priority::DEBUG;
  info_log.log(priority,"Set Priority::CRIT log");
        
  log4cpp::Category::shutdown();
  return 0;
}
