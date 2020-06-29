#include <bits/stdc++.h>
using namespace std;

//Handle:cyber_rajat
void update(int index, int value, vector<int>& BIT, int n)
{
	for(;index<=n;index+=(index&(-index)))
	{
		BIT[index]+=value;
	}
}

int query(int index, vector<int>& BIT)
{
	int sum=0;
	for(;index>0;index-=(index&(-index)))
	{
		sum+=BIT[index];
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> BIT(n+1,0);
	//1-based Indexing of array
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		update(i,a[i],BIT,n);
	}
	//queries
	int q;
	cin >> q;
	while(q--)
	{
		//Sum in Range[l,r]
		int l, r;
		cin >> l >> r;
		//In BIT Tree, in a particular index [1,indx] is stored and hence to compute
		//[l,r] we can [1,r]-[1,l-1];
		cout << query(r,BIT) - query(l-1,BIT) << endl;
	}
	return 0;
}
