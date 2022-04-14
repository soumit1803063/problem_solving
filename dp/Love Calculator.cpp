//problem tag :LightOJ,dp
//problem name :Love Calculator
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
lli dp1[35][35],dp2[35][35];
string s1, s2;
lli l1, l2;
lli fun1(lli i, lli j)
{
    if (i == l1 || j == l2)
        return 0;
    lli &ret = dp1[i][j];
    if (ret != -1)
        return ret;
    ret = 0;
    if (s1[i] == s2[j])
        ret = 1 + fun1(i + 1, j + 1);
    else
        ret = max(fun1(i + 1, j), fun1(i, j + 1));
    return ret;
}
lli fun2(lli i, lli j)
{
    
    lli &ret = dp2[i][j];
    

    if (i == l1 || j == l2)
        return ret=1;

    if (ret != -1)
        return ret;

    ret = 0;
    if (s1[i] == s2[j])
        ret = fun2(i + 1, j + 1);
    else
    {

        lli ret1=fun1(i + 1, j);
        lli ret2=fun1(i, j + 1);
        if(ret1==ret2)
            ret=fun2(i+1,j)+fun2(i,j+1);
        else if(ret1>ret2)
            ret=fun2(i+1,j);
        else
            ret=fun2(i,j+1);
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
        
        
        cin >> s1 >> s2;
        l1 = s1.length();
        l2 = s2.length();
        mset(dp1, -1);
        lli ans1= l1 + l2 - fun1(0, 0);
        mset(dp2, -1);
        lli ans2=fun2(0,0);
        printf("Case %lld: %lld %lld\n", t,ans1,ans2);
        
    }
    fileclose
    return 0;
}

