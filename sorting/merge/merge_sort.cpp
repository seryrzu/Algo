#include <cstdio>
#include <vector>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; ++i)
typedef vector<int> vi;

const int N = 1e4;
const int M = 1e4;
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

#include <ctime>  
#include <cstdlib>
#include <cassert>
#include <algorithm>

int main() {
	/*int n;
	scanf("%d", &n);
	vi a(n);
	forn(i, n)
		scanf("%d", &a[i]);
	vi b = merge_sort(a, 0, n - 1);
	forn(i, n)
		printf("%d ", b[i]);
*/
	std::srand ( unsigned ( std::time(0) ) );
  	vi a(N), b;
	forn(i, N)
		a[i] = i; 
	forn(_, M) {
		random_shuffle(a.begin(), a.end());
		a = merge_sort(a, 0, N - 1);
		//std::sort(a.begin(), a.end());
		forn(i, N)
			assert(a[i] == i);
	}
}