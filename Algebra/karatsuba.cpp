#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdint>
#define forn(i, n) for(int i = 0; i < n; ++i)

using ll = int64_t;

const int maxMem = (int)1e6;

ll mem[maxMem];
ll mpos = 0;

inline ll *my_alloc( int n )
{
  ll *res = mem + mpos;
  mpos += n;
  assert(mpos <= maxMem);
  return res;
}

void Karatsuba(int n, ll *a, ll *b, ll *c) {
  if (n <= 16) {
    memset(c, 0, sizeof(ll) * 2*n);
    forn(i, n)
       forn(j, n)
        c[i + j] += a[i] * b[j];
    return;
  }
  // a*b = (a1 + a2*BASE^k) * (b1 + b2*BASE^k) = a1b1 + (a1b2 + a2b1)*BASE^k + a2b2*BASE^{n} = 
  // a1b1 + BASE^k ((a1 + a2)(b1 + b2) - a1b1 - a2b2) + BASE^{n} a2b2
  int old_pos = mpos;

  int k = n / 2;
  ll * as = my_alloc(k);
  ll * bs = my_alloc(k);
  ll * d = my_alloc(n);
  forn(i, k) {
    as[i] = a[i] + a[i + k];
    bs[i] = b[i] + b[i + k];
  }
  Karatsuba(k, a, b, c);
  Karatsuba(k, a + k, b + k, c + n);
  Karatsuba(k, as, bs, d);
  forn(i, n)
    d[i] -= c[i] + c[i + n];
  forn(i, n)
    c[i + k] += d[i];
  
  mpos = old_pos;
}

const int N = 262144;
const int BASE_LEN = 6;
const int BASE = (int) 1e6;
ll a[N], b[N], c[2 * N];
int len = 1;


void read(int n, ll * a) {
  char s[N + 1];
  gets(s);
  int k = 0, x = 1;
  memset(a, 0, sizeof(ll) * n);
  for(int i = strlen(s) - 1; i >= 0; --i) {
    a[k] += x * (s[i] - '0'), x *= 10;
    if(x == BASE)
      k++, x = 1;
  }
  k++;
  while(len < k)
    len <<= 1; 
}

void write(int n, ll * a) {
  int k = n - 1;
  while(k && !a[k]) k--;
  printf("%lld", a[k--]);
  while(k >= 0)
    printf("%0*lld", BASE_LEN, a[k--]);
  puts("");
}

void carry(int n, ll * c) {
  forn(i, n - 1)
    c[i + 1] += c[i] / BASE, c[i] %= BASE;
}

int main() {
  read(N, a);
  read(N, b);
  Karatsuba(len, a, b, c);
  carry(2*len, c);
  write(2*len, c);
}
