#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo \
    { no return; }

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template <typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
    vector<T> a = vector<T>(n + oneIndexed);

    for (ll i = 0; i < n; i++) {
        T p;
        cin >> p;
        a[i + oneIndexed] = p;
    }

    return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        // printf("%lu ", a[i]);
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T, typename A>
void papair(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        // printf("%lu ", a[i]);
        cout << a[i].first << " " << a[i].second << endl;
    }
}

ll check(vv grid, ll row, ll col, ll player) {
    int tot = 0;
    if (grid[row][col] == player)
        return 0;
    for (ll i = row + 1; i < 10; i++) {
        if (grid[i][col] == 0)
            break;
        if (grid[i][col] == player) {
            tot += (i - row - 1);
            break;
        }
    }
    for (ll i = col + 1; i < 10; i++) {
        if (grid[row][i] == 0)
            break;
        if (grid[row][i] == player) {
            tot += (i - col - 1);
            break;
        }
    }
    for (ll i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 0)
            break;
        if (grid[i][col] == player) {
            tot += (row - 1 - i);
            break;
        }
    }
    for (ll i = col - 1; i >= 0; i--) {
        if (grid[row][i] == 0)
            break;
        if (grid[row][i] == player) {
            tot += (col - 1 - i);
            break;
        }
    }
    int i, j;
    i = row + 1, j = col + 1;
    while (i < 10 && j < 10) {
        if (grid[i][j] == 0)
            break;
        if (grid[i][j] == player) {
            tot += (i - row - 1);
            break;
        }
        i++, j++;
    }
    i = row + 1, j = col - 1;
    while (i < 10 && j >= 0) {
        if (grid[i][j] == 0)
            break;
        if (grid[i][j] == player) {
            tot += (i - row - 1);
            break;
        }
        i++, j--;
    }
    i = row - 1, j = col + 1;
    while (i >= 0 && j < 10) {
        if (grid[i][j] == 0)
            break;
        if (grid[i][j] == player) {
            tot += (row - i - 1);
            break;
        }
        i--, j++;
    }
    i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (grid[i][j] == 0)
            break;
        if (grid[i][j] == player) {
            tot += (row - i - 1);
            break;
        }
        i--, j--;
    }
    return tot;
}

void solve() {
    vv grid(10);
    ll x;
    for (ll i = 0; i < 10; i++) {
        for (ll j = 0; j < 10; j++) {
            cin >> x;
            grid[i].push_back(x);
        }
    }
    ll player;
    cin >> player;
    ll best = 0;
    pll move = {-1, -1};
    for (ll i = 0; i < 10; i++) {
        for (ll j = 0; j < 10; j++) {
            ll rv = check(grid, i, j, player);
            if (rv != -1) {
                if (rv > best) {
                    best = rv;
                    move = {i, j};
                }
            }
        }
    }
    cout << move.first << '\n' << move.second << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}