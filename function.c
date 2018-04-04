//函数学习---多线程编程
@函数功能--------------
@函数原型--------------
@所属头文件------------
@返回值----------------
@参数说明--------------
//*************标准IO函数************************
1. fopen()
{
@函数功能--------------
打开文件流
@函数原型--------------
FILE *fopen(const char *path, const char *mode);
@所属头文件------------
#include <stdio.h>
@返回值----------------

@参数说明--------------
}

2.fclose()
{
@函数功能--------------
 关闭文件流
@函数原型--------------
 int fclose(FILE *fd);
@所属头文件------------
#include <stdio.h>
@返回值----------------
文件关闭成功返回0，失败返回EOF
@参数说明--------------
}

3.fread()
{
@函数功能--------------
对已打开文件流读操作
@函数原型--------------
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); 
@所属头文件------------
#include <stdio.h>
@返回值----------------
成功，返回实际读取的nmemb,失败返回EOF
@参数说明--------------
ptr 存放读入记录的缓存区
size 读取的记录大小
nmemb 读取的记录数
stream 要读取的文件流
}

4. fwrite()
{
@函数功能--------------
对已打开的文件流写入操作
@函数原型--------------
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
@所属头文件------------
#include <stdio.h>
@返回值----------------
成功返回值为实际要写入的nmemb,失败为EOF
@参数说明--------------
ptr 存放读入记录的缓存区
size 读取的记录大小
nmemb 读取的记录数
stream 要读取的文件流
}

5.字符输入输出
6.行输入输出
7.格式化输入输出

