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
int a[N],lazy[N<<2];
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
        seg[node].mx = a[start];
        return ;
    }
    int mid = (start+end)>>1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0)
    {
        seg[node].mx+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r)
    {
        seg[node].mx+=(end-start+1)*val;
        if(start!=end)
        {
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

data query(int node,int start,int end,int l,int r)
{
    if(start>end || start>r || end<l)
    {
        // range represented by a node is completely outside the given range
        data d;
        return d;
    }
    if(lazy[node]!=0)
    {
        seg[node].mx+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r)
    {
        // range represented by a node is completely inside the given range
        return seg[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid=(start+end)>>1;
    data p1=query(node<<1,start,mid,l,r);
    data p2=query(node<<1|1,mid+1,end,l,r);
    data p;
    merge(p,p1,p2);
    return p;
}

/*
for(int i=0;i<n;i++)cin>>a[i];
build(1,0,n-1);
cin >> x >> y;
cout<<query(1,0,n-1,x-1,y-1)<<endl;
update(1,0,n-1,x-1,y-1,v);
for(int i=1; i<=2*n; i++)
{
    cout << i << ":" sp seg[i].maxi sp seg[i].secmaxi << endl;
}*/
