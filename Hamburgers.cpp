#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

bool checkPossibility(ll mid, ll nb_r, ll ns_r, ll nc_r,
                      ll nb, ll ns, ll nc,
                      ll pb, ll ps, ll pc,
                      ll rubles) {
    ll numb = max(0LL, nb_r * mid - nb);
    ll nums = max(0LL, ns_r * mid - ns);
    ll numc = max(0LL, nc_r * mid - nc);

    ll cost = 1LL * numb * pb + 1LL * nums * ps + 1LL * numc * pc;
    return cost <= rubles;
}

int main() {
    string recipe;
    cin >> recipe;

    ll nb, ns, nc, pb, ps, pc, rubles;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rubles;

    ll nb_r = 0, ns_r = 0, nc_r = 0;
    for (char c : recipe) {
        if (c == 'B') nb_r++;
        else if (c == 'S') ns_r++;
        else if (c == 'C') nc_r++;
    }

    ll low = 0, high = 1e13, ans = 0; // 1e13 to be safe for large inputs
    while (low <= high) {
        ll mid = (low + high) / 2;

        if (checkPossibility(mid, nb_r, ns_r, nc_r, nb, ns, nc, pb, ps, pc, rubles)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}