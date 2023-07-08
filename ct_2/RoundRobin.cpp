#include<bits/stdc++.h>
using namespace std;

struct process
{
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

int main()
{
    freopen("input1.txt","r",stdin);
    int numOfProcess;
    printf("Enter the number of process: ");
    scanf("%d",&numOfProcess);
    process processes[numOfProcess];
    for(int i = 0;i<numOfProcess;i++)
    {
        printf("Enter the burst time for process %d: ",i);
        cin>>processes[i].burstTime;
        // cout<<processes[i].burstTime;
    }
    int timeQuantum = 4;
    vector<pair<int,int>>grant_chart;

    int time = 0;
    // int i = 0;
    while(1)
    {
        bool nonzero = false;
        for(int i = 0;i<numOfProcess;i++)
        {
            if(processes[i].burstTime!=0)
            {

                // cout<<"hello\n";
                nonzero = true;
                if(processes[i].burstTime<=timeQuantum)
                {
                    // grant_chart.push_back({time,(time+processes[i].burstTime)-1});
                    grant_chart.push_back({time,i});
                    time = time + processes[i].burstTime;
                    processes[i].burstTime = 0;
                }
                else{
                    // grant_chart.push_back({time,(time+timeQuantum-1)});
                    grant_chart.push_back({time,i});
                    time = time + timeQuantum;
                    processes[i].burstTime = max(0,processes[i].burstTime - timeQuantum);
                }
            }
        }
        
        if(!nonzero) break;
        // i++;
        // i = i%numOfProcess;
    }
    // cout<<grant_chart.size()<<endl;
    // grant_chart.push_back({time,0});    
    // for(int i=0 ;i<grant_chart.size();i++)
    // {
    //     cout<<grant_chart[i].first;
    //     printf(" -> P%d\n",grant_chart[i].second);
    //     // cout<<grant_chart[i].first<<" -> "<<grant_chart[i].second<<endl;
    // }
    printf("\n");
    for(int i = 0;i<grant_chart.size();i++)
    {
        printf("   P%d  ",grant_chart[i].second);
    }
    printf("\n");
    for(int i = 0;i<grant_chart.size();i++)
    {
        printf("%2d     ",grant_chart[i].first);
    }
    printf("%2d     ",time);
}
/*
3
0 24
1 3
2 3
*/