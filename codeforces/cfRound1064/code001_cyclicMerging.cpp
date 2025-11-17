#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
  int t;
  std::vector<int> n;
  std::cin >> t;
  for (int i=0; i<t; i++)
  {
    std::cin >> n[i];
    std::vector<int> a;
    for (int j=0; j<n[i]; j++)
    {
      std::cin >> a[j];
    }
    int cost=0;
    while (a.size()>1)
    {
      std::vector<int> pairCost;
      for (int k=0; k<=a.size(); k++)
      {
        if (k!=a.size()) pairCost[k] = a[k]+a[k+1];
        else pairCost[k] = a[k]+a[0];
      }
      auto minElemIt = std::min_element(pairCost.begin(), pairCost.end());
      int minElemIdx = std::distance(pairCost.begin(), minElemIt);
      int minElemVal = *minElemIt;
      if (minElemIdx==
    }
