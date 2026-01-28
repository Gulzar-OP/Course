#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s)
{
    // remove spaces and colons and comma
    // s.erase(
    //     remove_if(s.begin(), s.end(),
    //               [](char c)
    //               {
    //                   return c == ' ' || c == ':' || c==',';
    //               }),
    //     s.end());

    // remove non-alphanumeric characters
    s.erase(
        remove_if(s.begin(), s.end(),
                  [](char c)
                  {
                      return !isalnum(c);
                  }),
        s.end());
    cout<<s<<endl;
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }
        i++;
        j--;
    }

    return true; // ✅ correct
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    bool ans = isPalindrome(s);

    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}
