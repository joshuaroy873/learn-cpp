#include<iostream>
#include<vector>
#include<cmath>

int main()
{
  std::vector<std::vector<int>> matrix(5, std::vector<int>(5));
  int pos_i, pos_j;
  for (int i=0; i<5; i++)
  {
    for (int j=0; j<5; j++)
    {
      std::cin >> matrix[i][j];
      if (matrix[i][j]==1) {pos_i=i; pos_j=j;}
    }
  }
  std::cout << std::abs(2-pos_i)+std::abs(2-pos_j); 
  return 0;
}
