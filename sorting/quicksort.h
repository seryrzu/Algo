#pragma once

// it is better to use random_shuffle() before quicksort(). With very high probability after rs the qs will work O(nlogn)

int partition(int a[], int l, int r);
void quicksort(int a[], int l, int r);

