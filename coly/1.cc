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

auto get_odd(int n) {
  if (n % 2)
    return n;
  return n + 1;
}

int main() {
  auto const l = read<int>();
  auto const r = read<int>();
  auto const n = read<int>();
  if (n == 1)
    std::cout << l << ' ' << l << std::endl;
  else {
    auto first = get_odd(l);
    for (int i = 0; i < n; ++i) {
      std::cout << first << ' ' << l + i << std::endl;
    }
  }
}
