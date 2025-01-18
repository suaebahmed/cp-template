#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
#define int long long
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define lowb(a, x) lower_bound(all(a),x)
#define sz(v) (int)v.size()
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
#define vi vector<int>
#define cinv(a) for(auto &x: a) cin>>x
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
const int N = 2e5 + 5, inf = 1e9;
// https://codeforces.com/contest/1999/problem/G2

int ask(int a, int b){
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    int x; cin>>x;
    return x;
}

void solve(){
    int l = 1, r = 1000;
    while(l < r){
        int mid1 = l + (r - l)/3;
        int mid2 = r - (r - l)/3;

        int res  = ask(mid1, mid2);
        if(mid1 * mid2 == res){
            l = mid2 + 1;
        }
        else if(res % mid1 == 0 && mid2 + 1 == (res/mid1)){
            l = mid1 + 1;
            r = mid2;
        }  
        else{
            r = mid1;
        }
    }
    cout<<"! "<<r<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}