/**
 * @file LoggerManager.h
 * @brief 日志模块封装
 * @author klc
 * @date 2020-03-01
 * @copyright Copyright (c) 2020年 klc
 */


#ifndef __LOG_LOGGERMANAGER_H__
#define __LOG_LOGGERMANAGER_H__

#include<log4cpp/Category.hh>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

namespace minilog{
	/**
	 * @brief 日志优先级
	 */
	enum Priority {
		ERROR,
		WARN,
		INFO,
		DEBUG
	};
	
	/**
	 * @brief 日志管理类
	 */
	class LoggerManager {
		 public: 
			/**
			 * @brief 构造函数
			 */
			LoggerManager(); 
			
			/**
			 * @brief 析构函数
			 * @param[in] newCategory    新增对象类别
			 */
			~LoggerManager();
			
			/**
			 * @brief 设置优先级
			 * @param[in] m         日志输出对象类别
			 * @param[in] priority  优先级
			 */
			void setPriority(log4cpp::Category &m,Priority priority);
			
			/**
			 * @brief 写error级别日志
			 * @param[in] m 	日志输出对象类别
			 * @param[in] msg   输出消息
			 */
			void error(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief 写warn级别日志
			 * @param[in] m    日志输出对象类别
			 * @param[in] msg  输出消息
			 */
			void warn(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief 写info级别日志
			 * @param[in] m    日志输出对象类别
			 * @param[in] msg  输出消息
			 */
			void info(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief 写debug级别日志
			 * @param[in] m    日志输出对象类别
			 * @param[in] msg  输出消息
			 */
			void debug(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief 新增输出对象类型
			 * @param[in] newCategory    新增对象类别
			 */
			void addLoggerCategory(log4cpp::Category &newCategory); 
			
			/**
			 * @brief 初始化实例对象
			 * @param[in] name  名称
			 */
			static LoggerManager& getInstance(std::string name="null");
			
			/**
			 * @brief 获取日志管理类名称
			 */
			//static std::string getName() {return logName;}
			
			/**
			 * @brief 获取日志管理类对象指针
			 */
			static LoggerManager * getLoggerManager() {return m_loggerManger;}
			
			/**
			 * @brief 获取日志管理类实例
			 */
			static map<std::string,log4cpp::Category &> getLogger() {return mlogger;}
			
		 private:
			/// 日志输出对象类型map集合
			static map<std::string,log4cpp::Category &> mlogger;
			/// 日志管理类对象指针
			static LoggerManager *m_loggerManger;
			/// 主日志器
			log4cpp::Category& m_root; 
			//static std::string logName;
			//static int count;

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


		inline void logWarn(log4cpp::Category &m,const char* msg) {
			LoggerManager::getLoggerManager()->warn(m,msg);

		}

		inline void logError(log4cpp::Category &m,const char* msg) {
			//LoggerManager& plog = LoggerManager::getInstance();
			LoggerManager::getLoggerManager()->error(m,msg);

		}

		inline void logInfo(log4cpp::Category &m,const char* msg) {
			LoggerManager::getLoggerManager()->info(m,msg);

		}

		inline void logDebug(log4cpp::Category &m,const char* msg) {
			LoggerManager::getLoggerManager()->debug(m,msg);
		} 
		
		//缩短并简化函数调用形式
		#define logError(mlog,msg) 	logError(mlog,suffix(msg))
		#define logWarn(mlog,msg) 	logWarn(mlog,suffix(msg))
		#define logInfo(mlog,msg) 	logInfo(mlog,suffix(msg))
		#define logDebug(mlog,msg) 	logDebug(mlog,suffix(msg))
		
		#define CREATE_LOGGERMANAGER(_class)  LoggerManager::getInstance(#_class)
				
}



#endif //__LOG_LOGGERMANAGER_H__
