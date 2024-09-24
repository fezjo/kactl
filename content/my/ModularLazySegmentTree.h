/**
 * Author: fezjo
 * Date: 2024-09-24
 * License: CC0
 * Source: own but based on https://github.com/kth-competitive-programming/kactl/pull/228
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Time: O(\log N).
 * Usage: ST st(n); ST st(arr); st.add(lo, hi, x); st.set(lo, hi, x); st.query(lo, hi);
 * Status: tested on CSES-1735
 */

struct ST {
	using Num = int; using T = Num; struct L { Num mset, madd; };
	const Num NOP = -1;	
	const T tneut = 0; const L lneut = {NOP, 0};
	T ftt(T a, T b) { return a + b; }
	void ftl(T& t, L l, int len) {
		if (l.mset != NOP) t = l.mset * len;
		t += l.madd * len;
	}
	void fll(L& a, L b) {
		if (b.mset != NOP) a = b;
		else a.madd += b.madd;
	}
	int n; vector<T> val; vector<L> lazy;
	ST(int _n) : n(__bit_ceil(_n)),
	             val(2*n, tneut), lazy(2*n, lneut) {}
	ST(const vector<T>& a) : ST(size(a)) {
		copy(a.begin(), a.end(), val.begin() + n);
		for (int i = n - 1; i > 0; i--)
			val[i] = ftt(val[i*2], val[i*2+1]);
	}
	void push(int cur, int len) {
		// if (lazy[cur] == lneut) return;
		ftl(val[cur], lazy[cur], len);
		if (cur < n) for (int i: {0, 1})
			fll(lazy[cur*2+i], lazy[cur]);
		lazy[cur] = lneut;
	}
	T query(int qlo, int qhi, int tv, int tlo, int thi) {
		if (tlo >= qhi || thi <= qlo) return tneut;
		push(tv, thi - tlo);
		if (tlo >= qlo && thi <= qhi) return val[tv];
		int tmid = (tlo + thi) / 2;
		return ftt(query(qlo, qhi, tv*2, tlo, tmid),
               query(qlo, qhi, tv*2+1, tmid, thi));
	}
	void update(int qlo, int qhi, L x, int tv, int tlo, int thi){
		if (tlo >= qlo && thi <= qhi) {
			fll(lazy[tv], x); push(tv, thi - tlo); return;
		}
		push(tv, thi - tlo);
		if (tlo >= qhi || thi <= qlo) return;
		int tmid = (tlo + thi) / 2;
		update(qlo, qhi, x, tv*2, tlo, tmid);
		update(qlo, qhi, x, tv*2+1, tmid, thi);
		val[tv] = ftt(val[tv*2], val[tv*2+1]);
	}
	T query(int l, int r) { return query(l, r, 1, 0, n); }
	void add(int l, int r, Num x) { update(l,r,{NOP,x},1,0,n); }
	void set(int l, int r, Num x) { update(l,r,{ x, 0},1,0,n); }
};