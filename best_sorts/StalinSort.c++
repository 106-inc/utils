#include <iostream>
#include <vector>

void StalinSort( std::vector<int> &arr  )
{
  std::vector<int> new_arr = {arr[0]};
  for (size_t i = 1; i < arr.size(); ++i)
  {
    if (arr[i] >= arr[i - 1])
      new_arr.push_back(arr[i]);
  }
  arr = std::move(new_arr);  
} 

int main( void )
{
  std::vector<int> arr; 
  size_t size = 0;  

  std::cout << "Input size of array: ";
  std::cin >> size;
  
  for (size_t i = 0; i < size; ++i)
  {
    int new_elem = 0;
    std::cin >> new_elem;
    arr.push_back(new_elem); 
  }

  StalinSort(arr);
  std::cout << "Sorted array:\n";
  for (size_t i = 0; i < arr.size(); ++i)
    std::cout << arr[i] << ((i == arr.size() - 1) ? "" : " ");
  std::cout << "\nIt's a communism, bitch\n";

  return 0;
}
