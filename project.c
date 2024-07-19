#include<stdio.h> 
#include<stdlib.h> 
#include<stdlib.h> 
 
//FCFS 
 
void FCFS() 
{ 
    FILE *fp; 
    fp=fopen("data.txt","r"); 
    char c,name[100]; 
    int n=0; 
    int w=0,b=0,i=0,temp=0,pos=0,j=0,a=0; 
    fseek(fp, 0, SEEK_SET); 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    { 
        if (c == '\n') 
            n = n + 1; 
    } 
 
 
int priority[n],burst_time[n],process[n],p,arrival[n],waiting_time[n],TAT[n],total_tat=0,total_wait=0,completion_time[n]; 
    fseek(fp, 0, SEEK_SET); 
    fgets(name,100,fp); 
    printf("%d\n",n); 
    while(fscanf(fp, "%d,%d,%d,%d",&w, &b,&a,&p) 
!= EOF) 
    { 
        burst_time[i]=b; 
        arrival[i]=a; 
        process[i]=w; 
        priority[i]=p; 
        i++; 
        j++; 
    } 
    fseek(fp, 0, SEEK_SET); 
    for(i=0; i<n-1; i++) 
    { 
        pos=i; 
        for(j=i+1; j<n; j++) 
        { 
            if(arrival[j]<arrival[pos]) 
                pos=j; 
        } 
        temp=arrival[i]; 
        arrival[i]=arrival[pos]; 
        arrival[pos]=temp; 
 
 
        temp=burst_time[i]; 
        burst_time[i]=burst_time[pos]; 
        burst_time[pos]=temp; 
 
        temp=process[i]; 
        process[i]=process[pos]; 
        process[pos]=temp; 
    } 
 
 
    completion_time[0]=burst_time[0]; 
    for(int i=1; i<n; i++) 
    { 
        completion_time[i]=completion_time[i+1]+burst_time[i]; 
 
    } 
    int z; 
    for(i=0; i<n-1; i++) 
    { 
        z=i; 

        if(completion_time[i]<arrival[i+1]) 
 
        { 
            completion_time[i+1]+=(arrival[i+1]-completion_time[i]); 
            i++; 
            i++; 
            while(i!=n) 
            { 
                
    completion_time[i]=completion_time[i+1]+burst_time[i]; 
                i++; 
            } 
            i=z; 
        } 
    } 
 
    for(int i=0; i<n; i++) 
    { 
        TAT[i]=completion_time[i]-arrival[i]; 
 
    } 
    for(i=0; i<n; i++) 
    { 
        waiting_time[i]=TAT[i]-burst_time[i]; 
    } 
 
 
 
    for(int i=0; i<n; i++) 
    { 
        total_wait+=waiting_time[i]; 
        total_tat+=TAT[i]; 
    } 
    
printf("Processes\tArrival\tBurst\tCompletion\tWaiting\tTurn_around"); 
 
    for(int i=0; i<n; i++) 
    { 
        printf("\nP%d\t\t%d\t%d\t%d\t\t%d\t%d", 
process[i],arrival[i],burst_time[i], 
completion_time[i],waiting_time[i],TAT[i]); 
    } 
    printf("\nAverage Waiting time %f\n",(float)(total_wait)/(n)); 
    printf("Average Turnaround time %f\n\n",(float)(total_tat)/(n)); 
 
    printf("...........Gantt Chart.............\n\n"); 
    printf("|"); 
    for(i=0; i<n; i++) 
    {  
        printf(" P%d |",process[i]); 
    } 
    printf("\n0"); 
    for(i=0; i<n; i++) 
    { 
        printf("    %d",completion_time[i]); 
    } 
} 
 
 
 
 
//sjf 
 
 
void SJ_F(int n,int at[],int brust[]) 
{ 
   int total=0,bt[n]; 
   double wt=0,tat=0; 
   for(int 
i=0;i<n;i++)bt[i]=brust[i],total+=bt[i]; 
   int ans[total+1]; 
   for(int i=n-1;i>=0;i--)if(at[i]==0)ans[0]=i; 
 
   printf("Gantt Chart : "); 
   for(int i=1;i<=total;i++) 
   { 

      int cr=ans[i-1],mn=brust[cr]; 
      for(int j=0;j<n;j++) 
      { 
         if(at[j]<i && 
brust[j]<mn)mn=brust[j],cr=j; 
      } 
      ans[i]=cr; 
      printf("%d ",ans[i]); 
      bt[cr]--; 
      if(bt[cr]==0) 
      { 
         tat+=(i-at[cr]); 
         wt+=(i-at[cr]-brust[cr]); 
         brust[cr]=1e9; 
      } 
   } 
   printf("\nAverage turn around time : "); 
   printf("%lf",tat/n); 
   printf("\nAverage waiting time :"); 
   printf("%lf",wt/n); 
} 
 
