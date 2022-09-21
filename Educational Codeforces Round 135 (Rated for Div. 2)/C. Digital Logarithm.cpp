//problem tag :Educational Codeforces Round 135 (Rated for Div. 2)
//problem name :C. Digital Logarithm
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
int turnOn(int x, int pos) {
    return x | (1 << pos);
}

bool isOn(int x , int pos) {
    return (bool)(x & (1 << pos));
}

lli digit(lli x)
{
    lli ret = 0;
    while (x)
    {
        x /= 10;
        ret++;
    }
    return ret;
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
        scanli(n);
        priority_queue<lli> aq, bq;
        frep(i, 1, n)
        {
            lli x;
            scanli(x);
            aq.push(x);
        }
        frep(i, 1, n)
        {
            lli x;
            scanli(x);
            bq.push(x);
        }

        lli ans = 0;
        while ((!aq.empty()) && (!bq.empty()))
        {

            lli t1 = aq.top();
            aq.pop();

            lli t2 = bq.top();
            bq.pop();


            if (t1 != t2)
            {
                ans++;
                if (t1 > t2)
                {
                    aq.push(digit(t1));
                    bq.push(t2);
                }
                else
                {
                    aq.push(t1);
                    bq.push(digit(t2));
                }
            }

        }
        printli(ans);
    }
    fileclose
    return 0;
}
