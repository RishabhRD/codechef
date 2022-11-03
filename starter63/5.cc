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

auto f(ll i, ll n) { return (i + 1) * (n - i); }

auto initial_string_val(std::string_view nums) {
  auto const n = std::size(nums);
  ll init = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == '1')
      init += f(i, n);
  }
  return init;
}

auto solve(std::string_view nums) {
  auto const n = std::size(nums);
  auto const init = initial_string_val(nums);
  ll max_val = 0;
  ll cur_val = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == '0') {
      cur_val += f(i, n);
    } else {
      cur_val -= f(i, n);
    }
    cur_val = std::max<ll>(cur_val, 0);
    max_val = std::max<ll>(cur_val, max_val);
  }
  return init + max_val;
}

int main() {
  auto t = read<int>();
  while (t--) {
    auto const nums = read<std::string>();
    std::cout << solve(nums) << std::endl;
  }
}
