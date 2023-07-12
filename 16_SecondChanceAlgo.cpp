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
    vector<int>frames(numOfFrames, -1);

    printf("\n");

    printf("\tString");
    for(int i = 0;i<numOfFrames;i++) printf("\tFrame %d",i+1);
    printf("\n");

    int framePointer = 0;
    bool isHit = false;
    map<int,bool> referenceBit;

    for(int i = 0; i < numOfPages; i++)
    {
        isHit = false;
        for(auto x: frames)
        {
            if(x == pages[i])
            {
                isHit = true;
                referenceBit[x] = true;
                break;
            }
        }    
        if(!isHit)
        {
            //Miss, need to replace
            while(true)
            {
                if(frames[framePointer] == -1)
                {
                    frames[framePointer] = pages[i];
                    framePointer = (framePointer + 1) % numOfFrames;
                    break;
                }
                else if(referenceBit[frames[framePointer]] == true)
                {
                    referenceBit[frames[framePointer]] = false;
                    framePointer = (framePointer + 1) % numOfFrames;
                }
                else
                {
                    frames[framePointer] = pages[i];
                    framePointer = (framePointer + 1) % numOfFrames;
                    break;
                }
            }
        }
        printf("\t%d",pages[i]);
        for(int j = 0;j<numOfFrames;j++)
        {
            printf("\t%d",frames[j]);
        }
        printf("\n");
    }

}