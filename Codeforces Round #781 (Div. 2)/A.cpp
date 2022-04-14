//problem tag :Codeforces Round #781 (Div. 2)
//problem name :A
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
        if(n%4==0)
        {
            lli x=n/4;
            cout<<x<<" "<<x<<" "<<x<<" "<<x<<"\n";
        }
        if(n%4==1)
        {
            lli x=n/4;
            cout<<x<<" "<<(2*x)<<" "<<x<<" "<<1<<"\n";
        }
        if(n%4==2)
        {
            
            cout<<(n-3)<<" "<<1<<" "<<1<<" "<<1<<"\n";
        }
        if(n%4==3)
        {
            lli x=n/4;
            cout<<(2*x)<<" "<<(2*x+1)<<" "<<1<<" "<<1<<"\n";
        }
    }
    fileclose
    return 0;
}

