#include <iostream>
#include <set>
using namespace std;

set<string> keywords;
set<string> oper;

void prepare()
{
    keywords.insert("if");
    keywords.insert("else");
    keywords.insert("while");
    keywords.insert("for");
    keywords.insert("do");
    keywords.insert("char");
    keywords.insert("bool");
    keywords.insert("string");
    keywords.insert("int");

    oper.insert("+");
    oper.insert("-");
    oper.insert("/");
    oper.insert("*");
    oper.insert("{");
    oper.insert("}");
    oper.insert(";");
    oper.insert("=");
    oper.insert("==");
    oper.insert("!=");
    oper.insert("<");
    oper.insert(">");
    oper.insert("<=");
    oper.insert(">=");
    oper.insert("&&");
    oper.insert("||");
    oper.insert("!");
}

bool isConstant(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= '0' && s[i] < '9'))
        {
            return false;
        }
    }
    return true;
}

int main()
{

    prepare();

    string checker;
    getline(cin, checker);
    cin.clear();

    int start = 0;

    for (int i = 0; i < checker.length(); i++)
    {
        if (checker[i] == ' ')
        {
            string check = checker.substr(start, i - start);
            if (keywords.find(check) != keywords.end())
            {
                cout << "Keyword " << check << endl;
            }
            else if (oper.find(check) != oper.end())
            {
                cout << "Operator " << check << endl;
            }
            else
            {
                if (isConstant(check))
                {
                    cout << "Constant " << check << endl;
                }
                else
                {
                    cout << "Identifier " << check << endl;
                }
            }
            start = i + 1;
        }
    }

    if (start != checker.length())
    {
        string check = checker.substr(start, checker.length() - start);
        if (keywords.find(check) != keywords.end())
        {
            cout << "Keyword " << check << endl;
        }
        else if (oper.find(check) != oper.end())
        {
            cout << "Operator " << check << endl;
        }
        else
        {
            if (isConstant(check))
            {
                cout << "Constant " << check << endl;
            }
            else
            {
                cout << "Identifier " << check << endl;
            }
        }
    }
}