#include <cstdio>
#include <algorithm>
#include "heapsort.h"
using namespace std;

#define forn(i, n) for(int i = 0; i < n; ++i)
const int N = (int) 1e5;
int a[N], n;

void sift_down(int heap_size, int i) {
  int l = 2 * i + 1, r = 2 * (i + 1);
  if (l >= heap_size) return;
  int m = (a[l] < a[i] ? i : l);
  if (r < heap_size && a[m] < a[r]) m = r;
  if (m == i) return;
  swap(a[m], a[i]);
  sift_down(heap_size, m);
}

void build_heap() {
  for(int i = n / 2; i >= 0; --i)
    sift_down(n, i);
}

void heap_sort() {
	int heap_size = n;
	build_heap();
	while(heap_size--) {
		swap(a[0], a[heap_size]);
	  sift_down(heap_size, 0);
  }
}

