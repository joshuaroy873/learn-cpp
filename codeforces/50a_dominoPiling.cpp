#include<iostream>

int main() {
  int M,N, area, ans=0;
  std::cin >> M >> N;
  area = M*N;
  if (M==1 && N==1)
    std::cout << ans;
  else {
    ans = area/2;
    std::cout << ans;
  }
  return 0;
}
