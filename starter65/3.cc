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

auto solve() {}

int main() {
  auto t = read<int>();
  while (t--) {
    auto const n = read<int>();
    auto const q = read<int>();
    auto const nums = read_vec<ll>(n);
    std::vector num_set(n, std::vector<ll>(61));
    for (int i = 0; i < n; ++i) {
      std::bitset<61> bs(nums[i]);
      for (int j = 0; j <= 60; ++j) {
        num_set[i][j] = bs[j];
        if (i != 0)
          num_set[i][j] += num_set[i - 1][j];
      }
    }
    for (auto _ = 0; _ < q; ++_) {
      auto const k = read<int>();
      auto const get = [&](auto i, auto j) {
        --i;
        --j;
        if (i == 0)
          return num_set[j][k];
        return num_set[j][k] - num_set[i - 1][k];
      };
      auto const l1 = read<int>();
      auto const r1 = read<int>();
      auto const l2 = read<int>();
      auto const r2 = read<int>();
      auto const n1 = get(l1, r1);
      auto const n2 = get(l2, r2);
      auto const n1_prime = (r1 - l1 + 1) - n1;
      auto const n2_prime = (r2 - l2 + 1) - n2;
      std::cout << n1 * n2_prime + n2 * n1_prime << std::endl;
    }
  }
}
