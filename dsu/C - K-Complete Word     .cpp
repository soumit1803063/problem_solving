//problem tag :codeforces,dsu
//problem name :C - K-Complete Word     
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


int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {
        
        lli n,k;
        scanf("%lld %lld",&n,&k);
        frep(i,0,n)
        {
            make_set(i);
        }
        string s;
        cin>>s;
        lli l=0,r=n-1;
        frep(i,0,n-1)
        {
            if(l<=r)
            {
                union_sets(l,r);
                l++;
                r--;
            }
            if(i-k>=0)
            {
                union_sets(i,i-k);
            }
            
        }
        lli color[n][26];
        frep(i,0,n-1)
        {
            frep(j,0,25)
            {
                color[i][j]=0;
            }
        }
        lli i=0;
        set<lli> st;
        for(char c:s)
        {
            color[find_set(i)][(c-'a')]++;
            st.insert(find_set(i));
            i++;
        }

        lli ans=0;
        for(lli e:st)
        {
            lli sum=0,maxi=-1;
            frep(i,0,25)
            {
              
                sum+=color[e][i];
                maxi=max(maxi,color[e][i]);
            }
            ans+=(sum-maxi);
        }

        cout<<ans<<"\n";

    }
    fileclose
    return 0;
}
