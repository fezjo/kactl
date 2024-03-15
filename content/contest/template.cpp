#include <bits/stdc++.h>
using namespace std;

// #define MANY_TESTS ll TC; cin >> TC; while (TC--)
#define For(i, lo, hi) for (ll i = lo; i < (ll)(hi); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)size(x))
#define vec vector
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (ll)1.1e18 - 1;

template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& c) {
  return os << "(" << c.first << ", " << c.second << ")";
}
template <class A, class B, class C>
basic_ostream<A, B>& operator<<(basic_ostream<A, B>& os, const C& c) {
  for (auto it = begin(c); it != end(c); ++it)
    os << (it == begin(c) ? "" : " ") << *it;
  return os;
}
template <class... Args>
void dbg(Args&& ...args) {
  ((cerr << args << " | "), ...);
  cerr << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}
