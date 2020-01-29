- 程序与进程

1. 程序，是指编译好的二进制文件，在磁盘上，不占用系统资源(cpu、内存、打开的文件、设备、锁....)。
2. 进程，是一个抽象的概念，与操作系统原理联系紧密。进程是活跃的程序，占用系统资源。在内存中执行。(程序运行起来，产生一个进程)

- 并发
    
 并发，在操作系统中，一个时间段中有多个进程都处于已启动运行到运行完毕之间的状态。但，任一个时刻点上仍只有一个进程在运行。

1. 单道程序设计：所有进程排队执行。
2. 多道程序设计：多个进程分时复用CPU资源（利用时钟中断，硬件实现）。

<html>  <!-- src中自然就是你刚刚复制的url外链 -->
        <img src = "https://github.com/klc407073648/my_dev_code/blob/master/md_image/CPUandMMU.JPG?raw=true"/>
</html>


MMU：内存管理单元，1-3G为用户区user，3-4G为内核区kernel；
两个a.out对应user通过MMU映射到物理内存上的不同位置，且最小单位page为4K，
对应kernel映射到同一个位置，即同用一块内存空间，但是两个PCB不一致。

我们在程序中使用的都是虚拟内存，由MMU完成虚拟内存与物理内存的映射关系。
<html>  <!-- src中自然就是你刚刚复制的url外链 -->
        <img src = "https://github.com/klc407073648/my_dev_code/blob/master/md_image/MMU.jpg?raw=true"/>
</html>

- 进程控制块PCB

每个进程在内核中都有一个进程控制块（PCB）来维护进程相关的信息，Linux内核的进程控制块是task_struct结构体

```
* 进程id。系统中每个进程有唯一的id，在C语言中用pid_t类型表示，其实就是一个非负整数。
* 进程的状态，有就绪、运行、挂起、停止等状态。
* 进程切换时需要保存和恢复的一些CPU寄存器。
* 描述虚拟地址空间的信息。
* 描述控制终端的信息。
* 当前工作目录（Current Working Directory）。
* umask掩码。
* 文件描述符表，包含很多指向file结构体的指针。
* 和信号相关的信息。
* 用户id和组id。
* 会话（Session）和进程组。
* 进程可以使用的资源上限（Resource Limit）。
```
- 进程状态

进程基本的状态有5种。分别为初始态，就绪态，运行态，挂起态与终止态。
<html>  <!-- src中自然就是你刚刚复制的url外链 -->
        <img src = "https://github.com/klc407073648/my_dev_code/blob/master/md_image/PCB_state.JPG?raw=true"/>
</html>
- 进程控制

	注意返回值，不是fork函数能返回两个值，而是fork后，fork函数变为两个，父子需【各自】返回一个。

1. 创建子进程

```
#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
 cout<<"Test Func begin!"<<endl;
 pid_t m_pid;
 m_pid= fork();

 if(m_pid == -1)
{
  perror("fork fail.");
}
 else if(m_pid == 0)
{
  cout<<"I'm child "<<"id:"<<getpid()<<" ppid:"<<getppid()<<endl;
}
 else if(m_pid > 0)
{
  cout<<"I'm parent "<<"id:"<<getpid()<<" ppid:"<<getppid()<<" childID:"<<m_pid<<endl;
  sleep(2);
}

 cout<<"fork end"<<endl;

 return 0;
}


```

2. 循环创建子进程

```
#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
   cout<<"Test Func begin!"<<endl;
   pid_t m_pid;
   int i;
   for(i=0;i<5;i++)
   {
	  m_pid= fork();
	  if( m_pid == 0)
		 break;
   }
    sleep(i);
	if( i < 5)
	{
	   cout<<"I'm child "<<i<<" id:"<<getpid()<<endl;
	}
	else
	{
	   cout<<"I'm parent "<<" id:"<<getpid()<<endl;
	   cout<<"Test Func end!"<<endl;
	}

 return 0;
}

```

- 进程共享

刚fork之后：
1. 父子相同处: 全局变量、.data、.text、栈、堆、环境变量、用户ID、宿主目录、进程工作目录、信号处理方式...
2. 父子不同处: 1.进程ID   2.fork返回值   3.父进程ID    4.进程运行时间     5.闹钟(定时器)   6.未决信号集
3. 似乎，子进程复制了父进程0-3G用户空间内容，以及父进程的PCB，但pid不同。真的每fork一个子进程都要将父进程的0-3G地址空间完全拷贝一份，然后在映射至物理内存吗？

注意：父子进程间遵循读时共享写时复制的原则。

父子进程共享：1. 文件描述符(打开文件的结构体)  2. mmap建立的映射区 (进程间通信详解)

- exec函数族	

fork创建子进程后执行的是和父进程相同的程序（但有可能执行不同的代码分支），子进程往往要调用一种exec函数以执行另一个程序。当进程调用一种exec函数时，该进程的用户空间代码和数据完全被新程序替换，从新程序的启动例程开始执行。

exec函数一旦调用成功即执行新的程序，不返回。只有失败才返回，错误值-1。所以通常我们直接在exec函数调用后直接调用perror()和exit()，无需if判断。
```
常用的如下：
execlp("ls", "ls", "-l", "-F", NULL);	     使用程序名在PATH中搜索。
execl("/bin/ls", "ls", "-l", "-F", NULL);    使用参数1给出的绝对路径搜索。
```

- 孤儿进程

孤儿进程: 父进程先于子进程结束，则子进程成为孤儿进程，子进程的父进程成为init进程，称为init进程领养孤儿进程。

- 僵尸进程

僵尸进程: 进程终止，父进程尚未回收，子进程残留资源（PCB）存放于内核中，变成僵尸（Zombie）进程。（需要杀死父进程进行回收）

- wait函数

```
父进程调用wait函数可以回收子进程终止信息。该函数有三个功能：
① 阻塞等待子进程退出 
② 回收子进程残留资源 
③ 获取子进程结束状态(退出原因)。
    pid_t wait(int *status); 	成功：清理掉的子进程ID；失败：-1 (没有子进程)
```

- waitpid函数

```
pid_t waitpid(pid_t pid, int *status, in options);	成功：返回清理掉的子进程ID；失败：-1(无子进程)
特殊参数和返回情况：
参数pid： 
> 0 回收指定ID的子进程	
-1 回收任意子进程（相当于wait）
0 回收和当前调用waitpid一个组的所有子进程
< -1 回收指定进程组内的任意子进程

参2：状态。

参3: 0:  (wait) 阻塞回收
     WNOHANG:   非阻塞回收   (轮询)

返回值:   成功: pid  失败:-1     返回0值:   参3传WNOHANG, 并且子进程尚未结束
```


