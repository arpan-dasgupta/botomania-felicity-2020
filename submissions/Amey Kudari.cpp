#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define rep(n) for(ll i=0;i<(n);i++)
#define jrep(n) for(ll j=0;j<(n);j++)
#define all(a) (a).begin(), (a).end()
#define dpp(a) cout<<(a).first<<" "<<(a).second<<endl;
#define append push_back
#define mod 1000000007
#define ff first
#define ss second
#define ffast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fast ios::sync_with_stdio(0);
ll pw(ll x,ll y,ll p=mod){ll r=1; x=x%p;while(y>0){ if(y&1)r=(r*x)%p;
y=y>>1;x=(x*x)%p;} return r; } vector<ll> uniq(vector<ll> arr)
{vector<ll>brr;sort(all(arr));brr.append(arr[0]);
for(auto i:arr)if(brr.back()!=i)brr.append(i);return brr;}


vector<vector<ll>> arr; ll player;
ll mm=0;

ll right(ll a,ll b){
    ll flips = 0;
    ll tf=0;
    for(ll i=b+1;i<10;i++){
        if(arr[a][i]==0){ return 0; }
        if(arr[a][i]==player) return flips;
        flips++;
    }
    return 0;
}
ll left(ll a,ll b){
    ll flips = 0;
    ll tf=0;
    for(ll i=b-1;i>=0;i--){
        if(arr[a][i]==0){ return 0; }
        if(arr[a][i]==player) return flips;
        flips++;
    }
    return 0;
}
ll up(ll a,ll b){
    ll flips = 0;
    ll tf=0;
    for(ll i=a-1;i>=0;i--){
        if(arr[i][b]==0){ return 0; }
        if(arr[i][b]==player) return flips;
        flips++;
    }
    return 0;
}

ll down(ll a,ll b){
    ll flips = 0;
    for(ll i=a+1;i<10;i++){
        if(arr[i][b]==0){ return 0; }
        if(arr[i][b]==player) return flips;
        flips++;
    }
    return 0;
}

ll dul(ll a,ll b){
    ll flips = 0;
    a--; b--;
    while(min(a,b)>=0){
        if(arr[a][b]==0){ return 0; }
        if(arr[a][b]==player){ return flips; }
        flips++;
        a--; b--;
    }
    return 0;
}
ll dur(ll a,ll b){
    ll flips = 0;
    a--; b++;
    while(min(a,b)>=0&&max(a,b)<10){
        if(arr[a][b]==0){ return 0; }
        if(arr[a][b]==player){ return flips; }
        flips++;
        a--; b++;
    }
    return 0;
}
ll ddr(ll a,ll b){
    ll flips=0;
    a++; b++;
    while(min(a,b)>=0&&max(a,b)<10){
        if(arr[a][b]==0){ return 0; }
        if(arr[a][b]==player){ return flips; }
        flips++;
        a++; b++;
    }
    return 0;
}
ll ddl(ll a,ll b){
    ll flips=0;
    a++; b--;
    while(min(a,b)>=0&&max(a,b)<10){
        if(arr[a][b]==0){ return 0; }
        if(arr[a][b]==player){ return flips; }
        flips++;
        a++; b--;
    }
    return 0;
}

ll totm(ll a,ll b){
    return right(a,b) + left(a,b) + up(a,b) + down(a,b) + dul(a,b) + dur(a,b) + ddr(a,b) + ddl(a,b);
}
ll totd(ll a,ll b){
    return dul(a,b) + dur(a,b) + ddr(a,b) + ddl(a,b);
}
pair<ll,ll> move(){
    pair<ll,ll> opt; opt.ff=-1; opt.ss=-1;
    ll co=-1;
    if(mm==0) co=100000000;
    rep(10) jrep(10) if(arr[i][j]==0&&totm(i,j)>0){
        ll a = totm(i,j);
        if(mm==0){
            if(a<co){
                co=a; opt.ff=i; opt.ss=j;
            } else if(a==co&&totd(i,j)>totd(opt.ff,opt.ss)){
                co=a; opt.ff=i; opt.ss=j;
            }
        } else {
            if(a>co){
                a=co; opt.ff=i; opt.ss=j;
            } else if(a==co&&totd(i,j)>totd(opt.ff,opt.ss)){
                co=a; opt.ff=i; opt.ss=j;
            }
        }
        //cout<<i<<" "<<j<<" => "<<a<<endl;
    }
    return opt;
}

void solve(){
    jrep(10){
        vector<ll> tmp(10); rep(10) cin>>tmp[i];
        arr.append(tmp); 
    }
    cin>>player; 
    ll tot=0;
    rep(10) jrep(10) if(arr[i][j]==0) tot++;
    if(tot<75) mm=1;
    auto ret = move();
    cout<<ret.ff<<"\n"<<ret.ss<<endl;
    //for(auto i:arr){
    //    for(auto j:i) cout<<j<<" "; cout<<endl;
    //}
    //cout<<player<<endl;
}
 
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    ffast
    ll t=1;
    //cin>>t;
    rep(t) solve();
}
 
 
// *p.find_by_order(n) : nth value (0 indexed)
// p.order_of_key(7): index of 7 (0 indexed)
