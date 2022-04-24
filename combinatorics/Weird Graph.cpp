//problem tag :toph,graph,combinatorics
//problem name :Weird Graph
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



lli parent[mx],siz[mx];
void make_set(lli v) {
    parent[v] = v;
    siz[v] = 1;
}
lli find_set(lli v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(lli a, lli b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

lli  mod=1000000007;

lli fac[mx];
lli fact(lli n)
{
    if(fac[n]!=0)
        return fac[n];
    if(n==0 || n==1)
    {
        return fac[n]=1;
    }
    return fac[n]=((n%mod)*fact(n-1))%mod;
    
}
lli modpow(lli x, lli n, lli m)
{
    if (n == 0)
        return 1%m;
    lli u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1)
        u = (u*x)%m;
    return u;
}

lli nCr(lli n,lli r)
{
    lli a=fact(n);
    lli b = fact(n-r);
    lli c = fact(r);
    b=modpow(b,mod-2,mod);
    c=modpow(c,mod-2,mod);
    return ((a%mod)*((b*c)%mod))%mod;

}
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {
        

        lli v,e;
        scanf("%lld %lld",&v,&e);
        frep(i,1,v)
        {
            make_set(i);
        }
        frep(i,1,e)
        {
            lli u,v;
            scanf("%lld %lld",&u,&v);
            union_sets(u,v);

        }
        map<lli,lli>m;
        frep(i,1,v)
        {
            lli p=find_set(i);
            m[p]=siz[p];
        }
        lli ans=1;
        for(auto e: m)
        {
            ans*=nCr(v,e.second);
            ans%=mod;
            v-=e.second;
        }
        printf("%lld\n",ans);
    }
    fileclose
    return 0;
}
