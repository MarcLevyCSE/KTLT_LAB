#include <iostream>
#include <string>

using namespace std;
bool nonRepeat(string s, char c)
{
    int len = s.length();
    for(int i = 0; i < len -1; i++)
    {
        for (int j = len -1; j > i; j--)
        {
            if (s[i] == s[j])
                return false;
        }
    }
    return true;
}
void process(string s)
{
    string result;
    string temp = s;
    int len = s.length();
    unsigned int maxLength = 0;
    for (int i = 0; i < len; i++)
    {
        len = temp.length();
        for (int j = len - 1; j >= i; j--)
        {
            if (nonRepeat(temp, temp[j]))
            {
                if (maxLength < temp.length())
                {
                    result = temp;
                    maxLength = temp.length();
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
    cout << maxLength;
}
int main()  {
    string s;
    getline(cin, s);
    process(s);
}