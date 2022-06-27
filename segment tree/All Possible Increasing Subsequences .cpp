//problem tag :LightOJ,segment tree
//problem name :All Possible Increasing Subsequences 
#include<bits/stdc++.h>
#define mx                          100005
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
#define CASE                        printf("Case %lld: ",t);
#define nn                          printf("\n");

using namespace std;
lli mod=1000000007;
int turnOn(int x, int pos) {
    return x | (1 << pos);
}

bool isOn(int x , int pos) {
    return (bool)(x & (1 << pos));
}
lli tree[mx * 4];
void init(lli node, lli b, lli e)
{
    if (b == e) {
        tree[node] = 0;
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
lli query(lli node, lli b, lli e, lli i, lli j)
{
    if (i > e || j < b)
        return 0; //out of range
    if (b >= i && e <= j)
        return tree[node]%mod; //relevent segment
    
    lli Left = node * 2; 
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;

    lli ret1,ret2;
    ret1 = query(Left, b, mid, i, j);
    ret2 = query(Right, mid + 1, e, i, j);
    return (ret1 + ret2)%mod;
}
void update(lli node, lli b, lli e, lli i, lli newvalue)
{
    if (i > e || i < b)
        return; //out of range
    if (b >= i && e <= i) // relevent segment
    { 
        tree[node] = (tree[node]+newvalue)%mod;
        return;
    }
    lli Left = node * 2; 
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = (tree[Left] + tree[Right])%mod;
}

int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {
        
        
        set<lli>st;
        map<lli, lli> mp;
        lli n;
        scanf("%lld",&n);
        lli arr[n+1];
        frep(i,1,n)
        {
            lli x;
            scanf("%lld",&x);
            st.insert(x);
            arr[i]=x;
        }

        lli i=1;
        for(lli e: st)
        {
            mp[e]=i;
            i++;
        }
        init(1,0,n);
        frep(i,1,n)
        {
            lli l=0,r=mp[arr[i]]-1;
            lli ret=query(1,0,n,l,r)+1;
            ret%=mod;
            update(1,0,n,r+1,ret);

        }
        printf("Case %lld: %lld\n",t,tree[1]);
    }
    fileclose
    return 0;
}

