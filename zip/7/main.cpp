#include <iostream>
#include <stack>
using namespace std;

int prec(char s)
{
    if (s == '^')
    {
        return 3;
    }
    else if (s == '*' || s == '/')
    {
        return 2;
    }
    else if (s == '+' || s == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string postfix(string s)
{
    string res = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            res += s[i];
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

string reverseString(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        res += s[s.size() - i - 1];
    }
    return res;
}

string prefix(string s)
{
    string reversedString = reverseString(s);
    string ans = postfix(reversedString);
    ans = reverseString(ans);
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << postfix(s) << endl;

    cout << prefix(s) << endl;

    return 0;
}