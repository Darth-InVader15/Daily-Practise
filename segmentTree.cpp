#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ull unsigned long long
#define ll long long 
#define forn(n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

int mod = 1e9+7;

struct node
{
	int sum;
	node()
	{
		sum = 0;
	}
};

node merge(node a, node b)
{
	node ans;
	ans.sum = max(a.sum, b.sum);
	return ans;
}

node t[4*200200]; //hmesa size k 4 times lete hai, kyuki perfectly balanced tree nhi banta 
int arr[200200];
void build(int id, int l, int r)
{
	if(l==r)
	{
		//leaf node
		t[id].sum = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id +1,mid+1,r);
	t[id] = merge(t[2*id],t[2*id +1]);
}

void update(int id, int l, int r,int pos, int val)
{
	if(pos<l || pos>r)	return; //if not in range
	if(l==r)
	{
		//leaf node
		t[id].sum -= (val);
		return;
	}
	int mid = (l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	t[id] = merge(t[2*id],t[2*id+1]);
}
int query(int id, int l, int r, int req)
{
	if(t[id].sum < req)	return -1; //we dont have that many rooms

	if(l == r)	return l; //leaf node so we are returnig the index where we will be assigning the room
	int mid = (l+r)/2;

	if(t[2*id].sum >= req)
	{
		return query(2*id,l,mid,req);	//we are left biased so as to assign least surplus of rooms
	}
	else return query(2*id+1,mid+1,r,req);
}

//This code is the solution for CSES 
//here rather than a array we use segment treee


int32_t main()
{
	fast_cin();

	int n,q;
	cin>>n>>q;

	// int arr[n];

	forn(n){
		cin>>arr[i];
	}

	build(1,0,n-1); //build a 0 indexed segment tree

	while(q--)
	{
		int req;
		cin>>req;
		int id = query(1,0,n-1,req);
		if(id != -1)
		{
			update(1,0,n-1,id,req); //if room was alloted then we remove that many room from our hotel
		}
		cout<<id+1<<" "; //answer is 1 based indexed
	}
	cout<<endl;

}