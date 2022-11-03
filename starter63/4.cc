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

auto right_shift(char a, char b) { return ((b - a) + 26) % 26; }

using ll = long long;

int dfs(std::string_view a, std::string_view b, int prev_score, int i,
        std::vector<std::vector<int>> &dp) {
  if (prev_score > 25 || prev_score < -25)
    return 26;
  if (i == std::size(a)) {
    return std::abs(prev_score);
  }
  if (dp[i][prev_score + 25] != -1)
    return dp[i][prev_score + 25];
  auto const a2b = right_shift(a[i], b[i]);
  auto const b2a = -right_shift(b[i], a[i]);
  return dp[i][prev_score + 25] =
             std::min(dfs(a, b, prev_score + a2b, i + 1, dp),
                      dfs(a, b, prev_score + b2a, i + 1, dp));
}

auto solve(std::string_view a, std::string_view b) {
  auto const n = std::size(a);
  std::vector visited(n, std::vector(51, -1));
  return dfs(a, b, 0, 0, visited);
}

int main() {
  auto t = read<int>();
  while (t--) {
    auto const n = read<int>();
    auto const a = read<std::string>();
    auto const b = read<std::string>();
    std::cout << solve(a, b) << std::endl;
  }
}
