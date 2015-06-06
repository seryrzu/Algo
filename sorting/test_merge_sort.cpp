#include "merge_sort.h"
#include <gtest/gtest.h>

#include <ctime>  
#include <cstdlib>
#include <algorithm>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; ++i)

const int M = 100; // number of check iterations
const int N = 1e4; // size of the array

TEST(TestMergeSort, SortTest) {
	/*int n;
	scanf("%d", &n);
	vi a(n);
	forn(i, n)
		scanf("%d", &a[i]);
	vi b = merge_sort(a, 0, n - 1);
	forn(i, n)
		printf("%d ", b[i]);
        */
  srand ( unsigned ( time(0) ) );
  vi a(N), b;
	forn(i, N)
		a[i] = i; 
	forn(_, M) {
		random_shuffle(a.begin(), a.end());
		a = merge_sort(a, 0, N - 1);
		//std::sort(a.begin(), a.end());
		forn(i, N)
			ASSERT_TRUE(a[i] == i);
	}
}

TEST(TestMergeSort, SortTest2) {
  vi a(N), b;
  const int K = 10;
  forn(k, K) { 
    forn(i, N)
      a[i] = i & ((1 << k) - 1);
    forn(_, M) {
      random_shuffle(a.begin(), a.end());
      b = merge_sort(a, 0, N - 1);
      std::sort(a.begin(), a.end());
      forn(i, N)
        ASSERT_TRUE(a[i] == b[i]); 
    }
  }
}

TEST(TestMergeSort, SortTest3) {
  vi a(N), b;
  const int K = 10;
  forn(k, K) { 
    forn(i, N)
      a[i] =  i & ((1 << k) - 1) * (i & 1 ? -1 : 1);
    forn(_, M) {
      random_shuffle(a.begin(), a.end());
      b = merge_sort(a, 0, N - 1);
      std::sort(a.begin(), a.end());
      forn(i, N)
        ASSERT_TRUE(a[i] == b[i]); 
    }
  }
}
