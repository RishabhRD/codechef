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
    auto a = read<std::string>();
    auto b = read<std::string>();
    std::array<int, 26> freq_a = {0};
    std::array<int, 26> freq_b = {0};
    for (auto c : a)
      ++freq_a[c - 'a'];
    for (auto c : b)
      ++freq_b[c - 'a'];
    int max = 0;
    for (int i = 0; i < 26; ++i) {
      max = std::max(max, std::min(freq_a[i], freq_b[i]));
    }
    std::cout << max << std::endl;
  }
}
