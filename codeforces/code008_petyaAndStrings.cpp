#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

int main()
{
  std::string strA, strB;
  std::cin >> strA >> strB;
  std::transform(strA.begin(), strA.end(), strA.begin(), [](unsigned char c){ return std::tolower(c); });
  std::transform(strB.begin(), strB.end(), strB.begin(), [](unsigned char c){ return std::tolower(c); });
  int i, n = strA.length();
  for (i=0; i<n; i++)
  {
    if (strA[i]<strB[i])
    {
      std::cout << -1;
      break;
    }
    if (strA[i]>strB[i])
    {
      std::cout << 1;
      break;
    }
    if (i==n-1 && strA[i]==strB[i])
    {
    std::cout << 0;
    }
  }
  return 0;
}
