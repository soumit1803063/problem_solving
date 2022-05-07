//problem tag :codeforces,dsu
//problem name :C - Where is the Pizza
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
lli mod=1000000007;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
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
        frep(i,0,n)
        {
            make_set(i);
        }
        lli a[n+1],b[n+1],c[n+1];
        frep(i,1,n)scanli(a[i]);
        frep(i,1,n)
        {
            scanli(b[i]);
            union_sets(a[i],b[i]);
        }
        map<lli, lli> m;
        frep(i,1,n)
        {
            scanli(c[i]);
            if(c[i]!=0)
                m[find_set(c[i])]=1;
        }
        map<lli,lli> mp;
        frep(i,1,n)
        {
            mp[find_set(i)]++;
        }
        lli ans=0;
        frep(i,1,n)
        {
            if(m[i]!=1 && mp[i]>1)
            {
                ans++;
            }
        }
        ans=binpow(2,ans,mod);
        printli(ans);


    }
    fileclose
    return 0;
}
