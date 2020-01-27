#ifndef __LOG_LOGGERMANAGER_H__
#define __LOG_LOGGERMANAGER_H__

#include<log4cpp/Category.hh>
#include<iostream>
#include<string>

namespace minilog{
//��־���ȼ�
enum Priority {
    ERROR,
    WARN,
    INFO,
    DEBUG
};

//�õ���ģʽ��װlog4cpp

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

		//���̲��򻯺���������ʽ
		#define logError(mlog,msg) mlog.error(suffix(msg))
		#define logWarn(mlog,msg) mlog.warn(suffix(msg))
		#define logInfo(mlog,msg) mlog.info(suffix(msg))
		#define logDebug(mlog,msg) mlog.debug(suffix(msg))
		
}
#endif //__LOG_LOGGERMANAGER_H__
