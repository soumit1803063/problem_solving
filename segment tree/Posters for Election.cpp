//problem tag :LightOJ,segment tree
//problem name :Posters for Election
#include<bits/stdc++.h>
#define mx                          200005
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
lli tree[mx * 4];
set<lli> s;
void init(lli node, lli b, lli e)
{
    tree[node] = 0;
    if (b == e) {
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);

}
void update(lli node, lli b, lli e, lli i, lli j, lli newvalue)
{
    if (i > e || j < b)
        return; //out of range
    if (b >= i && e <= j)
    {
        tree[node] = newvalue; //relevent segment
        return;
    }

    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    if (tree[node] != 0)
    {
        tree[Left] = tree[Right] = tree[node];
        tree[node] = 0;
    }

    update(Left, b, mid, i, j, newvalue);
    update(Right, mid + 1, e, i, j, newvalue);
}
void query(lli node, lli b, lli e)
{

    if (b == e) {
        if(tree[node]!=0)
            s.insert(tree[node]);
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    if (tree[node] != 0)
    {
        tree[Left] = tree[Right] = tree[node];
        tree[node] = 0;
    }
    query(Left, b, mid);
    query(Right, mid + 1, e);

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
        init(1,1,2*n);
        lli l, r;
        frep(i,1,n)
        {
            scanli(l);
            scanli(r);
            update(1,1,2*n,l,r,i);
        }
        s.clear();
        query(1,1,2*n);
        CASE;
        lli ans=s.size();
        printli(ans);
     

    }
    fileclose
    return 0;
}
