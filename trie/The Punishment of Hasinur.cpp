//problem tag :Toph,trie
//problem name :The Punishment of Hasinur
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
string ans;
struct node
{
    lli endmark;
    lli guide[2];
    node* next[26];
    node()
    {
        lli len = 25;
        guide[0] = guide[1] = -1;
        endmark = 0;
        frep(i, 0, len)
        next[i] = NULL;
    }
} * root;
lli insert(string s, lli pos, node* curr)
{
    if (pos == s.length())
    {
        curr->endmark++;
        if (curr->endmark >= curr->guide[1])
        {
            curr->guide[0] = -1;
            curr->guide[1] = curr->endmark;
        }
        return curr->guide[1];
    }
    lli id = s[pos] - 'a';
    if (curr->next[id] == NULL)
        curr->next[id] = new node();
    lli ret = insert(s, pos + 1, curr->next[id]);
    if (ret > curr->guide[1])
    {
        curr->guide[1] = ret;
        curr->guide[0] = id;
    }
    if (ret == curr->guide[1])
    {
        curr->guide[0] = min(id,curr->guide[0]);
    }
    return curr->guide[1];
}

void search(node* curr)
{
    if (curr->guide[0] == -1)
    {
        printf(" %lld\n", curr->guide[1]);
        return;
    }
    cout << ((char)(curr->guide[0] + 'a'));
    search(curr->next[curr->guide[0]]);
}

int main()
{

#ifndef ONLINE_JUDGE
    infile
    outfile
#endif // ONLINE_JUDGE
    //test_case
    {
        root = new node();
        lli n, q;
        scanf("%lld", &n);

        frep(i, 1, n)
        {
            string s;
            cin >> s;
            insert(s, 0, root);
        }
        scanf("%lld", &q);

        frep(i, 1, q)
        {
            bool f = true;
            string s;
            cin >> s;
            printf("Case %lld: ", i);
            node* curr = root;
            frep(i, 0, s.length() - 1)
            {
                lli id = s[i] - 'a';
                if (curr->next[id] == NULL)
                    {
                        f=false;
                        break;
                    }
                curr = curr->next[id];
            }
            if (f)
            {
                cout << s;
                search(curr);
            }
            else
                cout << "-1\n";

        }


    }
    fileclose
    return 0;
}
