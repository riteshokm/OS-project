#include <stdio.h>

struct student
{
int StudentId;
int FoodTakenTime;
int WaitingTime;
int TurnAroundTime;
};

void acpt(struct student stud[], int n);			//To get the details of student i.e. ID & Food taking time
void schdl(struct student stud[], int n);			//To Schedule the Food taking sequence of the students
void wt(struct student stud[], int n);				//To calculate the waiting time, also average waiting time
void tat(struct student stud[], int n);				//To calculate the turn around time, also average turn around time
void disp(struct student stud[], int n);			//To Display the data on screen

void main()
{
struct student stud[10];
int n,i;
char c;
do
{
printf("\nPlease enter the No. of Students entering into the mess : ");
scanf("%d", &n);

acpt(stud, n);
schdl(stud, n);
wt(stud,n);
tat(stud,n);
disp(stud, n);

printf("\nTo Calculate Again Enter Y or Enter N for exit \n");
scanf("%s",&c);
}while(c=='y'||c=='Y');
printf("\nThank You... ! \n");

}

void acpt(struct student stud[10], int n)
{

for (int i = 0; i<n; i++)
{
printf("\nEnter Student id : ");
scanf("%d", &stud[i].StudentId);

printf("Enter time taken for food (min): ");
scanf("%d", &stud[i].FoodTakenTime);
}

}

void schdl(struct student stud[10], int n)
{

struct student temp;

for(int i = 0; i<n-1; i++)
{
for(int j = 0; j<(n-1-i); j++)
{

if(stud[j].FoodTakenTime < stud[j+1].FoodTakenTime)
{

temp = stud[j];
stud[j] = stud[j+1];
stud[j+1] = temp;

}
else if(stud[j].FoodTakenTime == stud[j+1].FoodTakenTime)
{
if(stud[j].StudentId > stud[j+1].StudentId)
{
temp = stud[j];
stud[j] = stud[j+1];
stud[j+1] = temp;
}
}

}
}
}

void wt(struct student stud[10], int n)
{

stud[0].WaitingTime=0;
for(int j=1; j<n; j++)
{
stud[j].WaitingTime = stud[j-1].WaitingTime + stud[j-1].FoodTakenTime;
}

}

void tat(struct student stud[10], int n)
{

for(int j=0;j<n;j++)
{
stud[j].TurnAroundTime = stud[j].WaitingTime + stud[j].FoodTakenTime;
}

}

void disp(struct student stud[10], int n)
{

int AvgWaitingTime = 0, AvgTurnAroundTime = 0;
int TotalWatingTime = 0, TotalTurnAroundTime = 0;

printf("\n\nStudent id\tFoodTakenTime\tWaitingTime\tTurnAroundTime");    

for (int i = 0; i<n; i++)
{

printf("\n%d\t\t%d\t\t%d\t\t%d\t\t", stud[i].StudentId, stud[i].FoodTakenTime, stud[i].WaitingTime, stud[i].TurnAroundTime);

TotalWatingTime = TotalWatingTime + stud[i].WaitingTime;
TotalTurnAroundTime = TotalTurnAroundTime + stud[i].TurnAroundTime;

}

printf("\n\nTotal Waiting Time is: = %d",TotalWatingTime);
printf("\nTotal Turn around Time is: = %d\n",TotalTurnAroundTime);
printf("\n\nAverage Waiting Time is: = %d",TotalWatingTime/n);
printf("\nAverage Turn around Time is: = %d\n",TotalTurnAroundTime/n);

}


