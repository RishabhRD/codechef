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

int main() {
  auto t = read<int>();
  while (t--) {
    auto const n = read<int>();
    auto const nums = read_vec<ll>(n);
    ll dec_point = 0;
    ll ans = 1;
    for (ll i = 1; i < n; ++i) {
      auto const len = i - dec_point + 1;
      ans += len;
      if (i != n - 1 and nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) {
        dec_point = i;
      }
    }
    std::cout << ans << std::endl;
  }
}
