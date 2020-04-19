class data
{
public:
    int mx;
    data()
    {
        this->mx = INT_MIN;
    }
};

const int N=100005;
int a[N];
data seg[N<<2];

//update as required
void merge(data &cur, data &l, data &r) 
{
    cur.mx = min(l.mx, r.mx); 
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        //update as required
        seg[node].mx = a[start];
        return ;
    }
    int mid = (start+end)>>1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        //update as required
        a[idx] += val;
        seg[node].m += val;
        return;
    }
    int mid = (start + end)>>1;
    if(start <= idx && idx <= mid)
        update(node<<1, start, mid, idx, val);
    else
        update(node<<1|1, mid+1, end, idx, val);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);

}

data query(int node, int start, int end, int l, int r)
{
    if(r<start || end<l)
    {
        // range represented by a node is completely outside the given range
        data d;
        return d;
    }
    if(l<=start && end<=r)
    {
        // range represented by a node is completely inside the given range
        return seg[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end)>>1;
    data p1 = query(node<<1, start, mid, l, r);
    data p2 = query(node<<1|1, mid+1, end, l, r);
    data p;
    merge(p,p1,p2);
    return p;
}
/*
indexing or array is from 0,n-1
for(int i=0;i<n;i++)cin>>a[i];
build(1,0,n-1);
cin >> x >> y;
cout<<query(1,0,n-1,x-1,y-1)<<endl;
update(1,0,n-1,x-1,y);
for(int i=1; i<=2*n; i++)
{
    cout << i << ":" sp seg[i].maxi sp seg[i].secmaxi << endl;
}
*/
