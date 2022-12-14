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

bool is_neg(int ele) { return ele < 0; }

int main() {
  auto t = read<int>();
  while (t--) {
    auto const n = read<int>();
    auto const vec = read_vec<int>(n);
    auto const num_neg = std::count_if(std::begin(vec), std::end(vec), is_neg);
    if (num_neg == n) {
      std::cout << num_neg - 1 << std::endl;
    } else {
      std::cout << num_neg << std::endl;
    }
  }
}
