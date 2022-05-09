//problem tag :codeforces
//problem name :A. Subtle Substring Subtraction
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

        string s;
        cin >> s;
        lli sum = 0;
        for (char c : s)
            sum += (c - 'a' + 1);
        lli a, b;
        if(s.length()==1)
        {
            a=0;
            b=sum;
        }
        else if (s.length() % 2 == 0)
        {
            a = sum, b = 0;
        }
        else
        {
            a=max(sum-(s[0]-'a'+1),sum-(s[s.length()-1]-'a'+1));
            b=sum-a;
        }
        if(a>b)
        {
            cout<<"Alice ";
        }
        else
            cout<<"Bob ";
        printli(abs(a-b));
    }
    fileclose
    return 0;
}
