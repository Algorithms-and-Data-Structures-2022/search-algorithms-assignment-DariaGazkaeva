#include "assignment/two_sum.hpp"  // find_elements

namespace assignment {

  std::optional<std::pair<int, int>> two_sum(const std::vector<int>& arr, int sum) {

    // Tips: для создания пары (pair) используйте функцию std::make_pair

    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    while (left < right) {
      int summa = arr[left] + arr[right];
      if (summa == sum) return std::make_pair(left, right);
      if (summa < sum) left++;
      else right--;
    }
    return std::nullopt;
  }

}  // namespace assignment