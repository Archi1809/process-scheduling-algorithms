Links:

Process Sch : https://github.com/codophobia/process-scheduling-algorithms

Codes:

Fcfs ->
// C++ program for implementation of FCFS
// scheduling
#include<iostream>
using namespace std;

// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n,
						int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	//Display processes along with all details
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	//process id's
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	//Burst time of all processes
	int burst_time[] = {10, 5, 8};

	findavgTime(processes, n, burst_time);
	return 0;
}


Sjb->
#include<stdio.h>
#include<conio.h>
main()
{
int p[20], bt[20], wt[20], tat[20], i, k, n, temp; float wtavg,
tatavg;
printf("\nEnter the number of processes -- ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
p[i]=i;
printf("Enter Burst Time for Process %d -- ", i);
scanf("%d", &bt[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(bt[i]>bt[k])
{
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=p[i];
p[i]=p[k];
p[k]=temp;
}
wt[0] = wtavg = 0;
tat[0] = tatavg = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] +bt[i-1];
tat[i] = tat[i-1] +bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
printf("\nAverage Waiting Time -- %f", wtavg/n);
printf("\nAverage Turnaround Time -- %f", tatavg/n); getch();}


RR->
#include<stdio.h>
main()
{
int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
float awt=0,att=0,temp=0;
printf("Enter the no of processes -- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time for process %d -- ", i+1);
scanf("%d",&bu[i]);
ct[i]=bu[i];
}
printf("\nEnter the size of time slice -- ");
scanf("%d",&t);
max=bu[0];
for(i=1;i<n;i++)
{
	if(max<bu[i])
	{
		max=bu[i];
	}
}
for(j=0;j<(max/t)+1;j++)
{
	for(i=0;i<n;i++)
	{
		if(bu[i]!=0)
		{
			if(bu[i]<=t) {
				tat[i]=temp+bu[i];
				temp=temp+bu[i];
				bu[i]=0;
			}
			else {
				bu[i]=bu[i]-t;
				temp=temp+t;
			}
		}
	}
}
for(i=0;i<n;i++){
	wa[i]=tat[i]-ct[i];
	att+=tat[i];
	awt+=wa[i];
}
printf("\nThe Average Turnaround time is -- %f",att/n);
printf("\nThe Average Waiting time is -- %f ",awt/n);
printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);
}



