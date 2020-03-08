/**
 * @file LoggerManager.h
 * @brief ��־ģ���װ
 * @author klc
 * @date 2020-03-01
 * @copyright Copyright (c) 2020�� klc
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
	 * @brief ��־���ȼ�
	 */
	enum Priority {
		ERROR,
		WARN,
		INFO,
		DEBUG
	};
	
	/**
	 * @brief ��־������
	 */
	class LoggerManager {
		 public: 
			/**
			 * @brief ���캯��
			 */
			LoggerManager(); 
			
			/**
			 * @brief ��������
			 * @param[in] newCategory    �����������
			 */
			~LoggerManager();
			
			/**
			 * @brief �������ȼ�
			 * @param[in] m         ��־����������
			 * @param[in] priority  ���ȼ�
			 */
			void setPriority(log4cpp::Category &m,Priority priority);
			
			/**
			 * @brief дerror������־
			 * @param[in] m 	��־����������
			 * @param[in] msg   �����Ϣ
			 */
			void error(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief дwarn������־
			 * @param[in] m    ��־����������
			 * @param[in] msg  �����Ϣ
			 */
			void warn(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief дinfo������־
			 * @param[in] m    ��־����������
			 * @param[in] msg  �����Ϣ
			 */
			void info(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief дdebug������־
			 * @param[in] m    ��־����������
			 * @param[in] msg  �����Ϣ
			 */
			void debug(log4cpp::Category &m,const char* msg);
			
			/**
			 * @brief ���������������
			 * @param[in] newCategory    �����������
			 */
			void addLoggerCategory(log4cpp::Category &newCategory); 
			
			/**
			 * @brief ��ʼ��ʵ������
			 * @param[in] name  ����
			 */
			static LoggerManager& getInstance(std::string name="null");
			
			/**
			 * @brief ��ȡ��־����������
			 */
			//static std::string getName() {return logName;}
			
			/**
			 * @brief ��ȡ��־���������ָ��
			 */
			static LoggerManager * getLoggerManager() {return m_loggerManger;}
			
			/**
			 * @brief ��ȡ��־������ʵ��
			 */
			static map<std::string,log4cpp::Category &> getLogger() {return mlogger;}
			
		 private:
			/// ��־�����������map����
			static map<std::string,log4cpp::Category &> mlogger;
			/// ��־���������ָ��
			static LoggerManager *m_loggerManger;
			/// ����־��
			log4cpp::Category& m_root; 
			//static std::string logName;
			//static int count;

		};

		//*****************************************************
		//ע�⣺
		//�ļ��� __FILE__ ,������ __func__ ���к�__LINE__ �Ǳ�����ʵ�ֵ�
		//����C++ͷ�ļ��ж���� 
		//ǰ����������string���ͣ���__LINE__�����Σ�������ҪתΪstring����
		//******************************************************

		//���������ļ��к� ->ת��Ϊstring����
		inline std::string int2string(int line) {
			std::ostringstream oss;
			oss << line;
			return oss.str();
		}
		
		//���������ļ��к� ->ת��Ϊstring����
		inline std::string flieNameSplit(std::string str) {
			std::string mStr=str;
			int begin=mStr.find_last_of('/');
			int end=mStr.find_last_of('.');
			return mStr.substr(begin+1,end-begin-1);
		}
		
		
		//����һ������־����� �ļ��� ������ �к� �ĺ궨��
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
		
		//���̲��򻯺���������ʽ
		#define logError(mlog,msg) 	logError(mlog,suffix(msg))
		#define logWarn(mlog,msg) 	logWarn(mlog,suffix(msg))
		#define logInfo(mlog,msg) 	logInfo(mlog,suffix(msg))
		#define logDebug(mlog,msg) 	logDebug(mlog,suffix(msg))
		
		#define CREATE_LOGGERMANAGER(_class)  LoggerManager::getInstance(#_class)
				
}



#endif //__LOG_LOGGERMANAGER_H__
