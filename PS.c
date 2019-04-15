//Peterson's solution for two processess atrying to write on the same File

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int flag[2];
int turn;

void *func1();
void *func2();

void main()
{

int actual_value = shared;
  
//Initialize lock by reseting the desire of both the threads to acquire the locks.And, giving turn to one of them.
flag[0]=flag[1]=0;
turn=0;

//Initialized the lock then fork 2 threads
pthread_t t1,t2;

//Create two threads (both run there respective func)
pthread_create(&t1,NULL,func1,NULL);
pthread_create(&t2,NULL,func2,NULL);

//Wait for the threads to end.  
pthread_join(t1,NULL);
pthread_join(t2,NULL);

printf("\n The Actual Value of shared variable .: %d \n",actual_value);
printf("\n The final value of shared variable .: %d \n",shared);

}

void *func1()
{

printf("\n Thread 1 \n");
flag[0] = 1;  //Set flag[self] = 1 saying you want to acquire lock
turn = 1;     //But, first give the other thread the chance to  acquire lock

//Wait until the other thread looses the desire to acquire lock or it is your turn to get the lock.
while(flag[1]==1 && turn==1);

//Critical section (Only one thread can enter here at a time)

int fd = open("File.txt",O_CREAT|O_RDWR,0777);
printf("\n Thread 1 is writing into the File \n");
write(fd,"Thread 1 written Data",22);

//You do not desire to acquire lock in future. This will allow the other thread to acquire the lock.
flag[0] = 0;

}

void *func2()
{

printf("\n Thread 2 \n");
flag[1] = 1;    //Set flag[self] = 1 saying you want to acquire lock
turn = 0;       //But, first give the other thread the chance to  acquire lock

//Wait until the other thread looses the desire to acquire lock or it is your turn to get the lock.
while(flag[0]==1 && turn==0);

//Critical section (Only one thread can enter here at a time)

int fd = open("File.txt",O_CREAT|O_RDWR,0777);
printf("\n Thread 2 is writing into the File \n");
write(fd,"Thread 2 written Data",22);

//You do not desire to acquire lock in future. This will allow the other thread to acquire the lock.
flag[1] = 0;

}