Priority->
#include<stdio.h>
main()
{
int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp; float wtavg,
tatavg;
printf("Enter the number of processes --- ");
scanf("%d",&n);
for(i=0;i<n;i++){
p[i] = i;
printf("Enter the Burst Time & Priority of Process %d --- ",i); scanf("%d%d",&bt[i], &pri[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(pri[i] > pri[k]){
temp=p[i];
p[i]=p[k];
p[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=pri[i];
pri[i]=pri[k];
pri[k]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUNDTIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is --- %f",wtavg/n); printf("\nAverageTurnaround Time is --- %f",tatavg/n);
}


Banker’s ->

// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m, i, j, k;
	n = 5; // Number of processes
	m = 3; // Number of resources
	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
						{ 2, 0, 0 }, // P1
						{ 3, 0, 2 }, // P2
						{ 2, 1, 1 }, // P3
						{ 0, 0, 2 } }; // P4

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
					{ 3, 2, 2 }, // P1
					{ 9, 0, 2 }, // P2
					{ 2, 2, 2 }, // P3
					{ 4, 3, 3 } }; // P4

	int avail[3] = { 3, 3, 2 }; // Available Resources

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);

	return (0);

}


Contig FA->

#include<stdio.h>
main()
{
int f[50],i,st,j,len,c,k;
for(i=0;i<50;i++)
f[i]=0;
X:
printf("\n Enter the starting block & length of file");
scanf("%d%d",&st,&len);
for(j=st;j<(st+len);j++)
if(f[j]==0)
{
f[j]=1
;
printf("\n%d->%d",j,f[j]);
}
else
{
printf("Block already allocated");
break;
}
if(j==(st+len))
printf("\n the file is allocated to disk");
printf("\n if u want to enter more files?(y-1/n-0)");
scanf("%d",&c);
if(c==1)
goto X;
else
return 0;
}

Linked FA->

#include<stdio.h>
main()
{
int f[50],p,i,j,k,a,st,len,n,c;
for(i=0;i<50;i++) f[i]=0;
printf("Enter how many blocks that are alreadyallocated");
 scanf("%d",&p);
printf("\nEnter the blocks no.s that are already allocated");
for(i=0;i<p;i++)
{
scanf("%d",&a);
f[a]=1;
}
X:
printf("Enter the starting index block &length"); 
scanf("%d%d",&st,&len); k=len;
for(j=st;j<(k+st);j++)
{
if(f[j]==0)
{ f[j]=1;
printf("\n%d->%d",j,f[j]);
}
else
{
printf("\n %d->file is already allocated",j);
k++;
}
}
printf("\n If u want to enter one more file? (yes-1/no-0)");
scanf("%d",&c);
if(c==1)
goto
X;
else
return 0;}


Indexed FA ->

#include<stdio.h>
int f[50],i,k,j,inde[50],n,c,count=0,p;
main() {
for(i=0;i<50;i++)
f[i]=0;
x: printf("enter index block\t");
scanf("%d",&p);
if(f[p]==0)
{
f[p]=1;
printf("enter no of files on index\t");
scanf("%d",&n); }
else {
printf("Block already allocated\n");
goto x; }
for(i=0;i<n;i++)
scanf("%d",&inde[i]);
for(i=0;i<n;i++)
if(f[inde[i]]==1) {
printf("Block already allocated");
goto x; }
for(j=0;j<n;j++)
f[inde[j]]=1;
printf("\n allocated");
printf("\n file indexed");
for(k=0;k<n;k++)
printf("\n %d->%d:%d",p,inde[k],f[inde[k]]);
printf(" Enter 1 to enter more files and 0 to exit\t");
scanf("%d",&c);
if(c==1)
goto x;
else
return 0 ; }

Best fit ->

#include <stdio.h>
int main()
{
int a[20], b[20], c[20], b1, c1;
int i, j, temp;
static int barr[20], carr[20];
printf("\n\t\t\tMemory Management"
" Scheme - Best Fit");
printf("\nEnter the number of "
"blocks:");
scanf("%d", &b1);
printf("Enter the number of"
" processes:");
scanf("%d", &c1);
int lowest = 9999;
printf("\nEnter the size of the"
" blocks:\n");
for (i = 1; i <= b1; i++)
{
printf("Block no.%d:", i);
scanf("%d", &b[i]);
}
printf("\nEnter the size of"
" the processes :\n");
for (i = 1; i <= c1; i++)
{
printf("Process no.%d:", i);
scanf("%d", &c[i]);
}
for (i = 1; i <= c1; i++)
{
for (j = 1; j <= b1; j++)
{
if (barr[j] != 1)
{
temp = b[j] - c[i];
if (temp >= 0)
if (lowest > temp)
{
carr[i] = j;
lowest = temp;
}
}
}
a[i] = lowest;
barr[carr[i]] = 1;
lowest = 10000;
}
printf("\nProcess_no\tProcess"
"_size\tBlock_no\t"
"Block_size\tFragment");
for (i = 1; i <= c1 && carr[i] != 0; i++)
{
printf("\n%d\t\t%d\t\t%d\t\t"
"%d\t\t%d", i, 
c[i], carr[i], b[carr[i]], a[i]);
}
printf("\n");
}

Worst Fit ->

#include <stdio.h>
int main()
{
printf("\n\t\t\tMemory Management"
" Scheme - Worst Fit");
int i, j, nblocks, nfiles, temp, top = 0;
int frag[10], blocks[10], files[10];
static int block_arr[10], file_arr[10];
printf("\nEnter the Total Number "
"of Blocks: ");
scanf("%d", &nblocks);
printf("Enter the Total Number "
"of Files: ");
scanf("%d", &nfiles);
printf("\nEnter the Size of the "
"Blocks: \n");
for (i = 0; i < nblocks; i++)
{
printf("Block No.%d:\t", i + 1);
scanf("%d", &blocks[i]);
}
printf("Enter the Size of the "
"Files:\n");
for (i = 0; i < nfiles; i++)
{
printf("File No.%d:\t", i + 1);
scanf("%d", &files[i]);
}
for (i = 0; i < nfiles; i++)
{
for (j = 0; j < nblocks; j++)
{
if (block_arr[j] != 1)
{
temp = blocks[j] - files[i];
if (temp >= 0)
{
if (top < temp)
{
file_arr[i] = j;
top = temp;
}
}
}
frag[i] = top;
block_arr[file_arr[i]] = 1;
top = 0;
}
}
printf("\nFile Number\tFile Size\t"
"Block Number\tBlock Size\tFragment");
for (i = 0; i < nfiles; i++)
{
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d"
, i, files[i],
file_arr[i], blocks[file_arr[i]], frag[i]);
}
printf("\n");
return 0;
}

First Fit ->

#include <stdio.h>
int main()
{
int a[10], b[10], a1, b1, flags[10], all[10];
int i, j;
printf("\n\t\t\tMemory Management"
" Scheme -"
" First Fit\n");
for (i = 0; i < 10; i++)
{
flags[i] = 0;
all[i] = -1;
}
printf("Enter number of blocks: ");
scanf("%d", &a1);
printf("\nEnter the size of each"
" block:\n ");
for (i = 0; i < a1; i++)
{
printf("Block no.%d: ", i);
scanf("%d", &a[i]);
}
printf("\nEnter no. of "
"processes: ");
scanf("%d", &b1);
printf("\nEnter size of each"
" process:\n ");
for (i = 0; i < b1; i++)
{
printf("Process no.%d: ", i);
scanf("%d", &b[i]);
}
for (i = 0; i < b1; i++)
for (j = 0; j < a1; j++)
if (flags[j] == 0 && a[j] >= b[i])
{
all[j] = i;
flags[j] = 1;
break;
}
printf("\nBlock no.\tsize\t\t"
"process no.\t\tsize");
for (i = 0; i < a1; i++)
{
printf("\n%d\t\t%d\t\t",
 i + 1, a[i]);
if (flags[i] == 1)
{
printf("%d\t\t\t%d", all[i]
 + 1, b[all[i]]);
}
else
printf("Not allocated");
}
printf("\n");
}

Paging->

#include<stdio.h>
 main()
{
int memsize=15;
int pagesize,nofpage;
int p[100];
int frameno,offset;
int logadd,phyadd;
int i;
int choice=0;
printf("\nYour memsize is %d ",memsize);
printf("\nEnter page size:");
scanf("%d",&pagesize);

nofpage=memsize/pagesize;

for(i=0;i<nofpage;i++)
{
printf("\nEnter the frame of page%d:",i+1);
scanf("%d",&p[i]);
}

do
{
printf("\nEnter a logical address:");
scanf("%d",&logadd);
frameno=logadd/pagesize;
offset=logadd%pagesize;
phyadd=(p[frameno]*pagesize)+offset;
printf("\nPhysical address is:%d",phyadd);
printf("\nDo you want to continue(1/0)?:");
scanf("%d",&choice);
}while(choice==1);
}

