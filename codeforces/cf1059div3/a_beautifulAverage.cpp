#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
  int t;
  std::cin >> t;
  std::vector<int> max(t);
  for (int i=0; i<t; i++)
  {
    int size;
    std::cin >> size;
    std::vector<int> array(size);
    for (int j=0; j<size; j++)
    {
      std::cin >> array[j];
    }
    max[i] = *std::max_element(array.begin(), array.end());
  }
  for (int i=0; i<t; i++)
  {
    std::cout << max[i] << "\n";
  }
  return 0;
}
