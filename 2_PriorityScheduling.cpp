#include<bits/stdc++.h>
using namespace std;

struct Process
{
    string id;
    int burstTime, priority, watingTime, turnAroundTime;
};

bool cmp(Process a, Process b)
{
    return a.priority < b.priority;
}

int main()
{
    printf("Enter number of process ");
    int numOfProcess;
    cin>>numOfProcess;
    vector<Process> processList(numOfProcess);
    for(int i = 0; i < numOfProcess; i++)
    {
        cin>>processList[i].id>>processList[i].burstTime>>processList[i].priority;
    }
    sort(processList.begin(), processList.end(), cmp);
    int currentTime = 0;
    double totalTurnaroundTime = 0, totalWatingTime = 0;
    vector<pair<string,int>>processFinishTime;

    for(int i = 0; i < numOfProcess; i++)
    {
        currentTime += 	processList[i].burstTime;
        processFinishTime.push_back(make_pair(processList[i].id,currentTime));
        processList[i].turnAroundTime = currentTime;
        processList[i].watingTime = processList[i].turnAroundTime - processList[i].burstTime;
        totalTurnaroundTime += processList[i].turnAroundTime;
        totalWatingTime += processList[i].watingTime;
    }
    string ganttChart = "|", border = "-";
    for(auto x : processFinishTime)
    {
        ganttChart += "  " + x.first + "  |";
        border += "-------";
    }
    cout<<"Grant Chart: \n"<<border<<endl<<ganttChart<<endl<<border<<endl<<"0";
    int index = 0;
    for(int i = 1; i < ganttChart.size(); i++)
    {
        if(ganttChart[i] == '|')
        {
            cout<<processFinishTime[index].second;
            if(processFinishTime[index++].second > 9)
            {
                i++;
            }
        }
        else
        {
            cout<<" ";
        }
    }
    cout<<"\n\nAverage Turnaround Time: "<<totalTurnaroundTime/numOfProcess<<"\nAverage Waiting Time: "<<totalWatingTime/numOfProcess<<endl;
    cout<<"Process    |  Waiting Time  |  Turnaround Time\n";
    cout<<"-------------------------------------------------\n";
    for(int i = 0;i< numOfProcess;i++)
    {
        cout<<processList[i].id<<"         |  "<<processList[i].watingTime<<"         |  "<<processList[i].turnAroundTime<<"\n";
    }

}


/*
Input: 
5
P1 10 3
P2 1 1
P3 2 4
P4 1 5
P5 5 2

Output:

Enter number of process 5
P1 10 3
P2 1 1
P3 2 4
P4 1 5
P5 5 2
Grant Chart: 
------------------------------------
|  P2  |  P5  |  P1  |  P3  |  P4  |
------------------------------------
0      1      6      16     18     19

Average Turnaround Time: 12
Average Waiting Time: 8.2
Process    |  Waiting Time  |  Turnaround Time
-------------------------------------------------
P2         |  0         |  1
P5         |  1         |  6
P1         |  6         |  16
P3         |  16         |  18
P4         |  18         |  19

*/