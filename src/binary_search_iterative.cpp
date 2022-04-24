#include "assignment/binary_search_iterative.hpp"

namespace assignment {

  std::optional<int> BinarySearchIterative::Search(const std::vector<int>& arr, int search_elem) const {

    // Tips:
    // 1. Заведите две переменные: (а) индекс левой границы и (б) индекс правой границы.
    // 2. Поиск ведется пока индекс левой границы не превысил индекс правой.
    // 3. Каждую итерацию вычисляйте индекс середины внутри области, задаваемой индексами левой и правой границы.
    // 4. Рассмотрите 3 случая:
    //    1) Целевой элемент равен элементу посередине.
    //    2) Целевой элемент меньше элемента посередине (область поиска сокращается).
    //    3) Целевой элемент больше элемента посередине (область поиска сокращается).

    if (arr.size() == 0) return std::nullopt;

    int leftBorder = 0;
    int rightBorder = static_cast<int>(arr.size()) - 1;;
    int middle;

    while (leftBorder < rightBorder) {

      if (arr[leftBorder] == search_elem) return leftBorder;
      if (arr[rightBorder] == search_elem) return rightBorder;

      if ((rightBorder - leftBorder == 1) && arr[leftBorder] != search_elem && arr[rightBorder] != search_elem) return std::nullopt;

      middle = (rightBorder - leftBorder) / 2 + leftBorder;

      if (middle == leftBorder || middle == rightBorder) return std::nullopt;
      if (arr[middle] == search_elem) {
        return middle;
      } else if (arr[middle] >= search_elem) {
        rightBorder = middle;
      } else if (arr[middle] <= search_elem) {
        leftBorder = middle;
      }
    }

    if (leftBorder == rightBorder & arr[leftBorder] == search_elem) return leftBorder;

    return std::nullopt;
  }

}  // namespace assignment