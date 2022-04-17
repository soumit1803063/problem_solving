//problem tag :codeforces,dp
//problem name :C. Coin Rows
//idea of this solution is very interesting. 
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
lli turnOn(lli x, lli pos) {
    return x | (1 << pos);
}

bool isOn(lli x , lli pos) {
    return (bool)(x & (1 << pos));
}


int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {
        lli n;

        cin>>n;
        lli arr[2][n+1];
        arr[0][0]=arr[1][0]=0;
        frep(i,1,n)
        {
            cin>>arr[0][i];
            arr[0][i]+=arr[0][i-1];
        }
        frep(i,1,n)
        {
            cin>>arr[1][i];
            arr[1][i]+=arr[1][i-1];
        }
        lli ans=INT_MAX;
        frep(i,1,n)
        {
            lli temp=max(arr[0][n]-arr[0][i],arr[1][i-1]);
            ans=min(ans,temp);
        }
        cout<<ans<<"\n";

    }
    fileclose
    return 0;
}
