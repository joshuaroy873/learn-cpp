#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main()
{
  std::string input;
  std::cin >> input;
  std::vector<int> numList;
  for (int i=0; i < static_cast<int>(input.size()); i+=2)
  {
    numList.push_back(input[i]);
  }
  std::sort(numList.begin(), numList.end());
  for (int i=0; i < static_cast<int>(numList.size()); i++)
  {
    input[2*i] = static_cast<char>(numList[i]);
  }
  std::cout << input;
  return 0;
}
