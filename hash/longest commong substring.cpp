//problem tag :hash
//problem name :longest commong substring
//complexity: O((n^2)long(n))
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
lli bigmod(lli base, lli power, lli mod)
{
    if (power == 0)
        return 1;
    lli ret = bigmod(base, power / 2, mod);
    ret *= ret;
    if (power % 2)
        ret *= (base % mod);
    return ret % mod;
}

int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {
        string s1, s2;
        cin >> s1 >> s2;

        lli base = 27;
        lli mod = 1000000007;
        lli len1 = s1.length() - 1;
        lli len2 = s2.length() - 1;

        lli cumsum1[len1+2];
        lli cumsum2[len2+2];

        lli ret=0;
        frep(i, 0, len1)
        {
            ret += (s1[i] - 'a' + 1) * bigmod(base, i, mod);
            ret %= mod;
            cumsum1[i + 1] = ret;   
        }

        ret=0;
        frep(i, 0, len2)
        {
            ret += (s2[i] - 'a' + 1) * bigmod(base, i, mod);
            ret %= mod;
            cumsum2[i + 1] = ret;
        }

        len1++;
        len2++;
        lli l=1,r=min(len2,len1);
        lli ans=0;
        cumsum1[0]=cumsum2[0]=0;
        while(l<=r)
        {
            bool flag=false;
            lli mid=(l+r)/2;

            frep(i,1,len1-mid+1)
            {
                frep(j,1,len2-mid+1)
                {
                    if((cumsum1[i+mid-1]-cumsum1[i-1])==(cumsum2[j+mid-1]-cumsum2[j-1]))
                    {
                        ans=max(ans,mid);
                        l=mid+1;
                        flag=true;
                        break;
                     }
                }
                if(flag)
                    break;
            }
           
            if(!flag)
                r=mid-1;
        }

        cout<<"ans "<<ans<<"\n";
    }
    fileclose
    return 0;
}

