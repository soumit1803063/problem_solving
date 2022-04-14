//problem tag :LightOJ,trie
//problem name :Consecutive Sum
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

int arr[ 50005];
struct node {
    bool endmark;
    node* next[2];
    node()
    {
        endmark = false;
        next[0] = next[1] = NULL;
    }
} * root;
void insert(int num, int len)
{
    node* curr = root;

    frev(i, len - 1, 0)
    {
        int id = isOn(num, i);
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
int search(int num, int len, bool option )
{
    node* curr = root;
    int xr = 0;
    frev(i, len - 1, 0)
    {
        int id = isOn(num, i);
        if (option)
            id = !id;
    
        if (curr->next[id] == NULL)
        {

            curr = curr->next[!id];
            xr=turnOn(xr,i);
            continue;
        }
        curr = curr->next[id];

    }
    if(option)
        return ~(xr);
    return xr;
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
    test_case
    {
        root = new node();
        int n;
        cin >> n;
        arr[0] = 0;
        frep(i, 1, n)
        {
            cin >> arr[i];
            arr[i]^= arr[i - 1];

        }
        int mini = arr[1], maxi = arr[1];


        insert(arr[1], 32);
        frep(i, 2, n)
        {

            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
            mini = min(search(arr[i], 32, false), mini);
            maxi = max(search(arr[i], 32, true), maxi);
            insert(arr[i], 32);
        }
        printf("Case %lld: %d %d\n",t,maxi,mini);
        del(root);
    }
    fileclose
    return 0;
}