//problem tag :codeforces
//problem name :C - Tokitsukaze and Strange Inequality 
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
        scanli(n);
        lli arr[n + 1], mat[n + 1][n + 1];
        mset(mat, 0);

        frep(i, 1, n)
        {
            scanli(arr[i]);
        }
        frep(b, 1, n)
        {
            frep(d, b + 1, n)
            {
                mat[b][d] = mat[b][d - 1] + (arr[b] > arr[d]);

            }
        }
        frep(b, 1, n)
        {
            frep(d, b + 1, n)
            {
                mat[b][d] += mat[b-1][d];

            }
        }
        lli ans = 0;
       
        frep(c,1,n)
        {
           
            frep(a,1,c-1)
            {
                if(arr[a]<arr[c] && c<n)
                {
                    
                    ans+=((mat[c-1][n]-mat[a][n])-(mat[c-1][c]-mat[a][c]));
                }
            }
            
        }
        printli(ans);
    }
    fileclose
    return 0;
}
