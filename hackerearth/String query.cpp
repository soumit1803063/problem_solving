//problem tag :hackerearth,segment tree
//problem name :String query
#include<bits/stdc++.h>
#define mx                          200005
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
struct Node{
    lli digit[26];
    Node()
    {
        mset(digit, 0);
    }
};
Node sum(Node a, Node b)
{
    Node temp;
    frep(i, 0, 25)
    {
        temp.digit[i] = a.digit[i] + b.digit[i];
    }
    return temp;
}
Node tree[mx * 4];
string s;

void init(lli node, lli b, lli e)
{
    if (b == e) {
        tree[node].digit[s[b] - 'a'] = 1;
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = sum(tree[Left], tree[Right]);
}
void update(lli node, lli b, lli e, lli d, lli cnt)
{
    if (b == e) {
        tree[node].digit[d] = 0;
        s[b]='#';
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    if (tree[Left].digit[d] >= cnt)
        update(Left, b, mid, d, cnt);
    else
        update(Right, mid + 1, e, d, cnt - tree[Left].digit[d]);
    tree[node] = sum(tree[Left], tree[Right]);
}


int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {

        cin>>s;
        lli b=0,e=s.length()-1;
        init(1,b,e);
        lli q;
        scanli(q);
        while(q--)
        {
            lli pos,d;
            char c;
            cin>>pos>>c;
            d=c-'a';
            update(1,b,e,d,pos);
        }
        for(char c: s)
        {
            if(c!='#')
                cout<<c;
        }
        nn;
    }
    fileclose
    return 0;
}
