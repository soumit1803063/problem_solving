//problem tag :misc
//problem name :codeforces-1651B
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
lli n;
lli a[200005], b[200005];
lli f(lli node, lli type)
{
    lli ret = INT_MAX;

    frep(k, 1, n)
    {   if (type == 0)
            ret = min(ret, abs(a[node] - b[k]));
        else
            ret = min(ret, abs(b[node] - a[k]));
    }
    return ret;
}
lli fun1()
{
    lli ret=INT_MAX;
    ret = min(ret,abs(a[1] - b[1]) + abs(a[n] - b[n]));
    ret = min(ret,abs(a[1] - b[n]) + abs(a[n] - b[1]));
    return ret;

}
lli fun2()
{
    lli ret=INT_MAX;
    ret=min(ret,abs(a[1]-b[1])+f(n,0)+f(n,1));
    ret=min(ret,abs(a[n]-b[n])+f(1,0)+f(1,1));
    ret=min(ret,abs(a[1]-b[n])+f(n,0)+f(1,1));
    ret=min(ret,abs(a[n]-b[1])+f(1,0)+f(n,1));
    return ret;
}
lli fun3()
{
    return f(1,0)+f(n,0)+f(1,1)+f(n,1);
}
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {


        cin >> n;

        frep(i, 1, n)
        {
            cin >> a[i];
        }
        frep(i, 1, n)
        {
            cin >> b[i];
        }
        cout << (min(fun3(), min(fun1(), fun2()))) << "\n";

    }
    fileclose
    return 0;
}

