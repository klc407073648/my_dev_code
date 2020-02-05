- 信号的概念

```
共性：1. 简单 2. 不能携带大量信息3. 满足某个特设条件才发送。
机制：
由于信号是通过软件方法实现，其实现手段导致信号有很强的延时性。
每个进程收到的所有信号，都是由内核负责发送的，内核处理。
```

- 信号的产生

1. 按键产生，如：Ctrl+c、Ctrl+z、Ctrl+\
2. 系统调用产生，如：kill、raise、abort
3. 软件条件产生，如：定时器alarm
4. 硬件异常产生，如：非法访问内存(段错误)、除0(浮点数例外)、内存对齐出错(总线错误)
5. 命令产生，如：kill命令

- 信号的处理方式: 
1. 执行默认动作 
2. 忽略(丢弃) 
3. 捕捉(调用户处理函数)


```
阻塞信号集(信号屏蔽字)：
将某些信号加入集合，对他们设置屏蔽，当屏蔽x信号后，再收到该信号，该信号的处理将推后(解除屏蔽后)。

未决信号集: 
1. 信号产生，未决信号集中描述该信号的位立刻翻转为1，表信号处于未决状态。当信号被处理对应位翻转回为0。这一时刻往往非常短暂。 
2. 信号产生后由于某些原因(主要是阻塞)不能抵达。这类信号的集合称之为未决信号集。在屏蔽解除前，信号一直处于未决状态。
```

信号四要素：
1. 编号 2. 名称 3. 事件 4. 默认处理动作 

- kill函数/命令产生信号
```
int kill(pid_t pid, int sig);//给指定进程发送指定信号
int raise(int sig);//给当前进程发送指定信号 raise(signo) == kill(getpid(), signo);
void abort(void); //给自己发送异常终止信号 6) SIGABRT 信号，终止并产生core文件
```

- 软件条件产生信号
```
unsigned int alarm(unsigned int seconds);//返回0或剩余的秒数，无失败。
int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
//设置定时器(闹钟)。 可代替alarm函数。精度微秒us，可以实现周期定时。
```

- 信号集操作函数

内核通过读取未决信号集来判断信号是否应被处理。信号屏蔽字mask可以影响未决信号集。而我们可以在应用程序中自定义set来改变mask。已达到屏蔽指定信号的目的。
```
信号集设定
	sigset_t  set;		// typedef unsigned long sigset_t; 
    int sigemptyset(sigset_t *set);			        将某个信号集清0		 		成功：0；失败：-1
    int sigfillset(sigset_t *set);				    将某个信号集置1		  		成功：0；失败：-1
    int sigaddset(sigset_t *set, int signum);		将某个信号加入信号集  		成功：0；失败：-1
    int sigdelset(sigset_t *set, int signum);		将某个信号清出信号集   		成功：0；失败：-1
    int sigismember(const sigset_t *set, int signum);判断某个信号是否在信号集中	返回值：在集合：1；不在：0；出错：-1  

处理函数：
sigprocmask函数：用来屏蔽或解除屏蔽信号。其本质，读取或修改进程的信号屏蔽字(PCB中)。
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);	成功：0；失败：-1，
how:SIG_BLOCK;SIG_UNBLOCK;SIG_SETMASK (屏蔽，解除屏蔽，新屏蔽集)，oldset为旧的信号屏蔽集。
调用sigprocmask(SIG_SETMASK, &oldmask, NULL);来恢复原先的信号屏蔽集。

sigpending函数：读取当前进程的未决信号集
int sigpending(sigset_t *set);	set传出参数。   返回值：成功：0；失败：-1，设置errno

信号捕捉函数：
signal函数：注册一个信号捕捉函数。
typedef void (*sighandler_t)(int);  //去掉typedef,即定义了一个函数指针，指向的函数接受一个整型参数并返回一个无类型指针
sighandler_t signal(int signum, sighandler_t handler);

sigaction函数：修改信号处理动作（通常在Linux用其来注册一个信号的捕捉函数）
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); 


```

