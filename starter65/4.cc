#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T> T read() {
  T t;
  std::cin >> t;
  return t;
}

template <typename T> std::vector<T> read_vec(int n) {
  std::vector<T> vec(n);
  for (auto &ele : vec)
    std::cin >> ele;
  return vec;
}

template <typename T> std::vector<T> read_matrix(int m, int n) {
  std::vector<std::vector<T>> vec(m, std::vector<T>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> vec[i][j];
    }
  }
  return vec;
}

using ll = long long;

constexpr ll mod = 1e9 + 7;

ll pow2(ll n) {
  if (n == 0)
    return 1;
  auto const partial = pow2(n / 2);
  auto const sqr = (partial * partial) % mod;
  if (n % 2 == 1) {
    return (2 * sqr) % mod;
  } else {
    return sqr;
  }
}

auto solve() {}

int main() {
  auto t = read<int>();
  while (t--) {
    auto const n = read<int>();
    auto const k = read<int>();
    auto const nums = read_vec<ll>(n);
    std::vector num_mod(k + 1, 0);
    for (auto const ele : nums)
      ++num_mod[ele % k];
    ll ans = 1;
    for (ll i = 0; i < k; ++i) {
      auto const j = (k - i) % k;
      if (i > j)
        break;
      if (i == j) {
        ans = (ans * (num_mod[i] + 1)) % mod;
      } else {
        ans = (ans * (pow2(num_mod[i]) + pow2(num_mod[j]) - 1)) % mod;
      }
    }
    std::cout << ans << std::endl;
  }
}
