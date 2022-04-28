//problem tag :codeforces,dfs
//problem name :D. Harmonious Graph
#include<bits/stdc++.h>
#define mx                          200005
#define lli                         long long int
#define ulli                        unsigned long long int
#define mset(a,b)                   memset(a, b, sizeof(a))
#define infile                      freopen("in.txt", "r", stdin);
#define outfile                     freopen ("out.txt","w",stdout);
#define fileclose                   fclose (stdin); fclose (stdout);
#define test_case                   lli T; cin>>T;for(lli t=1;t<=T;t++)
#define scani(x)                    scanf("%d",&x);
#define printi(x)                   printf("%d\n",x);
#define scanli(x)                   scanf("%lld",&x);
#define printli(x)                  printf("%lld\n",x);
#define frep(i,from,to)             for(lli i=from;i<=to;i++)
#define frev(i,from,to)             for(lli i=from;i>=to;i--)

using namespace std;
int turnOn(int x, int pos) {
    return x | (1 << pos);
}

bool isOn(int x , int pos) {
    return (bool)(x & (1 << pos));
}
int n, m, u, v,cnt = 0, maxi = -1;

bool visited[mx];
vector<int>graph[mx];
void dfs(int node)
{
    visited[node]=1;

    maxi=max(maxi,node);

    lli len=graph[node].size();
    frep(child,0,len-1)
    {
        if(!visited[graph[node][child]]) 
            dfs(graph[node][child]);
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {

        scani(n);
        scani(m);
        frep(i,1,m) 
        {
            scani(u);
            scani(v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        frep(i,1,n) 
        {
            if(visited[i])continue;

            if (i < maxi) cnt++;
            dfs(i);
        }
        printi(cnt);
    }
    fileclose
    return 0;
}
