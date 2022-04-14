//problem tag :codeforces,trie
//problem name :Vasiliy's Multiset
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
struct node {
    bool endmark;
    lli counter;
    node* next[2];
    node()
    {
        counter = 0;
        endmark = false;
        frep(i, 0, 1)
        next[i] = NULL;
    }
} * root;
void insert(lli num)
{
    lli len = 31;
    node* curr = root;
    frev(i, len, 0)
    {
        lli id = isOn(num, i);
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->counter++;
    }
    curr->endmark = true;
}
void Remove(lli num)
{
    lli len = 31;
    node* curr = root;
    frev(i, len, 0)
    {
        lli id = isOn(num, i);
        curr = curr->next[id];
        curr->counter--;
    }

    if (curr->counter == 0)
        curr->endmark = false;
}
lli search(lli num)
{
    node* curr = root;
    lli len = 31;
    lli xr = 0;
    frev(i, len, 0)
    {
        lli id = !isOn(num, i);

        if (curr->next[id] == NULL || curr->next[id]->counter==0)
        {

            curr = curr->next[!id];
            xr = turnOn(xr, i);
            continue;
        }
        curr = curr->next[id];

    }

    return ~(xr);

}
void del(node* cur)
{
    for (int i = 0; i < 2; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
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
        lli n;
        scanf("%lld", &n);
        char type;
        lli x = 0;
        insert(x);
        while (n--)
        {

            scanf(" %c %lld", &type, &x);
            if (type == '+')
            {
                insert(x);
            }
            else if (type == '-')
            {
                Remove(x);
            }
            else
            {
                cout << (search(x)) << "\n";

            }
        }
        fileclose
        return 0;
    }
}

