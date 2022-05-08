//problem tag :codechef,segment tree
//problem name :Sereja and D (Problem Code: SEAD)
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
lli arr[mx], tree[mx * 4];
void init(lli node, lli b, lli e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = max(tree[Left], tree[Right]);
}
lli query(lli node, lli b, lli e, lli i, lli j)
{
    if (i > e || j < b)
        return 0; //out of range
    if (b >= i && e <= j)
        return tree[node]; //relevent segment

    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;

    lli ret1, ret2;
    ret1 = query(Left, b, mid, i, j);
    ret2 = query(Right, mid + 1, e, i, j);
    return max(ret1, ret2);
}

int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {

        lli n;
        scanli(n);
        vector<lli>v;
        frep(i, 0, n - 1)
        {
            lli x;
            scanli(x);
            v.push_back(x);
            if (i > 0)
                arr[i] = v[i] - v[i - 1];
        }
        if (n > 1)
            init(1, 1, n - 1);
        lli q;
        scanli(q);
        while (q--)
        {
            lli c, d;
            scanli(c);
            scanli(d);
            lli r = upper_bound(v.begin(), v.end(), c) - v.begin();
            r--;
            lli ans = r + 1;
            lli hi = r, lo = 1;
            while (lo <= hi)
            {
                lli mid = (lo + hi) / 2;
                if (query(1, 1, n - 1, mid, r) <= d)
                {
                    ans = min(ans, mid);
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            printli(ans);
        }
    }
    fileclose
    return 0;
}
