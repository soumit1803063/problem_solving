//problem tag :misc
//problem name :codeforces-1658C
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
        cin >> n;
        bool flag = true;
        lli one = 0;
        lli arr[n + 1];
        frep(i, 1, n)
        {
            cin >> arr[i];
            if (arr[i] == 1)
                one++;
            if (one > 1 or (i == n and (one == 0 or arr[1] - arr[n] > 1) ))
                flag = false;
            if (i > 1)
            {
                if (arr[i] - arr[i - 1] > 1)
                    flag = false;
            }

        }
        string ans[] = {"NO\n", "YES\n"};
        cout << ans[flag];
    }
    fileclose
    return 0;
}

