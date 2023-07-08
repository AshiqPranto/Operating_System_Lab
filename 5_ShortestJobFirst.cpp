#include<bits/stdc++.h>
using namespace std;

struct process
{
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
};



int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    printf("Enter the number of process: ");
    cin>>n;
    vector<pair<int,int>>order;
    process processes[n+5];
    int burstTime;
    for(int i = 0;i<n;i++)
    {
        printf("\nEnter the Burst time for process %d: ", i+1);
        cin>>burstTime;
        processes[i].burstTime = burstTime;
        processes[i].arrivalTime = 0;
        order.push_back({burstTime,i});

    }
    sort(order.begin(), order.end());
    int t = 0;
    vector<pair<int,int>>grant_chart;
    //grant_chart first = time, second = process_id
    for(int i = 0;i<order.size();i++)
    {
        grant_chart.push_back({t,order[i].second});
        t += order[i].first;
    }
    printf("\n\n GRANT CHART:");
    // for(int i = 0;i<n;i++)
    // {
    //     printf("time = %d, process = %d\n",grant_chart[i].first,grant_chart[i].second+1);
    // }

    // Printing Grant Chart
    printf("\n\n");
    for(int i = 0;i<n;i++)
    {
        printf("P%d \t",grant_chart[i].second+1);
    }
    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\t",grant_chart[i].first);
    }

    for(int i = 0;i<n;i++)
    {
        int pid = grant_chart[i].second;
        processes[pid].completionTime = grant_chart[i].first+processes[pid].burstTime;
        processes[pid].turnAroundTime = processes[pid].completionTime - processes[pid].arrivalTime;
        processes[pid].waitingTime = processes[pid].turnAroundTime - processes[pid].burstTime;
        processes[pid].responseTime = grant_chart[i].first - processes[pid].arrivalTime;
    }
    //printing the processes in a table
    cout << "\nTABLE:\n" << endl;
    puts("| PID | Burst Time | Arrival Time | Completion Time | Waiting Time | Turnaround Time | Response Time");

    for (int i = 0; i < n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |      %2d      |      %2d       |      %2d       |\n"
            , (i+1), processes[i].burstTime, processes[i].arrivalTime, processes[i].completionTime, processes[i].waitingTime, processes[i].turnAroundTime,processes[i].responseTime);
    }

}


// void print_table(vector<Process>& p, int n) {
//     cout << "TABLE:" << endl;
//     puts("+-----+------------+--------------+-----------------+--------------+---------------+");
//     puts("| PID | Burst Time | Arrival Time | Turnaround Time | Waiting Time | Complete Time |");
//     puts("+-----+------------+--------------+-----------------+--------------+---------------+");

//     for (int i = 0; i < n; i++) {
//         printf("| %2d  |     %2d     |      %2d      |        %2d       |      %2d      |      %2d       |\n"
//             , p[i].pid, p[i].brust_time, p[i].arrival_time, p[i].turnaround_time, p[i].waiting_time, p[i].complete_time);
//         puts("+-----+------------+--------------+-----------------+--------------+---------------+");
//     }
// }