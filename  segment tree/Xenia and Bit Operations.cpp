//problem tag :codeforces, segment tree
//problem name :Xenia and Bit Operations
#include<bits/stdc++.h>
#define mx                          131080
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
lli n, q;
lli arr[mx];
lli tree[mx * 4];

void init(lli node, lli b, lli e, bool flag)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    init(Left, b, mid,!flag);
    init(Right, mid + 1, e,!flag);
    if (flag)
        tree[node] = tree[Left] | tree[Right];
    else
        tree[node] = tree[Left] ^ tree[Right];
}

void update(lli node, lli b, lli e, lli i, lli newvalue,bool flag)
{
    if (i > e || i < b)
        return; //out of range
    if (b >= i && e <= i) // relevent segment
    {
        tree[node] = newvalue;
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue,!flag);
    update(Right, mid + 1, e, i, newvalue,!flag);

    if (flag)
        tree[node] = tree[Left] | tree[Right];
    else
        tree[node] = tree[Left] ^ tree[Right];
}

int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {

        scanf("%lld %lld", &n, &q);
        lli nn=n;
        n = pow((lli)2, n);
        
        frep(i, 1, n)
        {
            scanf("%lld", &arr[i]);
        }
        init(1,1,n,(nn%2)==1);
        frep(i,1,q)
        {
            lli index,x;
            scanf("%lld %lld",&index,&x);
            update(1, 1, n, index, x,(nn%2)==1);
            printf("%lld\n",tree[1]);


        }

    }
    fileclose
    return 0;
}
