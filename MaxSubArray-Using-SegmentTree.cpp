struct SegmentTree{
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
private:
    struct Node{
        ll pre,suf,mx,sum;
        Node():pre(-1e14),suf(-1e14),sum(-1e14),mx(-1e14){}
        Node(ll val):pre(val),suf(val),sum(val),mx(val){}
    };
    vector<Node>seg;ll sz;
    Node merge(Node &a,Node &b)
    {
        Node ret;
        ret.sum=a.sum+b.sum;
        ret.pre=max(a.pre,a.sum+b.pre);
        ret.suf=max(b.suf,b.sum+a.suf);
        ret.mx=max({ret.sum,a.mx,b.mx,a.suf+b.pre});
        return ret;
    }
    void build(int l,int r,int node,vector<ll>&arr)
    {
        if(l==r)
        {
            if(l<arr.size())
            {
                seg[node]=Node(arr[l]);
            }
            return;
        }
        build(l,mid,L,arr);
        build(mid+1,r,R,arr);
        seg[node]=merge(seg[L],seg[R]);
    }
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node]=Node(val);
            return;
        }
        if(idx<=mid)
        {
            update(l,mid,L,idx,val);
        }
        else
        {
            update(mid+1,r,R,idx,val);
        }
        seg[node]=merge(seg[L],seg[R]);
    }
public:
    SegmentTree(vector<ll>&arr)
    {
        int n=arr.size();
        sz=1;
        while(sz<n)
        {
            sz<<=1;
        }
        seg=vector<Node>(sz<<1,Node());
        build(0,sz-1,0,arr);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query()
    {
        return seg[0].mx;
    }
#undef L
#undef R
#undef mid
};