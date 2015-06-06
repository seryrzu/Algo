#include <cstdio>
#include <algorithm>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; ++i)
const int N = 1e5;

int partition(int a[], int l, int r) {
  int x = a[l], i = l - 1, j = r + 1;
  while (true) {
    do i++; while(a[i] < x);
    do j--; while(a[j] > x);
    if (i < j) swap(a[i], a[j]);
    else return j; 
  }
}

void quicksort(int a[], int l, int r) {
  if (l < r) {
    int p = partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
 }
}
