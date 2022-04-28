//problem tag :toph,dsu
//problem name :Unbelievable Array
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

lli parent[mx], siz[mx];
lli root[mx],value[mx];
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


int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {

        lli n, q;
        scanf("%lld %lld", &n, &q);

        mset(root, -1);
        frep(i, 1, n)
        {
            make_set(i);
        }

        frep(i, 1, n)
        {
            scanli(value[i]);

            if (root[value[i]] == -1)
            {
                root[value[i]] = i;
            }
            else
            {
                union_sets(root[value[i]],i);
                root[value[i]]=find_set(i);
            }
        }
        printf("Case %lld:\n",t);
        while (q--)
        {
            lli type;
            scanli(type);

            if (type == 1)
            {
                lli x, y;
                scanli(x);
                scanli(y);

                if (root[x] == -1 || x==y)
                {
                    continue;
                }
                else if (root[y] == -1)
                {
                    value[root[x]]=y;
                    root[y]=root[x];
                    root[x]=-1;

                }
                else
                {
                   
                    union_sets(root[x],root[y]);
                    lli boss=find_set(root[x]);
                    value[boss]=y;
                    root[y]=boss;
                    root[x]=-1;                }

            }
            else 
            {
                lli idx;
                scanli(idx)
                printli(value[find_set(idx)]);
                
            }
        }
    }
    fileclose
    return 0;
}
