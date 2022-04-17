//problem tag :Not solved
//problem name :Maximum Distance
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

using namespace std;
int turnOn(int x, int pos) {
    return x | (1 << pos);
}

bool isOn(int x , int pos) {
    return (bool)(x & (1 << pos));
}
struct node_data
{
    lli suff[2],pref[2];
    node_data()
    {
        suff[0]=suff[1]=0;
        pref[0]=pref[1]=0;
    }
};
lli n,q;
lli arr[2][mx];
node_data tree[mx * 4];
lli Minp(lli x,lli y)
{
    if(x==-1)
        return y;
    if(y==-1)
        return x;
    if(arr[0][x]<arr[0][y])
        return x;
    return y;
}
lli Mins(lli x,lli y)
{
    if(x==-1)
        return y;
    if(y==-1)
        return x;
    if(arr[1][x]<arr[1][y])
        return x;
    return y;
}
lli Maxp(lli x,lli y)
{
    if(x==-1)
        return y;
    if(y==-1)
        return x;
    if(arr[0][x]>arr[0][y])
        return x;
    return y;
}
lli Maxs(lli x,lli y)
{
    if(x==-1)
        return y;
    if(y==-1)
        return x;
    if(arr[1][x]>arr[1][y])
        return x;
    return y;
}
node_data Merge(node_data node1,node_data node2)
{
    node_data node;
    node.pref[0]=Minp(node1.pref[0],node2.pref[0]);
    node.pref[1]=Maxp(node1.pref[1],node2.pref[1]);
    node.suff[0]=Mins(node1.suff[0],node2.suff[0]);
    node.suff[1]=Maxs(node1.suff[1],node2.suff[1]);
    return node;
}
void init(lli node, lli b, lli e)
{
    if (b == e) 
    {
        tree[node].pref[0]=tree[node].pref[1] = b;
        tree[node].suff[0]=tree[node].suff[1] = b;
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;

    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node]=Merge(tree[Left],tree[Right]);
}
node_data query(lli node, lli b, lli e, lli i, lli j)
{
    node_data ret;
    if (i > e || j < b)//out of range
    {
        ret.suff[0]=ret.pref[0]=-1;
        ret.suff[1]=ret.pref[1]=-1;
        return ret; 
    }
    if (b >= i && e <= j)
        return tree[node]; //relevent segment

    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;

    node_data ret1, ret2;
    ret1 = query(Left, b, mid, i, j);
    ret2 = query(Right, mid + 1, e, i, j);

    return ret=Merge(ret1,ret2);
}


int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {


        scanf("%lld",&n);
        lli arrr[n+1];
        frep(i,1,n)
        {
            scanf("%lld",&arrr[i]);
        }
        frep(i,1,n)
        {
            arr[0][0]=0;
            arr[0][i]=arr[0][i-1]+arrr[i];
        } 
        frev(i,n,1)
        {
            arr[1][n+1]=0;
            arr[1][i]=arr[1][i+1]+arrr[i];
        }

        init(1,1,n); 
        scanf("%lld",&q);
        while(q--)
        {

            lli i,j;
            scanf("%lld %lld",&i,&j);
            node_data ret=query(1, 1, n, i, j);
            lli ret1=abs(arr[0][ret.pref[0]]-arr[1][ret.suff[1]]);
            lli ret2=abs(arr[1][ret.suff[0]]-arr[0][ret.pref[1]]);
            if(ret1>ret2)
                printf("%lld %lld\n",ret.pref[0],ret.suff[1]);
            else
                printf("%lld %lld\n",ret.pref[1],ret.suff[0]);
            
        }
    }
    fileclose
    return 0;
}