void SJF() 
{ 
 
    FILE *fp; 
    fp=fopen("data.txt","r"); 

    char c,name[100]; 
    int n=0; 
    int w=0,b=0,i=0,temp=0,pos=0,j=0,a=0; 
    fseek(fp, 0, SEEK_SET); 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    { 
        if (c == '\n') 
            n = n + 1; 
    } 
 
    int priority[n],burst_time[n],process[n],p,arrival[n],waiting_time[n],TAT[n],total_tat=0,total_wait=0; 
    fseek(fp, 0, SEEK_SET); 
    fgets(name,100,fp); 
    while(fscanf(fp, "%d,%d,%d,%d",&w, &b,&a,&p) != EOF) 
    { 
        burst_time[i]=b; 
        arrival[i]=a; 
        process[i]=w; 
        priority[i]=p; 
        i++; 
        j++; 
    } 
    fseek(fp, 0, SEEK_SET); 
 
    SJ_F(n,arrival,burst_time); 
 
} 
 
 
void PS(int n,int at[],int bt[],int p[]){ 
    int temp[n],tat[n],wt[n]; 
    for (int i = 0; i < n; i++) 
    { 
        temp[i] = bt[i]; 
    } 
 
    int cnt = 0, t = 0, Total_wt = 0, Total_tat = 0; 
    printf("Gantt chart\n"); 
 
    for(t;cnt<n;t++){ 
        int mi_p = n+1; 
        int ind=-1; 
        for(int i=0;i<n;i++){ 
            if(p[i]<mi_p && at[i]<=t && 
bt[i]>0){ 
                mi_p=p[i]; 
                ind = i; 
            } 
        } 
        if(ind==-1) { 
            printf("%s - "); 
            continue; 
        } 
        bt[ind]-=1; 
        printf("%d ",ind); 
        if(bt[ind]==0){ 
            cnt++; 
            tat[ind]=t+1-at[ind]; 
            wt[ind]=tat[ind]-temp[ind]; 
            Total_tat += tat[ind]; 
            Total_wt += wt[ind]; 
        } 
    } 
    float avg_tat = (float)Total_tat/n; 
    float avg_wt = (float)Total_wt/n; 
 
    printf("\n"); 
 
    printf("\nAverage Turn-Around Time : %f",avg_tat); 
    printf("\nAverage Waiting Time : %f",avg_wt); 
} 
 
 
  
//preemp_priority 
 
 
 
 
void Priority() 
{ 
    FILE *fp; 
    fp=fopen("data.txt","r"); 
    char c,name[100]; 
    int n=0; 
    int w=0,b=0,i=0,temp=0,pos=0,j=0,a=0; 
    fseek(fp, 0, SEEK_SET); 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    { 
        if (c == '\n') 
            n = n + 1; 
    } 
 
    int priority[n],burst_time[n],process[n],p,arrival[n],waiting_time[n],TAT[n],total_tat=0,total_wait=0; 
    fseek(fp, 0, SEEK_SET); 
    fgets(name,100,fp); 
    while(fscanf(fp, "%d,%d,%d,%d",&w, &b,&a,&p) != EOF)  
    { 
        burst_time[i]=b; 
        arrival[i]=a; 
        process[i]=w; 
        priority[i]=p; 
        i++; 
        j++; 
    } 
    fseek(fp, 0, SEEK_SET); 
 
    PS(n,arrival,burst_time,priority); 
 
 
 
    } 
 
 
 
 
