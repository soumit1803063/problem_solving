//problem tag :codeforces,dp
//problem name :C. Palindrome Basis
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
vector<lli> p;
lli dp[40005][500];
lli n;
lli mod=1000000007;
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    frep(i, 1, 9)
    {
        p.push_back(i);
    }
    frep(i, 1, 9)
    {
        p.push_back(11 * i);
    }
    frep(i, 1, 9)
    {
        frep(j, 0, 9)
        {
            p.push_back(i * 100 + j * 10 + i);
        }
    }
    frep(i, 1, 9)
    {
        frep(j, 0, 9)
        {
            lli temp = i * 1000 + j * 100 + j * 10 + i;
            p.push_back(temp);
        }
    }
    frep(i, 1, 4)
    {
        frep(j, 0, 9)
        {
            frep(k, 0, 9)
            {
                lli temp = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                if (temp < 40000)
                    p.push_back(temp);
            }

        }
    }

    frep(i,0,p.size()-1)
        dp[0][i] = 1;
    frep(i,1,40000)
    {
        dp[i][0] = 0;
        frep(j,0,p.size()-1)
        {
            dp[i][j+1] = dp[i][j];
            if (p[j] <= i)
                dp[i][j+1] +=dp[i - p[j]][j+1]% mod;
                dp[i][j+1]%=mod;
                
        }
    }
    test_case
    {
        scanli(n);
        printli(dp[n][p.size()]);

    }
    fileclose
    return 0;
}
