/**
 * @file ThreadPool.h
 * @brief  线程池类定义
 * @author klc
 * @date 2020-03-15
 * @copyright Copyright (c) 2020年 klc
 */
 
#include <deque>  
#include <pthread.h>
#include <functional>      

namespace ThreadFunction
{	
	/**
	* @brief 线程池类
	*/
	class ThreadPool
	{
		public:
			/**
			 * @brief 定义处理任务函数的类型
			 */
			typedef std::function<void()> Task;

			/**
			* @brief 构造函数
			* @param[in] threadNum  线程池线程个数
			*/
			ThreadPool(const int threadNum = 10);
			
			/**
			* @brief 析构函数
			*/
			~ThreadPool();
			
			/**
			* @brief 添加处理任务到线程池
			* @param[in] task  线程任务的函数
			*/
			int addTask(const Task& task);
			
			/**
			* @brief 线程池终止函数
			*/
			void   stop();
			
			/**
			* @brief 线程池任务队列中taskQueue_的个数
			*/
			int    size();
			
			/**
			* @brief 线程池任务处理
			*/
			Task take();

        private:
			/**
			* @brief 创建线程
			*/
			int createThreads();
			
			/**
			* @brief 线程处理函数
			* @param[in] threadData  线程数据
			*/
			static void* threadFunc(void * threadData);

            /**
			* @brief 线程赋值函数
			* @param[in] ThreadPool  ThreadPool对象
			*/
			ThreadPool& operator=(const ThreadPool&);
			
			/**
			* @brief 线程拷贝函数
			* @param[in] ThreadPool  ThreadPool对象
			*/
			ThreadPool(const ThreadPool&);

			private:
				//volatile关键词影响编译器编译的结果，用volatile声明的变量表示该变量随时可能发生变化，与该变量有关的运算，不要进行编译优化，以免出错
				volatile  bool              isRunning_;
				int                         threadsNum_;
				pthread_t*                  threads_;

				std::deque<Task>            taskQueue_;
				pthread_mutex_t             mutex_;
				pthread_cond_t              condition_;
    };
}  