//srtf 
 
 
void SRTF() 
{ 
    FILE *fp; 
    fp=fopen("data.txt","r"); 
    char c,name[100]; 
    int n=0; 
    int w=0,b=0,i=0,temp=0,min=0,j=0,a=0,small; 
    fseek(fp, 0, SEEK_SET); 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    { 
        if (c == '\n') 
            n = n + 1; 
    } 
 
    int priority[n],burst_time[n],process[n],p,arrival[n],waiting_time[n],TAT[n],total_tat=0,total_wait=0,completion[n]; 
    fseek(fp, 0, SEEK_SET); 
    fgets(name,100,fp); 
    while(fscanf(fp, "%d,%d,%d,%d",&w, &b,&a,&p) != EOF) 
    { 
        burst_time[i]=b; 
        arrival[i]=a; 
        process[i]=w; 
        priority[i]=p; 
        i++; 
        j++; 
    } 
    fseek(fp, 0, SEEK_SET); 
    int total=0,finish[n],k; 
    for(i=0; i<n; i++) 
    { 
        total+=burst_time[i]; 
    } 
 
    for(i=0; i< -1; i++) 
    { 
        min=i; 
        for(j=i+1; j< n; j++) 
        { 
            if(arrival[j]< arrival[min]) 
            { 
                min=j; 
            } 
        } 
        temp=arrival[i]; 
        arrival[i]=arrival[min]; 
        arrival[min]=temp; 
 
        temp=burst_time[i]; 
        burst_time[i]=burst_time[min]; 
        burst_time[min]=temp; 
 
        temp=process[i]; 
        process[i]=process[min]; 
        process[min]=temp; 
    } 
    int RT[n],maxCT,q=0; 
    double thrpt; 
    for(i=0; i< n; i++) 
    { 
        RT[i]=burst_time[i]; 
    } 
    RT[n]=9999; 
    j=0; 
     printf(".........Gantt Chart.........\n"); 
    for(min=0; j!=n; min++) 
    { 
        temp=n; 
        for(i=0; i< n; i++) 
        { 
            if(arrival[i]<=min && RT[i]< RT[temp] && RT[i]>0) 
            { 
                temp=i; 
            } 
        } 
        RT[temp]--; 
        if(RT[temp]==0) 

        { 
            j++; 
            thrpt=min+1; 
            completion[temp]=thrpt; 
            if(maxCT< thrpt) 
            { 
                maxCT=thrpt; 
            } 
        } 
        q++; 
        printf("P%d| ",process[temp]); 
    } 
    printf("\n"); 
    for(i=0; i<q; i++) 
    { 
        printf("%d  ",i); 
    } 
    printf("\n\nProcess\tArrival Time\tExecution Time\tCompletion Time\tTAT\tWaiting Time\n"); 
    for(i=0; i< n; i++) 
    { 
        TAT[i]=completion[i]-arrival[i]; 
        waiting_time[i]=TAT[i]-burst_time[i]; 
        total_tat=total_tat+TAT[i]; 
        total_wait=total_wait+waiting_time[i]; 
        
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",process
 
[i],arrival[i],burst_time[i],completion[i],TAT[i
 ],waiting_time[i]); 
    } 
    printf("\nAverage Waiting time %f\n",(float)(total_wait)/(n)); 
    printf("Average Turnaround time %f\n\n",(float)(total_tat)/(n)); 
} 
 
 
 
 
//rr 
 
 
void RoundRobin() 
{ 
    FILE *fp; 
    fp=fopen("data.txt","r"); 
    char c,name[100]; 
    int n=0; 
    int w=0,b=0,i=0,min=0,j=0,a=0,small,sum=0; 
    fseek(fp, 0, SEEK_SET); 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    { 
        if (c == '\n') 
            n = n + 1; 

    } 
    int 
priority[n],y,burst_time[n],process[n],p,arrival
 [n],waiting_time[n],TAT[n],total_tat=0,total_wait=0,completion[n]; 
    fseek(fp, 0, SEEK_SET); 
    int temp[n]; 
    fgets(name,100,fp); 
    while(fscanf(fp, "%d,%d,%d,%d",&w, &b,&a,&p) != EOF) 
    { 
        burst_time[i]=b; 
        arrival[i]=a; 
        process[i]=w; 
        priority[i]=p; 
        i++; 
    } 
    fseek(fp, 0, SEEK_SET); 
 
    y = n; 
    int quant; 
for(i=0; i<n; i++) 
{ 
temp[i] = burst_time[i]; 
} 
 
printf("Enter the Time Quantum for the process: \t"); 
scanf("%d", &quant); 
int count=0; 
printf("\n Process No \tArrival_time\tBurst Time \tTAT \t\t Waiting Time "); 
for(sum=0, i = 0; y!=0; ) 
{ 
if(temp[i] <= quant && temp[i] > 0) // define the conditions 
{ 
    sum = sum + temp[i]; 
    temp[i] = 0; 
    count=1; 
    } 
    else if(temp[i] > 0) 
    { 
        temp[i] = temp[i] - quant; 
        sum = sum + quant; 
    } 
    if(temp[i]==0 && count==1) 
    { 
        y--; 
        printf("\nProcess No%d\t\t%d\t\t%d\t%d\t\t%d", i+1, arrival[i],burst_time[i], sum-arrival[i], sum+arrival[i]-burst_time[i]); 

        total_wait = total_wait+sum-arrival[i]+burst_time[i]; 
        total_tat=total_tat+sum-arrival[i]; 
        count =0; 
    } 
    if(i==n-1) 
    { 
        i=0; 
    } 
    else if(arrival[i+1]<=sum) 
    { 
        i++; 
    } 
    else 
    { 
        i=0; 
    } 
} 
float avg_wt,avg_tat; 
avg_wt = total_wait * 1.0/n; 
avg_tat = total_tat * 1.0/n; 
printf("\n Average Turn Around Time: \t%f", 
avg_tat); 
printf("\n Average Waiting Time: \t%f", avg_wt); 
} 
  
 
//lrtf 
 
