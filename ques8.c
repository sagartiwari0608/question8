 
#include<stdio.h> 
#include<conio.h>

void findWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; . 
	while (1) 
	{ 
		bool done = true; 

		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = false; 
				if (rem_bt[i] > quantum) 
				{ 
					t += quantum; 

					rem_bt[i] -= quantum; 
				} 

				else
				{ 
					t = t + rem_bt[i]; 

					wt[i] = t - bt[i]; 

					rem_bt[i] = 0; 
				} 
			} 
		} 

		if (done == true) 
		break; 
	} 
} 

// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int processes[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	findWaitingTime(processes, n, bt, wt, quantum); 

	findTurnAroundTime(processes, n, bt, wt, tat); 

	printf("  Processes     Burst time     Waiting time      Turn around time\n"); 



	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		printf("  %d \t\t %d \t\t\t %d\t\t %d \n", i+1 , bt[i],  wt[i] ,tat[i]); 
	} 
intf("Average waiting time = %f",(float)total_wt / (float)n); 
	printf("\nAverage turn around time = %f",(float)total_tat / (float)n); 
} 

int main() 
{ 
	int processes[] = { 1, 2, 3,4,5,6}; 
	int n = sizeof processes / sizeof processes[0]; 
	int priority[]={40,30,30,35,5,10}
	int burst_time[] ={20,25,25,15,10,10};

	int quantum = 10; 
	findavgTime(processes, n, burst_time, quantum); 
	return 0; 
} 
