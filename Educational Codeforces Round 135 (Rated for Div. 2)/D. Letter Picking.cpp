//problem tag :Educational Codeforces Round 135 (Rated for Div. 2)
//problem name :D. Letter Picking
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
lli dp[2005][2005];
string s;
lli cost(lli i, lli j)
{
    if (s[i] < s[j])
        return 1;
    if (s[i] > s[j])
        return -1;
    return 0;
}
lli fun(lli i, lli j)
{
    
    if(i>=j){

        return 0;
    }

    lli &ret = dp[i][j];
    if (ret != -2)
        return ret;

    lli c1 = cost(i, j);
    lli c2 = cost(i, i + 1);
    lli c3 = cost(j, i);
    lli c4 = cost(j, j - 1);


    lli ret1=fun(i+1,j-1);
    lli ret2=fun(i+2,j);
    lli ret3=fun(i+1,j-1);
    lli ret4=fun(i,j-2);
    
    /*cout<<i<<","<<j<<"\n";
   cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<"\n";
    cout<<ret1<<" "<<ret2<<" "<<ret3<<" "<<ret4<<"\n\n";*/

    if(((ret1==1 || (ret1==0 && c1==1))&&(ret2==1 || (ret2==0 && c2==1))) || ((ret3==1 || (ret3==0 && c3==1))&&(ret4==1 || (ret4==0 && c4==1)))) 
        ret=1;
    else if(((ret1==-1 || (ret1==0 && c1==-1))||(ret2==-1 || (ret2==0 && c2==-1))) && ((ret3==-1 || (ret3==0 && c3==-1))||(ret4==-1 || (ret4==0 && c4==-1))))  
        ret=-1;    
    else
        ret=0;
    return ret;
}
int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    test_case
    {


        string ans[3] = {"Bob","Draw", "Alice"};

        cin >> s;

        lli i = 0, j = s.length() - 1;
       
        frep(k,0,j+1)
        frep(l,0,j+1)
        dp[k][l]=-2;
        cout<<ans[fun(i,j)+1]<<"\n";
    
    }
    fileclose
    return 0;
}
