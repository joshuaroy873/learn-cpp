#include<iostream>
#include<string>
#include<set>

int main()
{
  std::string input;
  std::set<char> input_dist;
  std::cin >> input;
  for (char c:input)
  {
    input_dist.insert(c);
  }
  if (input_dist.size()%2==1) std::cout<<"IGNORE HIM!";
  else std::cout<<"CHAT WITH HER!";
  return 0;
}
