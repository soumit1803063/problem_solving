//problem tag :Codeforces Round #821 (Div. 2)
//problem name :C. Parity Shuffle Sorting
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
#define CASE                        printf("Case %lld: ",t);
#define nn                          printf("\n");

using namespace std;
int turnOn(int x, int pos) {
    return x | (1 << pos);
}

bool isOn(int x , int pos) {
    return (bool)(x & (1 << pos));
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
        cin>>n;
        lli arr[n+1];
        frep(i,1,n)
        {
            cin>>arr[i];
        }
        if(n==1)
        {
            cout<<"0\n";

        }
        else
        {
            
        vector<pair<lli,lli> > v;
        v.push_back({1,n});
        bool f=true;
        if((arr[1]+arr[n])%2==1)
        {
            arr[n]=arr[1];
        }
        else
        {
            arr[1]=arr[n];
        }
        frep(i,2,n-1)
        {
            if((arr[i]+arr[1])%2==1)
                v.push_back({1,i});
            else
                v.push_back({i,n});

        }
        cout<<(v.size())<<"\n";
        for(auto e: v)
            cout<<(e.first)<<" "<<(e.second)<<"\n";
        }
        
    }
    fileclose
    return 0;
}
