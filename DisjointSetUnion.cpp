#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Rep(i,n) for(ll i=0; i<int(n); ++i)
#define read(v) for (auto &it : v) cin >> it;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(s) s.size()
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb emplace_back
#define deb(x) cout<<"For debug : "<<x<<endl;
#define lowb(a, x) (lower_bound((a).begin(),(a).end(),(x))-(a).begin())
#define uppb(a, x) (upper_bound((a).begin(),(a).end(),(x))-(a).begin())
typedef long long ll;
#define ld long double
#define endl '\n'
#define mod 1000000007
const int N=1e5+10, INF=INT_MAX;

struct disjoint{
    vector<int> p, sz;
    void Build(int n) {
        p.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            p[i] = i;
        }
    }
    int Find(int x) {
        if(x != p[x]) p[x] = Find(p[x]);
        return p[x];
    }
    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
    int Size(int n) {
        return sz[Find(n)];
    }
};

void solve(){
    int n; cin>>n;
    
}

int main(){
    optimize();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt=1;
    // scanf("%d",&tt);cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}