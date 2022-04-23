//problem tag :15-295
//problem name :Maximum Subrectangle 
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
    //test_case
    {
            
        lli m,n,ans=0;
        cin>>m>>n;
        lli a[m+1],b[n+1];
        a[0]=b[0]=0;
        frep(i,1,m)
        {
            cin>>a[i];
            a[i]+=a[i-1];
           
        }
       
        
        frep(i,1,n)
        {
            cin>>b[i];
            b[i]+=b[i-1];

        }
        
        lli x;
        cin>>x;

        lli dp1[m+1];
        lli dp2[n+1];
        
        frep(i,0,m)
        dp1[i]=INT_MAX;
        frep(i,0,n)
        dp2[i]=INT_MAX;


        frep(i,1,m)
        {
            frev(j,m,i)
            {
                lli len=j-i+1;
                dp1[len]=min(dp1[len],a[j]-a[i-1]);

            }
        }
        frep(i,1,n)
        {
            frev(j,n,i)
            {
                lli len=j-i+1;
                dp2[len]=min(dp2[len],b[j]-b[i-1]);

            }
        }
        frev(i,m,0)
        {
            frev(j,n,0)
            {
                if(dp1[i]*dp2[j]<=x)
                {
                    //cout<<i<<" "<<dp1[i]<<" "<<j<<" "<<dp2[j]<<"\n";
                    ans=max(ans,i*j);
                    break;
                }
            }
        }
        cout<<ans<<"\n";

    }
    fileclose
    return 0;
}
