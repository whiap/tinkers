# Advanced Linux Programming

## Chapter01. Getting Started
* gdb demo
* code -> reciprocal

## Chapter02. Writing Good GNU/LINUX Software
* code -> basis
* `gcc -c -fPIC test1.c test2.c`
* `gcc -shared -fPIC -o libtest.so test1.o test2.o`
* `gcc -o app app.o -L. –ltest`

* using static instead of dynamic: `gcc -static -o app app.o -L. –ltest` 
* using dynamic library:  `gcc -o app app.o -L. -ltest -Wl,-rpath,/usr/local/lib`
* or using `LD_LIBRARY_PATH`

## Chapter03. Processes
* code -> process
* exec函数族
* 调整优先级
    * `nice -n 10 COMMAND-LINE`
    * `renice`
* 使用kill方法进行信号通知 
    * `kill -KILL pid`
    * `kill(pid, SIGTERM)`
* 进程退出编码应该是0–127，128+是留给128+信号数值进行标识的

## Chapter04. Threads
* code -> thread
* code -> thread -> create1 & create2
* code -> thread -> primers
* code -> thread -> detached
* code -> thread -> critical-section
* code -> thread -> tsd (thread specific data)
* code -> thread -> cleanup & cxx techniques
* code -> thread -> race condition
    * job-queue1.c: Thread Function to Process Jobs from the Queue <BUGGY>
    * job-queue2.c: Job Queue Thread Function, Protected by a Mutex
    * job-queue3.c: Job Queue Controlled by a Semaphore
* code -> thread -> condition variables
    * spin-condvar.c:  A Simple Condition Variable Implementation
    * condvar.c: Control a Thread Using a Condition Variable
    > 1. The loop in thread_function locks the mutex and reads the flag value.
    > 2. If the flag is set, it unlocks the mutex and executes the work function.
    > 3. If the flag is not set, it atomically unlocks the mutex and waits on the condition variable.
    * NOTE: `pthread_cond_wait` when it is called, the mutex must already be locked by the calling thread. That function atomically unlocks the mutex and blocks on the condition variable.When the condition variable is signaled and the calling thread unblocks, `pthread_cond_wait` automatically reacquires a lock on the mutex.
    * Deadlocks with Two or More Threads: The solution is to make sure that all threads that lock more than one resource lock them in the same order.
* `pthread_kill` signal handling

## Chapter05. Interprocess Communication
* code -> ipc
* code -> ipc -> shm.c  `ipcs -m`, `ipcrm shm shmid`
* code -> ipc -> `sem_all_deall.c`:  Allocating and Deallocating a Binary Semaphore
* code -> ipc -> `sem_init.c`: Initializing a Binary Semaphore
* code -> ipc -> `sem_pv.c`: Wait and Post Operations for a Binary Semaphore
* code -> ipc -> `mmap-write.c`: Write a Random Number to a Memory-Mapped File
* code -> ipc -> `mmap-read.c`: Read an Integer from a Memory-Mapped File, and Double It.
* code -> ipc -> `pipe.c`: Using a Pipe to Communicate with a Child Process
* code -> ipc -> `dup2.c`: Redirect Output from a Pipe with dup2
* code -> ipc -> `socket-server.c`: Local Namespace Socket Server (UNIX-domain sockets, UDS)
plus with `socket-client.c`, `socket-inet.c` used for web browsing.


## Chapter07. The /Proc File System

