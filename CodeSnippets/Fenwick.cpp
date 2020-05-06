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