void LR_TF(int n,int at[],int brust[]) 
{ 
    int total=0,bt[n]; 
    double tat=0,wt=0; 
    for(int 
i=0;i<n;i++)bt[i]=brust[i],total+=bt[i]; 
    int ans[total+1]; 
    for(int i=n-1;i>=0;i--)if(at[i]==0)ans[0]=i; 
    printf("Gantt chart : "); 
    for(int i=1;i<=total;i++) 
    { 
       int maxt=bt[ans[i-1]],cr=ans[i-1]; 
       for(int j=0;j<n;j++) 
       { 
          if(bt[j]>maxt && 
at[j]<i)maxt=bt[j],cr=j; 
       } 
       ans[i]=cr; 
       bt[cr]--; 
       if(bt[cr]==0)tat+=i-at[cr],wt+=(i+at[cr])-brust[cr]; 
       printf("%d ",ans[i]); 
    } 
    //printf("%s\n"); 

    printf("\nAverage turn aroud time : %f",tat/n); 
    printf("\nAverage waiting time :%f",wt/n); 
} 
 
void LRTF() 
  { 
      FILE *fp; 
    fp=fopen("data.txt","r"); 
    char c,name[100]; 
    int n=0; 
    int w=0,b=0,i=0,min=0,j=0,a=0,small,sum=0; 
    fseek(fp, 0, SEEK_SET); 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    { 
        if (c == '\n') 
            n = n + 1; 
    } 
    int 
priority[n],y,burst_time[n],process[n],p,arrival
 [n],waiting_time[n],TAT[n],total_tat=0,total_wait=0,completion[n]; 
    fseek(fp, 0, SEEK_SET); 
    int temp[n]; 
    fgets(name,100,fp); 
    while(fscanf(fp, "%d,%d,%d,%d",&w, &b,&a,&p) 
!= EOF) 

    { 
        burst_time[i]=b; 
        arrival[i]=a; 
        process[i]=w; 
        priority[i]=p; 
        i++; 
    } 
    fseek(fp, 0, SEEK_SET); 
 
    LR_TF(n,arrival,burst_time); 
 
 
      
    } 
 
 
int main() 
{ 
    printf("\t\t|-----------OPERATING SYSTEM INNOVATIVE ASSIGNMENT :\n"); 
    
    printf("\n"); 
    int flag=1; 
 
    while(flag!=0) 
    { 
        printf("\n\n"); 
        printf("\t1.First-Come First-Served \n\t2.Shortest Job First \n\t3.Round Robin Scheduling \n\t4.Preemptive Priority Scheduling \n\t5.Shortest Remaining Time First \n\t6.Longest remaining time first \n\t0.Exit"); 
        printf("\n\n"); 
 
        printf("Enter your choice: "); 
 
        int choice; 
        scanf("%d",&choice); 
 
        switch(choice) 
        { 
        case 1: 
            FCFS(); 
            break; 
        case 2: 
            SJF(); 
            break; 
        case 3: 
            RoundRobin(); 
            break; 
        case 4: 
            Priority(); 
            break; 
        case 5: 

            SRTF(); 
            break; 
        case 6: 
            LRTF(); 
            break; 
        case 0: 
            flag=0; 
            break; 
        } 
 
    } 
 
    return 0;
}