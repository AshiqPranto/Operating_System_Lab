// FCFS
#include <iostream>
using namespace std;


const int Max_Process = 100;


struct Process{
	int arrival_time;
	int burst_time;
};

void findWaitingTime(Process processes[],int n,int waiting_time[])
{
    waiting_time[0] = 0;
    for(int i = 1; i<n;i++)
    {
        waiting_time[i] = waiting_time[i-1] + processes[i].burst_time-processes[i].arrival_time;
    }
}
void findTurnAroundTime(Process processes[],int n,int waiting_time[],int turn_around_time[])
{
    for(int i = 0;i<n;i++)
    {
        turn_around_time[i] =  processes[i].burst_time + waiting_time[i];
    }
}


void findAvgTime(Process processes[],int n)
{
    int waiting_time[n], turn_around_time[n];
    findWaitingTime(processes,n,waiting_time);
    findTurnAroundTime(processes,n,waiting_time,turn_around_time);
    cout<<"Processes "<<" Burst time "<<" Waiting time "<<" Turn around time\n";
    int total_waiting_time = 0, total_turn_around_time = 0;
    for(int i = 0;i<n;i++)
    {
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        cout<<" "<<i+1<<"\t\t"<<processes[i].burst_time<< "\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i]<<endl;
    }
    cout<<"Average waiting time = "<<total_waiting_time/(n+0.0);
    cout<<"\nAverage turn around time = "<<total_turn_around_time/(n+0.0);
}




int main() {
	// your code goes here
	
	
	Process processes[Max_Process];
	int n;
	cout<<"Enter the number of processes";
	cin>> n;
	cout<<"Enter the burst time and arrival time of the process: \n";
	for(int i = 0;i<n;i++)
	{
	    cout<<"Processes "<<i+1<<": ";
	    cin>>processes[i].burst_time>>processes[i].arrival_time;
	}
	findAvgTime(processes,n);
	
	return 0;
}






