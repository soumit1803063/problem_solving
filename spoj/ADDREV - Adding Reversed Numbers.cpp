//problem tag :spoj
//problem name :ADDREV - Adding Reversed Numbers
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
    return x | (1<<pos);
}

bool isOn(int x ,int pos) {
    return (bool)(x & (1<<pos));
}
int main()
{

    #ifndef ONLINE_JUDGE
    infile
    outfile
    #endif // ONLINE_JUDGE
    test_case
    {
        string s1,s2;
        cin>>s1>>s2;
       
        lli len1=s1.length()-1,len2=s2.length()-1;
        lli len=max(len1,len2);
        lli carry=0;
        lli isleading=true;
        frep(i,0,len)
        {
            lli sum=carry;
            if(i<=len1)
                sum+=(lli)(s1[i]-'0');
            if(i<=len2)
                sum+=(lli)(s2[i]-'0');
            lli w=sum%10;
            sum/=10;
            carry=sum%10;
            if(w!=0)
            {
                isleading=false;
                cout<<w;
            }
            else
            {
                if(!isleading)
                    cout<<w;
            }
        }
        if(carry!=0)
            cout<<carry;
        cout<<"\n";
    }
    fileclose
    return 0;
}

