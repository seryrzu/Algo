#include "merge_sort.h"

using namespace std;
#define forn(i, n) for(int i = 0; i < n; ++i)

vi merge(const vi &lm, const vi &mr) {
	int lms = lm.size(), mrs = mr.size();
	vi mm(lms + mrs);
	int i = 0, j = 0, k = 0;
	while(i < lms && j < mrs)
		mm[k++] = lm[i] <  mr[j] ? lm[i++] : mr[j++];
	while(i < lms)
		mm[k++] = lm[i++];
	while(j < mrs)
		mm[k++] = mr[j++];
	return mm;
}

vi merge_sort(const vi &a, const int l, const int r) {
	if (l > r) return vi(0);
	if (l == r) {
		vi res(1, a[l]);
		return res;
	}
	int mid = (l + r) / 2;
	vi lm = merge_sort(a, l, mid);
	vi mr = merge_sort(a, mid + 1, r);
	return merge(lm, mr);
}

