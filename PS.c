#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int flag[2];
int turn;
int shared = 1;

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
pthread_create(&t1,NULL,func1,&shared);
pthread_create(&t2,NULL,func2,&shared);

//Wait for the threads to end.  
pthread_join(t1,NULL);
pthread_join(t2,NULL);

printf("\n The Actual Value of shared variable .: %d \n",actual_value);
printf("\n The final value of shared variable .: %d \n",shared);

}

void *func1()
{

printf("\n Thread 1 \n");
flag[0] = 1;
turn = 1;
while(flag[1]==1 && turn==1);

//Critical section (Only one thread can enter here at a time)

printf("Thread 1 Entered ");
int x = shared;
x++;
shared = x;

flag[0] = 0;

}

void *func2()
{

printf("\n Thread 2 \n");
flag[1] = 1;
turn = 0;
while(flag[0]==1 && turn==0);

//Critical section (Only one thread can enter here at a time)

printf("Thread 2 Entered ");
int y = shared;
y--;
shared = y;

flag[1] = 0;

}




