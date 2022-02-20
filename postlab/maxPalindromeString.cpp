#include <iostream>
#include <string>

using namespace std;


bool isPalindrome(string s, char c)
{
    int len = s.length();
    if (len == 0 || len == 1)
        return true;
    if (s[0] != c)
        return false;
    for (int i = 1; i < len / 2 + 1; i++)
    {
        if (s[i] != s[len - i - 1])
            return false;
    }
    return true;
}
void process(string s)
{
    string result;
    string temp = s;
    int len = s.length();
    unsigned int maxLength = 0;
    for (int i = 0; i < len - maxLength; i++)
    {
        len = temp.length();
        for (int j = len - 1; j >= i; j--)
        {
            if (isPalindrome(temp, temp[j]))
            {
                if (maxLength < temp.length())
                {
                    maxLength = temp.length();
                    result = temp;
                    break;
                }
            }
            else
            {
                temp.pop_back();
            }
        }
        temp = s;
        temp.erase(0, i+1);
    }
    cout << result;
}
int main()
{
    string s;
    getline(cin, s);
    process(s);
}
