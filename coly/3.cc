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
    auto n = read<int>();
    auto nums = read_vec<ll>(n);
    ll v = 0;
    ll p = 0;
    {
      auto const begin = std::begin(nums);
      auto const end = std::prev(std::end(nums));
      auto max_itr = std::max_element(begin, end);
      if (max_itr != end) {
        v += *max_itr;
        nums.erase(max_itr);
      }
    }
    n = std::size(nums);
    for (int i = n - 1; i >= 0; i -= 2) {
      p += nums[i];
    }
    for (int i = n - 2; i >= 0; i -= 2) {
      v += nums[i];
    }
    if (p > v) {
      std::cout << "Poonguzhali" << v << ' ' << p << std::endl;
    } else if (p < v) {
      std::cout << "Vanthiyathevan" << v << ' ' << p << std::endl;
    } else {
      std::cout << "Tie" << v << ' ' << p << std::endl;
    }
  }
}
