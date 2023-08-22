#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long
const int DIM = 100007;
const ll INF = 1000000000000;
typedef pair<ll, ll> pairll;
vector<pairll> d[DIM];
priority_queue<pairll, vector<pairll>, greater<pairll> > priq;
ll n, start, finish;
ll a[DIM], b[DIM], c[DIM];

void getinputdata() {
    ll m, v1, v2, dd;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> v1 >> v2 >> dd;
        d[v1].push_back({v2, dd});
        d[v2].push_back({v1, dd});
    }
    cin >> start >> finish;
}

void algo_Dejkstra() {
    ll v, to, dd;
    for (ll i = 1; i <= n; i++) {
        a[i] = 0;
        b[i] = INF;
        c[i] = 0;
    }
    b[start] = 0;
    priq.push({0, start});
    while (!priq.empty()) {
        v = priq.top().second;
        priq.pop();
        if (a[v] == 1) continue;
        a[v] = 1;
        for (auto x: d[v]) {
            to = x.first;
            dd = x.second;
            if (b[v] + dd < b[to]) {
                b[to] = b[v] + dd;
                c[to] = v;
                priq.push({b[to], to});
            }
        }
    }
}

void fastiooper() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void getoutotputdata() {
    if (b[finish] == INF) cout << -1 << endl;
    else cout << b[finish] << endl;
}

int main() {
    fastiooper();
    getinputdata();
    algo_Dejkstra();
    getoutotputdata();
    return 0;
}