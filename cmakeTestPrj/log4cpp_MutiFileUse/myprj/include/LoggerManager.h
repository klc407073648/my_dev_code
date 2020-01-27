#ifndef __LOG_LOGGERMANAGER_H__
#define __LOG_LOGGERMANAGER_H__

#include<log4cpp/Category.hh>
#include<iostream>
#include<string>

namespace minilog{
//日志优先级
enum Priority {
    ERROR,
    WARN,
    INFO,
    DEBUG
};

//用单例模式封装log4cpp

		class LoggerManager {
		 public: 
			static LoggerManager& getInstance();
			void destory();

			void setPriority(Priority priority);
			void error(const char* msg);
			void warn(const char* msg);
			void info(const char* msg);
			void debug(const char* msg);
			LoggerManager();  
			//static void setName(std::string val) {m_name = val;}
		 private:
			static LoggerManager *plog_;
			log4cpp::Category &category_ref_; 
		};

		//*****************************************************
		//注意：
		//文件名 __FILE__ ,函数名 __func__ ，行号__LINE__ 是编译器实现的
		//并非C++头文件中定义的 
		//前两个变量是string类型，且__LINE__是整形，所以需要转为string类型
		//******************************************************

		//整数类型文件行号 ->转换为string类型
		inline std::string int2string(int line) {
			std::ostringstream oss;
			oss << line;
			return oss.str();
		}
		
		//整数类型文件行号 ->转换为string类型
		inline std::string flieNameSplit(std::string str) {
			std::string mStr=str;
			int begin=mStr.find_last_of('/');
			int end=mStr.find_last_of('.');
			return mStr.substr(begin+1,end-begin-1);
		}
		
		
		//定义一个在日志后添加 文件名 函数名 行号 的宏定义
		/* #define suffix(msg)  std::string(msg).append(" ##")\
				.append(__FILE__).append(":").append(__func__)\
				.append(":").append(int2string(__LINE__))\
				.append("##").c_str() */
				
		#define suffix(msg)  std::string(msg).append("(")\
				.append(flieNameSplit(__FILE__)).append(":").append(__func__)\
				.append(":").append(int2string(__LINE__))\
				.append(")").c_str()

		//缩短并简化函数调用形式
		#define logError(mlog,msg) mlog.error(suffix(msg))
		#define logWarn(mlog,msg) mlog.warn(suffix(msg))
		#define logInfo(mlog,msg) mlog.info(suffix(msg))
		#define logDebug(mlog,msg) mlog.debug(suffix(msg))
		
}
#endif //__LOG_LOGGERMANAGER_H__
