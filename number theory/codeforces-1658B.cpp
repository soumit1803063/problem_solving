//problem tag :number theory
//problem name :codeforces-1658B
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
    return x | (1<<pos);
}

bool isOn(int x ,int pos) {
    return (bool)(x & (1<<pos));
}
lli mod=998244353;
lli fac[1001];
int main()
{

    #ifndef ONLINE_JUDGE
    infile
    outfile
    #endif // ONLINE_JUDGE
    
    fac[0]=1;
    frep(i,1,1000)
    {
        fac[i]=((fac[i-1]%mod)*(i%mod))%mod;
    }
    test_case
    {
        lli n;
        cin>>n;
        if(n%2)
            cout<<"0\n";
        else
            cout<<((fac[n/2]*fac[n/2])%mod)<<"\n";

    }
    fileclose
    return 0;
}

