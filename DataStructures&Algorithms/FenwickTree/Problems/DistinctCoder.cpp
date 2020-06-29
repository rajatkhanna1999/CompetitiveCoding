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
	int x,y,index;
};

bool compare(coder a, coder b)
{
	return a.y<b.y;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	int q;
	cin >> q;
	coder queries[q+1];
	//Offline queries
	for(int i=0; i<q; i++)
	{
		cin>>queries[i].x>>queries[i].y;
		queries[i].index=i;
	}

	sort(queries,queries+q,compare);

	int last[1000005];
	memset(last,-1,sizeof(last));
	vector<int> ans(q+1);
	int total=0,k=0;

	BIT fenw;
	fenw.init(n);
	for(int i=1; i<=n; i++)
	{
		if(last[a[i]]!=-1)
		{
			fenw.update(last[a[i]],-1);
		}
		else
		{
			total++;
		}

		fenw.update(i,1);
		last[a[i]]=i;

		while(k<q && queries[k].y==i)
		{
			ans[queries[k].index] = total - fenw.query(queries[k].x-1);
			k++;
		}

	}
	for(int i=0; i<q; i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
