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
lli n, k;

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

lli search(node* cur, bool isLarge, lli pos, lli num)
{
	if (cur->endmark or isLarge)
		return cur->counter;
	lli ret = 0;
	frep(i, 0, 1)
	{
		if ((cur->next[i]) and (i ^ isOn(num, pos)) >= isOn(k, pos))
		{
			ret += search(cur->next[i], isLarge | ((i ^ isOn(num, pos)) > isOn(k, pos)), pos - 1, num);
		}
	}
	return ret;


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
		scanf("%lld %lld",&n,&k);
		lli xr = 0;
		lli ans = 0;
		insert(0);
		frep(i, 1, n)
		{
			lli x;
			scanf("%lld",&x);
			xr ^= x;

			ans += search(root, false, 31, xr);
			insert(xr);
		}

		printf("%lld\n",ans);




	}
	fileclose
	return 0;
}
