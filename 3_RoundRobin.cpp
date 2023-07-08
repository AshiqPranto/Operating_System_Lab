#include<bits/stdc++.h>
using namespace std;

struct Process
{
    string id;
    int burstTime, waitingTime, turnAroundTime;
};
int main()
{
    printf("Enter number of process ");
    int numOfProcess;
    cin>>numOfProcess;
    vector<Process> processList(numOfProcess);
    queue<Process>waitingQueue;
    for(int i = 0; i < numOfProcess; i++)
    {
        cin>>processList[i].id>>processList[i].burstTime;
        waitingQueue.push(processList[i]);
    }
    int currentTime = 0, totalWaitingTime = 0, totalTurnAroundTime = 0;
    int timeQuntum = 4;
    vector<pair<string,int>> processFinishTime;
    while(!waitingQueue.empty())
    {
        Process currentProcess = waitingQueue.front();
        waitingQueue.pop();
        if(currentProcess.burstTime <= timeQuntum)
        {
            currentTime += currentProcess.burstTime;
            processFinishTime.push_back(make_pair(currentProcess.id,currentProcess.waitingTime + currentTime));
            for(int i = 0; i < numOfProcess; i++)
            {
                if(processList[i].id == currentProcess.id)
                {
                    processList[i].waitingTime = currentTime - processList[i].burstTime;
                    processList[i].turnAroundTime = currentTime;;
                    totalWaitingTime += processList[i].waitingTime;
                    totalTurnAroundTime += processList[i].turnAroundTime;
                }
            }
        }
        else{
            currentProcess.burstTime -= timeQuntum;
            currentTime += timeQuntum;
            processFinishTime.push_back(make_pair(currentProcess.id,currentProcess.waitingTime + currentTime));
            waitingQueue.push(currentProcess);
        }
    }
    string ganttChirt = "|", border = "-";
    for(auto x : processFinishTime)
    {
        ganttChirt += "  " + x.first + "  |";
        border += "-------";
    }
    cout<<"GanttChirt: \n"<<border<<"\n"<<ganttChirt<<"\n"<<border<<"\n"<<"0";
    int index = 0;
    for(int i = 1; ganttChirt[i]; i++)
    {
        if(ganttChirt[i] == '|')
        {
            cout<<processFinishTime[index].second;
            if(processFinishTime[index++].second > 9)
            {
                i++;
            }
        }
        else cout<<" ";
    }
    cout<<"\n\nAverage Turnaround Time: "<<totalTurnAroundTime/numOfProcess<<"\nAverage Waiting Time: "<<totalWaitingTime/numOfProcess<<endl;
    cout<<"Process    |  Waiting Time  |  Turnaround Time\n";
    cout<<"-------------------------------------------------\n";
    for(int i = 0;i< numOfProcess;i++)
    {
        cout<<processList[i].id<<"         |  "<<processList[i].waitingTime<<"         |  "<<processList[i].turnAroundTime<<"\n";
    }
}