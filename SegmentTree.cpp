#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Rep(i,n) for(int i=0; i<int(n); ++i)
#define read(v) for (auto &it : v) cin >> it;
#define aint(v) (v).begin(), (v).end()
#define raint(v) (v).rbegin(), (v).rend()
#define sz(s) s.size()
#define ff first
#define ss second
#define pii pair<int, int>
#define pint pair<int, int>
#define vi vector<int>
#define vl vector<int>
#define pb push_back
#define lxb(a, x) (lxer_bound((a).begin(),(a).end(),(x))-(a).begin())
#define uppb(a, x) (upper_bound((a).begin(),(a).end(),(x))-(a).begin())
#define ld long double
#define mod 1000000007
#define endl '\n'
const int MAXN=2*1e5+10;
int a[MAXN];
pair<int,int> seg[4*MAXN];

void build(int x,int lx,int rx){
    if(lx==rx){
        seg[x].ff=1;
        seg[x].ss=a[lx];
        return;
    }
    int mid=(lx+rx)/2;
    build(2*x+1,lx,mid);
    build(2*x+2,mid+1,rx);
    seg[x].ff=seg[2*x+1].ff+seg[2*x+2].ff;
}

int query(int x,int lx,int rx,int l,int r){
    if(l>r) return -1;
    if(l==lx && r==rx){
        return seg[x].ff;
    } 
    int mid=(lx+rx)/2;
    int left=query(2*x+1,lx,mid,l,min(r,mid));
    int right=query(2*x+2,mid+1,rx,max(l,mid+1),r);
    return max(left,right);
}

// another way for query
// int query(int x,int lx,int rx,int l,int r){
//     // complately inside
//     if(lx>=l && rx<=r){ 
//         return seg[x].ff;
//     }
//     //complately outside
//     if(rx<l || lx>r) return 0;
//     //overlap
//     int mid=(lx+rx)/2;
//     int left=query(2*x+1,lx,mid,l,r);
//     int right=query(2*x+2,mid+1,rx,l,r);
//     return (left+right);
// }

void updateAndFind_kth(int x,int lx,int rx,int k){
    if(k>seg[x].ff) return;
    if(lx==rx){
        cout<<seg[x].ss<<" ";
        seg[x].ff=0;
        return;
    }
    int mid=(lx+rx)/2;
    if(seg[2*x+1].ff>=k) updateAndFind_kth(2*x+1,lx,mid,k);
    else updateAndFind_kth(2*x+2,mid+1,rx,k-seg[2*x+1].ff);
    seg[x].ff=seg[2*x+1].ff+seg[2*x+2].ff;
}

/*
    lazy propagation
*/
// int get(int x,int lx,int rx,int pos){
//     if(lx==rx){
//         return seg[x];
//     }
//     push(x);
//     int mid=(lx+rx)/2;
//     if(pos<=mid) return get(2*x,lx,mid,pos);
//     else return get(2*x+1,mid+1,rx,pos);
// }

// void update(int x,int lx,int rx,int l,int r,int addend){
//     if(l>r) return;
//     if(l==lx && r==rx){
//         seg[x] += addend;
//         lazy[x] += addend;
//         deb(seg[x]);
//         return;
//     }
//     push(x);
//     int mid=(lx+rx)/2;
//     update(2*x,lx,mid,l,min(r,mid),addend);
//     update(2*x+1,mid+1,rx,max(l,mid+1),r,addend);
// }

void solve(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(0,0,n-1);
    int q=n;
    while(q--){
        int pos; cin>>pos;
        updateAndFind_kth(0,0,n-1,pos);
    }
}

int main(){
    optimize();
    int tt=1;
    // scanf("%d",&tt);cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}