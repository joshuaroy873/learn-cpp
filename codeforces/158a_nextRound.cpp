#include<iostream>
#include<vector>

int main() {
	int n,k, count=0; 
	std::cin >> n >> k;
  std::vector<int> scores(n);

	for (int i=0; i<n; i++) std::cin >> scores[i];
	
  int kth_score = scores[k-1];
  
  for (int i=0; i<n; i++)
  {
    if (scores[i]>0)
    {
      if (scores[i]>=kth_score) count++;
       else break;
    }
    else break;
  }

	std::cout << count;
	return 0;
}
