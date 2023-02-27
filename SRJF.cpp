#include<bits/stdc++.h>
using namespace std;

struct test
{
    int a;
    int b;
};

int main()
{
    // test temp;
    // temp.a = 5;
    // temp.b = 6;
    map<int,vector<pair<int,int>>> process;
    int numOfProcess;
    printf("Enter the number of process: ");
    scanf("%d",&numOfProcess);

    int arrivalTime,burstTime;
    int totalBurstTime = 0;
    int ans[100];

    for(int i = 1;i<=numOfProcess;i++)
    {
        scanf("%d %d",&arrivalTime,&burstTime);
        totalBurstTime += burstTime;
        process[arrivalTime].push_back({i,burstTime});    
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> shortestProcess;
    for(int i = 0;i<totalBurstTime;i++)
    {
        for(int j = 0;j<process[i].size();j++)
        {
            shortestProcess.push({process[i][j].second,process[i][j].first});
        }
        pair<int,int> shortest = shortestProcess.top();
        shortestProcess.pop();
        ans[i] = shortest.second;
        printf("i = %d, processnumber = %d\n",i,ans[i]);
        shortest.first--;
        if(shortest.first != 0)
        shortestProcess.push({shortest});
    }
    

}
// Slide's input
// 4
// P1 0 8
// P2 1 4
// P3 2 9
// P4 3 5

// Slide's output
// ------------------------------------
// |  P1  |  P2  |  P4  |  P1  |  P3  |
// ------------------------------------
// 0      1      5      10     17    26