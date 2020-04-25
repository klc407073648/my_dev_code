#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Category.hh>
int main() {
    // 1 读取解析配置文件
    // 读取出错, 完全可以忽略，可以定义一个缺省策略或者使用系统缺省策略
    // BasicLayout输出所有优先级日志到ConsoleAppender
    try
    {
        log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
    }
    catch (log4cpp::ConfigureFailure& f)
    {
        std::cout << "Configure Problem: " << f.what() << std::endl;
        return -1;
    }
    //2    实例化category对象
    //    这些对象即使配置文件没有定义也可以使用，不过其属性继承其父category
    //    通常使用引用可能不太方便，可以使用指针，以后做指针使用
    log4cpp::Category& root = log4cpp::Category::getRoot();
    log4cpp::Category& sample = log4cpp::Category::getInstance(std::string("sample"));
    log4cpp::Category& sample_son = log4cpp::Category::getInstance(std::string("sample.son"));
    log4cpp::Category& sample_daughter = log4cpp::Category::getInstance(std::string("sample.daughter"));
    
	//    正常使用这些category对象进行日志处理。
    root.fatal("root's log");
    
    sample.error("sample's log");
    
    sample_son.debug("sample.son's log");
   
    sample_daughter.debug("sample.daughter's log");
    
    return 0;
}