//**************文件IO编程类**********************
{
1.open()
{
@函数功能
用于打开或创建文件，并指定文件属性及用户权限
@函数原型--------------
int open(const char *pathname, int flags, mode_t mode);
@所属头文件----------------------
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
@返回值----------------
成功返回文件描述符， 失败返回-1
@参数说明--------------
*pathname 文件名或路径名
flags     文件打开方式
          O_RDONLY
          O_WRONLY
          O_RDWR   

}	
2.close()
{
@函数功能--------------
关闭打开的文件
@函数原型--------------
int close(int fd);
@所属头文件------------
#include <unistd.h>
@返回值----------------
成功返回0，失败返回-1
@参数说明--------------
fd 文件名或路径名
}

3.read()
{
@函数功能--------------
用于从指定文件描述符读出数据
@函数原型--------------
ssize_t read(int fd, void *buf, size_count);
@所属头文件------------
#include <unistd.h>
@返回值----------------
读取成功返回字节数，返回0表示到达文件尾，返回-1表示出错
@参数说明--------------	
fd: 文件描述符
*buf: 读出数据的缓冲区	
count：读出字节数
}

4.write()
{
@函数功能--------------
用于向打开的文件写入数据
@函数原型--------------
ssize_t write(int fd, const void *buf, size_t count);
@所属头文件------------
#include <unistd.h>
@返回值----------------
写成功返回字节数，失败返回-1
@参数说明--------------	

5.lseek()
{
@函数功能--------------
用于控制文件的读写位置
@函数原型--------------
off_t lseek(int fd, off_t offset, int whence);
@所属头文件------------
#include <sys/types.h> 
#include <unistd.h>
@返回值----------------
返回值若为字节数，表示文件的当前位移字节数， 若为-1，表示出错
@参数说明--------------
fd 文件描述符
offset 偏移量
whence 当前位置基点

}	
}

}
//**************进程编程类*****************************
{
1.fork()
{
@函数功能-------------
创建一个子进程
@函数原型-------------
pid_t fork(void);
@所属头文件
#include <unistd.h>
@返回值---------------
成功-在父进程中返回子进程PID，在子进程返回是0
失败-返回-1
@参数说明-------------
无参数
}

2.exec()函数族
{
@函数功能-------------
@函数原型-------------
int execl(const char *path, const char *arg,...);
int execlp(const char *file, const char *arg,...);
int execle(const char *path, const char *arg, char* const envp[]);
@所属头文件
#include <unistd.h>
extern char **environ;
@返回值-------------
@参数说明-------------
}

3._exit() exit() 
{
@函数功能-------------
_exit()函数直接终止进程，并清除内存空间
exit()函数在进程终止前，先检查文件的打开情况，并对文件缓存区的文件处理，然后终止进程
@函数原型-------------
#include <unistd.h>
void _exit(int status);

#include <stdlib.h>
void exit(int status);
@返回值-------------
无
@参数说明-------------
参数status一般是0，表示正常结束
}
//*******************************信号编程类***************************************
1. kill()
{
@函数功能--------------
kill()函数用于向自身或其他进程发送信号
@函数原型--------------
int kill(pid_t pid, int sig);
@所属头文件
#include <sys/types.h>
#include <signal.h>
@返回值----------------
执行成功返回0，如果有错误返回-1
@参数说明--------------
pid,进程号
pid > 0 要发送信号的进程号
pid = 0 信号被发送到与当前进程同一进程组的所有进程
pid =-1 信号发给所有进程表中的进程
pid <-1 信号发给进程组号为-pid的每个进程
sig: 要发送的信号
}

2.alarm()
{
@函数功能--------------
设置信号传送时钟
@函数原型--------------
unsigned int alarm(unsigned int seconds);
@所属头文件
#include <unistd.h>
@返回值----------------
返回之前闹钟的剩余秒数，如果之前未设置闹钟则返回0
@参数说明--------------
seconds 数字
}
}
//**************管道编程类****************************
{
1.pipe()
{
@函数功能--------------
创建无名管道pipe
@函数原型--------------
int pipe(int pipefd[2]);
@所属头文件
#include <unistd.h>
@返回值----------------
成功返回0 失败返回-1

@参数说明--------------
返回两个文件描述符
filedes[0] 读端
filedes[1] 写端
}

2.mkfifo()
{
@函数功能--------------
创建FIFO有名管道
@函数原型--------------
int mkfifo(const char *filename, mode_t mode)
@所属头文件
#include <sys/types.h>
#include <sys/state.h>
@返回值----------------
若函数调用成功，则返回0; 若函数调用失败，则返回-1
@参数说明--------------
--filename: 要创建的管道名称
--mode: 管道的访问权限
O_RDONLY 读管道 
O_WRONLY 写管道
O_RDWR   读写管道
O_NONBLOCK 非堵塞
O_CREAT  若管道不存在，则创建新文件
O_EXCL   若使用O_CREAT时，管道文件存在，则返回错误信息

示例：
mkfifo(my_fifo, O_WRONLY)
}


3.unlink()函数
{
@函数功能--------------
删除文件(管道)
@函数原型--------------
#include <unistd.h>
int unlink(const char* pathname);
@返回值----------------
成功返回0; 失败返回-1
@参数说明--------------
pathname 用来指明要删除的文件名字(含路径)
}
}
//**************信号量编程类***********************************
{

1.semget()函数
{
@函数功能--------------
创建或获得信号量
@函数原型--------------
int semget(key_t key, int nsems, int semflg);
@所属头文件
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
@返回值----------------
若调用成功，返回信号量表示符; 若调用失败， 则返回-1
@参数说明--------------
key--信号量键值，多个进程可以通过它访问同一个信号量， 通常为IPC_PRIVATE
创建当前进程的私有信号量
nsems--需要创建的信号量数目，通常为1
semflg--信号量操作权限
}


2.semctl()函数
{
@函数功能--------------
初始化信号量
@函数原型--------------
int semctl(int semid, int semnum, int cmd,...);
@所属头文件
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
@返回值----------------
调用成功，则根据cmd返回不同的值，调用失败，则返回-1
@参数说明--------------
semid--信号量ID
semnum 信号量编号
cmd    命令参数
-IPC_STAT
_IPC_SETVAl
IPC_CETVAL
IPC_RMID
}

3.semop()
{
@函数功能--------------
信号量操作函数
@函数原型--------------
int semop(int semid, struct sembuf* sops, unsigned nsops);
@所属头文件
#include <sys/types.h>
#include <sys/ipc.h>
#incldue <sys/sem.h>
@返回值----------------
调用成功，则返回信号量标识符，调用失败，返回-1
@参数说明--------------
sops:信号量操作数组  
nsops:sops的个数
}
}
//**************消息队列编程类**********************
{
1.msgget()
{
@函数功能--------------
创建或打开消息队列
@函数原型--------------
int msgget(key_t key, int msgflg);
@所属头文件
#include <sys/types.h>
#include <sys/ipc.h>
#incldue <sys/msg.h>
@返回值----------------
若调用成功，返回消息队列ID;
若调用失败，则返回-1

@参数说明--------------
key: 队列ID，取IPC_PRIVATE,创建当前进程私有的消息队列
msgflg: 权限标识位，IPC_CREAT创建
}	

2.msgsnd()
{
@函数功能--------------
用于把消息添加到消息队列中
@函数原型--------------
int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg);
@返回值----------------
调用成功，返回0，把消息的一个副本放到消息队列中;
调用失败，返回-1
@参数说明--------------	
msqid:
msgp:
msgsz:
}
}		

//**************共享内存编程类**********************
{
	
	
}
//**************多线程编程类**********************
{
1. pthread_create()
{
@函数功能--------------
创建一个线程
@函数原型--------------
int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr,
                   void *(*start_rtn)(void),void *restrict arg);
@所属头文件------------
#include <pthread.h>
@返回值----------------
线程创建成功返回0， 失败返回错误标识
@参数说明--------------
tidp 创建线程ID
attr 线程属性，NULL
start_rtn 起始地址
arg 传递给start_rtn参数
}	

2. pthread_exit()   pthread_join()  pthread_cancel()
@函数功能--------------
终止线程
@函数原型--------------
void pthread_exit(void *retval);
                  retval  调用线程的返回值     
int  pthread_join(pthread_t *th, void **thread_return); 
                  th 等待线程ID  thread_return 用来存储被等待线程的返回值
int  pthread_cancel(pthread_t tid);
                  tid 终止线程ID 
@所属头文件------------
#include <pthread.h>
@返回值----------------
@参数说明--------------

}
	
	