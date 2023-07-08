#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("input.txt","r",stdin);
    // fastio
    int numOfFrames,pages[50],numOfPages,numOfPageFault;

    printf("Enter number of Pages: ");
    cin>>numOfPages;
    printf("Enter the sequence of %d pages: ",numOfPages);
    for(int i = 0;i<numOfPages;i++) scanf("%d",&pages[i]);

    printf("Enter number of Frames: ");
    cin>>numOfFrames;

    printf("\n");

    vector<int>frames;
    map<int,int>leastRecentIndex;

    for(int i = 0;i<numOfPages;i++)
    {
        if(frames.size() < numOfFrames)
        {
            bool isExist = false;
            for(int j = 0;j<frames.size();j++)
            {
                if(frames[j]==pages[i]) isExist = true;
            }
            leastRecentIndex[pages[i]] = i;
            if(isExist==0)
            {
                frames.push_back(pages[i]);
            }
        }
        else{ 
            bool isExist = false;
            for(int j = 0;j<frames.size();j++)
            {
                if(frames[j]==pages[i]) isExist = true;
            }
            leastRecentIndex[pages[i]] = i;
            if(isExist == 1)
            {
                leastRecentIndex[pages[i]] = i;
            }
            else
            {
                int index;
                int val = i+1;
                for(int j = 0;j<numOfFrames;j++)
                {
                    if(leastRecentIndex[frames[j]] < val)
                        index = j, val = leastRecentIndex[frames[j]];
                }
                frames[index] = pages[i];
                leastRecentIndex[pages[i]] = i;
            }
        }
        int j = 0;
        for(j = 0;j<frames.size();j++)
        {
            printf("%d, ",frames[j]);
        }
        for(; j < numOfFrames;j++)
            printf("-1");
        cout<<endl;
    }

}
/*
input:
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
 