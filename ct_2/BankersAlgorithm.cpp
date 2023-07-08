#include<bits/stdc++.h>
using namespace std;

int numOfProcess,numOfResource,allocation[100][100],need[100][100],maxi[100][100],work[100],available[100];
int pn,req[100];
vector<int>sequence;

bool isSafeState()
{
    vector<int>finish(numOfProcess+5,0);
    sequence.clear();
    // copy available to work
    for(int i = 0;i<numOfResource;i++) work[i] = available[i];
    for(int z = 0;z<numOfProcess;z++)
    {

        for(int i = 0;i<numOfProcess;i++)
        {
            int j;
            if(finish[i] == true) continue;
            for( j = 0;j<numOfResource;j++)
            {
                if(need[i][j]>work[j]) break;
            }
            if(j!=numOfResource) continue;
            finish[i] = true;
            sequence.push_back(i);
            for( j = 0;j<numOfResource;j++)
            {
                work[j] += allocation[i][j];
            }
        }
    }
    for(int i = 0;i<numOfProcess;i++) 
        if(finish[i] == false) return false;
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);

    printf("Enter the number of process: ");
    scanf("%d",&numOfProcess);
    printf("Enter the number of resource: ");
    scanf("%d",&numOfResource);
    printf("Enter the resource allocation matrix:\n");
    for(int i = 0;i<numOfProcess;i++)
    {
        for(int j = 0;j<numOfResource;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Enter the resource max matrix:\n");
    for(int i = 0;i<numOfProcess;i++)
    {
        for(int j = 0;j<numOfResource;j++)
        {
            scanf("%d",&maxi[i][j]);
        }
    }
    printf("Enter the available resource array: \n");
    for(int i = 0;i<numOfResource;i++)
    {
        scanf("%d",&available[i]);
    }
    //calculate need matrix
    for(int i = 0;i<numOfProcess;i++)
    {
        for(int j = 0;j<numOfResource;j++)
        {
            need[i][j] = maxi[i][j] - allocation[i][j];
        }
    }

    if(isSafeState())
    {
        printf("System is in safe state and following is the safe sequence: \n");
        for(int i = 0;i<numOfProcess-1;i++)
        {
            printf(" P%d -> ",sequence[i]);
        }
        printf(" P%d \n",sequence[numOfProcess-1]);
        
    }
    else{
        printf("The system is in Deadlock...!\n");
    }

}

/*
Input:
5
3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
*/