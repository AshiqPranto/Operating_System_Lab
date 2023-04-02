/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include<bits/stdc++.h>
 
#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define f0(x) for(ll i = 0;i<=x;i++)
#define f1(x) for(ll i = 1;i<=x;i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define matrix(x) vector<vector<x>>
#define vss vector<string>
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
#define sf(a)   scanf("%d",&a)
#define sfl(a)  scanf("%lld",&a)
#define sff(a,b)    scanf("%d %d",&a,&b)
#define sffl(a,b)   scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define ms(a,b) memset(a, b, sizeof(a))
#define ff  first
#define ss  second
#define lcm(a, b)   ((a)*((b)/__gcd(a,b)))
#define all(a)  a.begin(),a.end()
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define gap " "
#define mx 104
#define inf (ll)1e17
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1
#define mod 1000000007
#define MOD(a,b) (a%b + b)%b
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
void eff()
{
    
}
 
int main()
{
    freopen ("input.txt","r",stdin);
    // fastio
    int numOfFrames,pages[50],numOfPages,frames[50],numOfPageFault;

    printf("Enter number of Pages: ");
    cin>>numOfPages;
    printf("Enter the sequence of %d pages: ",numOfPages);
    for(int i = 0;i<numOfPages;i++) scanf("%d",&pages[i]);

    printf("Enter number of Frames: ");
    cin>>numOfFrames;
    printf("\n");

    //initializes all frames value with -1
    for(int i = 0;i<numOfFrames;i++) frames[i] = -1;

    printf("\tString");
    for(int i = 0;i<numOfFrames;i++) printf("\tFrame %d",i+1);
    printf("\n");

    int pointerOfFrame = 0;//this variable will point to the current index of frame
    int available = 0;
    for(int i = 0;i<numOfPages;i++)
    {
        printf("\t   %d",pages[i]);
        available = 0;
        //Search if current page is in the frame or not
        for(int j = 0;j<numOfFrames;j++)
        {
            if(frames[j]==pages[i])
            {
                available = 1;
                break;
            }
        }
        // If we don't find pages in the frame then we need to process the algorithm
        if(!available)
        {
            frames[pointerOfFrame] = pages[i];
            pointerOfFrame = (pointerOfFrame+1)%numOfFrames;
            numOfPageFault++;
        }
        for(int j = 0;j<numOfFrames;j++)
        {
            printf("\t%d",frames[j]);
        }
        printf("\n");
    }
    
    return 0;
}
