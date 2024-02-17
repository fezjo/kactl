#include <bits/stdc++.h>
using namespace std;

#define For(i, lo, hi) for(ll i = lo; i < (ll)(hi); ++i)
#define sz(x) ((ll)size(x))
#define all(x) begin(x), end(x)
#define vec vector
using ll = long long;
const ll INF = (ll)1.1e18 - 1;

template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}
template <typename A, typename B, typename C>
basic_ostream<A, B>& operator<<(basic_ostream<A, B>& os, const C& c) {
	for (auto it = begin(c); it != end(c); ++it)
		os << (it == begin(c) ? "" : " ") << *it;
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& c) {
	for (auto it = begin(c); it != end(c); ++it)
		os << (it == begin(c) ? "" : "\n") << *it;
	return os;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
}