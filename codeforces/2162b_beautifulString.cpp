#include<iostream>
#include<string>
#include<vector>

bool isPalindrome(const std::string& s)
{
    int left=0, right=s.length()-1;
    while (left<right)
    {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> n(t);
    std::vector<std::string> str(t);
    for (int i=0; i<t; i++)
    {
        std::cin >> n[i];
        std::cin >> str[i];
    }
    for (int i=0; i<t; i++)
    {
        if (isPalindrome(str[i]))
        {
            std::cout << "0\n\n";
        }
        else
        {
            std::vector<int> indices;
            for (int j=0; j<n[i]; j++)
            {
                if (str[i][j]=='0')
                {
                    indices.push_back(j+1);
                }
            }
            std::cout << indices.size() << "\n";
            for (size_t k=0; k<indices.size(); k++)
            {
                std::cout << indices[k];
                if (k < indices.size()-1) std::cout << " ";
            }
            std::cout << "\n";

        }
    }

    return 0;
}