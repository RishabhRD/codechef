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

// for any W < w, return max value possible
int knapsack(int w, int i, std::vector<int> const &weight,
             std::vector<int> const &value, std::vector<std::vector<int>> &dp) {
  if (i >= std::size(weight))
    return 0;
  if (dp[i][w] != -1)
    return dp[i][w];
  if (weight[i] > w) {
    return dp[i][w] = knapsack(w, i + 1, weight, value, dp);
  } else {
    return dp[i][w] = std::max(
               knapsack(w, i + 1, weight, value, dp),
               value[i] + knapsack(w - weight[i], i + 1, weight, value, dp));
  }
}

// can sum be a min(x, y)
// if sum is a candidate, then for any (x >= sum) => (max_y >= sum)
bool is_candidate(int sum, std::vector<int> const &red,
                  std::vector<int> const &blue) {
  auto const rsum = std::reduce(std::begin(red), std::end(red), 0);
  std::vector dp(std::size(red), std::vector(rsum + 1, -1));
  // if max_y is for a weight lesser value than rsum - sum
  // then it means, its for greater x
  return knapsack(rsum - sum, 0, red, blue, dp) >= sum;
}

using ll = long long;

template <typename Func> int binary_search(int low, int high, Func &&possible) {
  if (low >= high)
    return low;
  auto const mid = (low + high + 1) / 2;
  if (possible(mid)) {
    return binary_search(mid, high, possible);
  } else {
    return binary_search(low, mid - 1, possible);
  }
}

int main() {
  auto t = read<int>();
  while (t--) {
    auto const n = read<int>();
    auto const red = read_vec<int>(n);
    auto const blue = read_vec<int>(n);
    auto const red_sum = std::reduce(std::begin(red), std::end(red), 0);
    auto const blue_sum = std::reduce(std::begin(blue), std::end(blue), 0);
    auto const low = 0;
    auto const high = std::min(red_sum, blue_sum);
    auto is_i_candidate = [&red, &blue](int i) {
      return is_candidate(i, red, blue);
    };
    std::cout << binary_search(low, high, is_i_candidate) << std::endl;
  }
}
