#include <iostream>

template<typename T, size_t N>
void selection_sort(T (&arr)[N]);

template<typename T, size_t N>
void bubble_sort(T (&arr)[N]);

int main()
{
  int select_array[] = { 64, 34, 25, 12, 22, 11, 90 };
  for (auto num : select_array) std::cout << num << " ";
  std::cout << std::endl;
  selection_sort<int, 7>(select_array);
  for (auto num : select_array) std::cout << num << " ";
  std::cout << std::endl;

  int bubble_array[] = { 64, 34, 25, 12, 22, 11, 90 };
  for (auto num : bubble_array) std::cout << num << " ";
  std::cout << std::endl;
  bubble_sort<int, 7>(bubble_array); 
  for (auto num : bubble_array) std::cout << num << " ";
  std::cout << std::endl;

  return 0;
}

template<typename T, size_t N>
void selection_sort(T (&arr)[N])
{
  //implement this
}

template<typename T, size_t N>
void bubble_sort(T (&arr)[N])
{
  //implement this
}
