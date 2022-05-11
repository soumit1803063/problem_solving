//problem tag :codechef,bitwise
//problem name :XORGAND
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
lli msb(lli x)
{
    frev(i,31,0)
    {
        if(isOn(x,i))
            return i+1;
    }
    return 0;
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
        lli mat[33][n+1];
        mset(mat,0);
        frep(i,1,n)
        {
            frep(j,0,32)
            {
                mat[j][i]=mat[j][i-1];
            }
            lli x;
            scanli(x);
            mat[msb(x)][i]++;
        }

        lli q;
        scanli(q);
        while(q--)
        {
            lli l,r,x;
            scanli(l);
            scanli(r);
            scanli(x);
            lli temp=msb(x);
            lli ans=r-l+1;
            ans-=(mat[temp][r]-mat[temp][l-1]);
            printli(ans);

        }

    }
    fileclose
    return 0;
}
