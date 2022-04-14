//problem tag :misc
//problem name :codeforces-1647B
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
        lli R, C;
        bool flag = true;
        cin >> R >> C;

        bool mat[R + 1][C + 1];
        frep(r, 1, R)
        {
            string s;
            cin >> s;
            frep(c, 1, C)
            {
                mat[r][c] = (bool)(s[c - 1] - '0');

            }

        }

        frep(r, 1, R)
        {

            frep(c, 1, C)
            {
                if (mat[r][c])
                {
                    if ((r - 1 > 0 && mat[r - 1][c] && c + 1 <= C && !mat[r - 1][c + 1] && mat[r][c + 1]))
                        flag = false;
                    if ((r + 1 <= R && mat[r + 1][c] && c + 1 <= C && !mat[r + 1][c + 1] && mat[r][c + 1]))
                        flag = false;
                    if ((r - 1 > 0 && c - 1 > 0 && !mat[r - 1][c - 1] && mat[r - 1][c] && mat[r][c - 1]))
                        flag = false;
                    if ((r + 1 <= R && c - 1 > 0 && !mat[r + 1][c - 1] && mat[r + 1][c] && mat[r][c - 1]))
                        flag = false;
                }


            }

        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    fileclose
    return 0;
}

