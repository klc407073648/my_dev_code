- 终端
```
所有输入输出设备的总称。
Alt + Ctrl + F1、F2、F3、F4、F5、F6	字符终端   pts (pseudo terminal slave) 指伪终端。
Alt + F7		图形终端
SSH、Telnet...		网络终端
```

- 终端的启动流程

简单来说，一个Linux系统启动，大致经历如下的步骤：
init --> fork --> exec --> getty --> 用户输入帐号 --> login --> 输入密码 --> exec --> bash

- 进程组

```
进程组操作函数
getpgrp函数：获取当前进程的进程组ID
pid_t getpgrp(void); 
getpgid函数：获取指定进程的进程组ID
pid_t getpgid(pid_t pid);	 成功：0；失败：-1，设置errno
setpgid函数：改变进程默认所属的进程组。通常可用来加入一个现有的进程组或创建一个新进程组。
int setpgid(pid_t pid, pid_t pgid); 	成功：0；失败：-1，设置errno

```

- 会话

```
getsid函数：获取进程所属的会话ID
pid_t getsid(pid_t pid); 成功：返回调用进程的会话ID；失败：-1，设置errno

setsid函数：创建一个会话，并以自己的ID设置进程组ID，同时也是新会话的ID。
pid_t setsid(void);  成功：返回调用进程的会话ID；失败：-1，设置errno

```

- 守护进程

```
Daemon(精灵)进程，是Linux中的后台服务进程，通常独立于控制终端并且周期性地执行某种任务或等待处理某些发生的事件。一般采用以d结尾的名字。例如httpd,sshd,vsftpd等。

创建守护进程模型
1.	创建子进程，父进程退出
所有工作在子进程中进行形式上脱离了控制终端
2.	在子进程中创建新会话
　　	setsid()函数
　　	使子进程完全独立出来，脱离控制
3.	改变当前目录为根目录
　　	chdir()函数
　　	防止占用可卸载的文件系统
　　	也可以换成其它路径
4.	重设文件权限掩码
　　	umask()函数
　　	防止继承的文件创建屏蔽字拒绝某些权限
　　	增加守护进程灵活性
5.	关闭文件描述符
　　	继承的打开文件不会用到，浪费系统资源，无法卸载
6.	开始执行守护进程核心工作
7.	守护进程退出处理程序模型	
```
