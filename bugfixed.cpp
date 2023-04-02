#include <bits/stdc++.h>
using namespace std;


int n,m,i,j;
int process[100],available[100],req[100], maxi[100][100],allocation[100][100], need[100][100],work[100];
vector<int>seq;


bool isSafety(){
    vector <int> finish(n,0);
    seq.clear();
    int it = 0;
    while (it<n){
        bool marker = false;
        for (i=0;i<n;i++){
            if (!finish[i]){
                for (j=0;j<m;j++){
                    if (need[i][j]>work[j])
                        break;
                }
                if (j == m){
                    for (j=0;j<m;j++){
                        work[j]+=allocation[i][j];
                    }
                    seq.push_back(i);
                    it++;
                    finish[i] = 1;
                    marker = true;
                }
            }
        }
        if (marker == false) return false;


    }
    return true;

}
bool resourceReq(int pn){

    for (i=0;i<n;i++){
        available[i]-=req[i];
        allocation[pn][i]+=req[i];
        need[pn][i]-=req[i];
    }

    if (isSafety()) return true;
    else{
        for (i=0;i<n;i++){
            available[i]+=req[i];
            allocation[pn][i]-=req[i];
            need[pn][i]+=req[i];
        }
        return false;
    }
}

int main(){
    freopen("BankersAlgoInput.txt","r",stdin);
    cout<<"Enter the number of process"<<endl;
    cin>>n;
    cout<<"Enter the number of resourses"<<endl;
    cin>>m;


    for (int i=0;i<n;i++){
            cin>>process[i];
        for (int j=0;j<m;j++){
            cin>>allocation[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>maxi[i][j];
            need[i][j] = maxi[i][j] - allocation[i][j];
        }
    }
    for (int i=0;i<m;i++){
            cin>>available[i];
            work[i] = available[i];
        }
        if (isSafety()){
            int test = 1;
            while (test--){
                for (int i=0;i<m;i++){
                    work[i] = available[i];
                }
                int pn;
                cin>>pn;
                for (i=0;i<m;i++)
                    cin>>req[i];
                bool valid = true;
                for (i=0;i<m;i++){
                    if (req[i]>need[pn][i]){
                        valid = false;
                        break;
                    }
                }
                if (valid == false) continue;
                for (i=0;i<m;i++){
                    if (req[i]>available[i]){
                        valid = false;
                        break;
                    }
                }

                if (valid == false) continue;
                if (resourceReq(pn)){
                    cout<<"The resource req is granted"<<endl;
                    for (i=0;i<n;i++)
                        cout<<seq[i]<<" ";
                    cout<<endl;
                }
                else cout<<"not granted"<<endl;
            }
        }
        else
            cout<<"There is no safe seq"<<endl;

}

/*
5
3
0 0 1 0
1 2 0 0
2 3 0 2
3 2 1 1
4 0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
1
1 0 2
*/
