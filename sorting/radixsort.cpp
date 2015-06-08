#include <cstdio>
#include "radixsort.h"
#include <algorithm>

#define forn(i, n) for(int i = 0; i < n; ++i)

const int BASE_POW = 16;
const int BASE = 1 << BASE_POW;
const int BASE_MOD = BASE - 1;

const int MAX_POW = 32 / BASE_POW;
const int INF = (int) 1e9; // max value of a number

typedef vector<int> vi;

void radix_sort(vi & a) {
  forn(i, a.size())
     a[i] += INF;
  vi count(BASE), b(a.size());
  for(int k = 0; k < MAX_POW; ++k) {
    fill(count.begin(), count.end(), 0);
    forn(i, a.size())   // counting sort
      count[(a[i] >> (k * BASE_POW)) & BASE_MOD]++;
    for(int i = 1; i < BASE; ++i)
      count[i] += count[i - 1];
    for(int i = a.size() - 1; i >= 0; --i) // sort digit
      b[--count[(a[i] >> (k * BASE_POW)) & BASE_MOD]] = a[i];
    a.swap(b);
  }
  forn(i, a.size())
     a[i] -= INF;
}
