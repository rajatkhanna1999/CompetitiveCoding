#include <bits/stdc++.h>
using namespace std;

//Handle:cyber_rajat

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int index, int value)
	{
		while(index <= N)
		{
			bit[index] += value;
			index += index & -index;
		}
	}

	void updateMax(int index, int value)
	{
		while(index <= N)
		{
			bit[index] = max(bit[index], value);
			index += index & -index;
		}
	}

	int query(int index)
	{
		int ans = 0;
		while(index > 0)
		{
			ans += bit[index];
			index -= index & -index;
		}
		return ans;
	}

	int queryRange(int l, int r)
	{
		return query(r) - query(l - 1);
	}

	int queryMax(int index)
	{
		int ans = -2e9;
		while(index > 0)
		{
			ans = max(ans, bit[index]);
			index -= index & -index;
		}
		return ans;
	}
};

class coder{
	public:
		int first,second,index;
};

bool compare(coder a, coder b)
{
	if(a.first==b.first)
	{
		return a.second<b.second;
	}
	return a.first<b.first;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<coder> a(n+1);
	for(int i=1; i<=n; i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i].index = i;
	}

	//Sort Coders on Basis of X-Values;
	sort(a.begin(),a.end(),compare);
	vector<int> ans(n+1);

	BIT fenw;
	fenw.init(100000);
	for(int i=1; i<=n;)
	{
		//Beacause 1 coder can't be better than other if both X and Y values are same
		int endIndex=i;
		while(endIndex<=n && a[i].first==a[endIndex].first && a[i].second==a[endIndex].second)
		{
			endIndex++;
		}
		//query
		for(int j=i;j<endIndex;j++)
		{
			ans[a[j].index] = fenw.query(a[j].second);
		}

		//update
		for(int j=i;j<endIndex;j++)
		{
			fenw.update(a[j].second,1);
		}
		i=endIndex;
	}
	for(int i=1; i<=n ;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
