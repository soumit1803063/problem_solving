//problem tag :15-295
//problem name :C. Omkar and Last Class of Math
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

int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {
        lli n, b = INT_MAX, a;
        cin >> n;
        for (lli i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                lli a1=i,a2=n/i;
                lli b1=(a2-1)*a1,b2=(a1-1)*a2;
                if(b1>0)
                    b=min(b1,b);
                if(b2>0)
                    b=min(b2,b);

            }
        }
        printf("%lld %lld\n",b,n-b);
    }
    fileclose
    return 0;
}
