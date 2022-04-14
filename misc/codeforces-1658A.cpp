//problem tag :misc
//problem name :codeforces-1658A
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
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {
        lli n;
        string s;
        vector<lli> v;
        cin >> n >> s;
        lli ans = 0;
        frep(i,0,n-1) 
        {
            if (s[i] == '0') 
                v.push_back(i);
        }

        lli len=(lli)v.size()-1;
        frep(i,1,len)
        {
            if (v[i] - v[i-1] <= 2) 
                ans += 3 - v[i] + v[i-1];
        }
        cout << ans << '\n';
    }
    fileclose
    return 0;
}

