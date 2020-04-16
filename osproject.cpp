#include<stdio.h>
int main()
{
  int i,j,n;
  int time,remaining;
  int flag=0,time_quantum=10;
  int waiting_time=0,turn_around_time=0;
  int arrival_time[10],burst_time[10],remaining_time[10];
  printf("\n\nEnter the number of process to excute:\t ");
  scanf("%d",&n);
  remaining=n;
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
    scanf("%d",&arrival_time[i]);
    scanf("%d",&burst_time[i]);
    remaining_time[i]=burst_time[i];
  }
  printf("Enter Time Quantum:%d\t",time_quantum);
 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,i=0;remaining!=0;)
  {
    if(remaining_time[i]<=time_quantum && remaining_time[i]>0)
    {
      time+=remaining_time[i];
      remaining_time[i]=0;
      flag=1;
    }
    else if(remaining_time[i]>0)
    {
      remaining_time[i]-=time_quantum;
      time+=time_quantum;
    }
    if(remaining_time[i]==0 && flag==1)
    {
      remaining--;
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-arrival_time[i],time-arrival_time[i]-burst_time[i]);
      waiting_time+=time-arrival_time[i]-burst_time[i];
      turn_around_time+=time-arrival_time[i];
      flag=0;
    }
    if(i==n-1)
     i=0;
    else if(arrival_time[i+1]<=time)
      i++;
    else
      i=0;
  }
  printf("\nAverage Waiting Time= %f\n",waiting_time*1.0/n);
  printf("Avg Turnaround Time = %f",turn_around_time*1.0/n);
 
  return 0;
}

