//problem tag :codeforces,game theory
//problem name :A - Log Chopping 
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

using namespace std;
int turnOn(int x, int pos) {
    return x | (1 << pos);
}

bool isOn(int x , int pos) {
    return (bool)(x & (1 << pos));
}
lli dp[51];
lli fun(lli x)
{
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    lli &ret=dp[x];
    if(ret!=-1)
        return ret;
    if(x%2==1)
        return ret=1+fun(x-1);
    else
        return ret=1+2*fun(x/2);
}
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    mset(dp,-1);
    test_case
    {
        
        lli n;
        lli mv = 0;
        scanli(n);
        frep(i, 1, n)
        {
            lli x;
            scanli(x);
            mv+=fun(x);
        }
  
        if(mv%2==1)
            printf("errorgorn\n");
        else
            printf("maomao90\n");

    }
    fileclose
    return 0;
}

