#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<pair<string, string>, string> mp;

set<string> s;
set<string> states;

int main()
{

    string init = "q0";
    string final = "q1";

    string question[4][3] = {
        {
            "q0",
            "a",
            "q1",
        },
        {
            "q0",
            "b",
            "q1",
        },
        {
            "q1",
            "a",
            "q0",
        },
        {
            "q1",
            "b",
            "q1",
        }};

    for (int i = 0; i < 4; i++)
    {
        mp[make_pair(question[i][0], question[i][1])] = question[i][2];
        s.insert(question[i][0]);
        states.insert(question[i][1]);
    }

    cout
        << "Initial"
        << "\t"
        << "a"
        << "\t"
        << "b" << endl;

    for (set<string>::iterator i = s.begin(); i != s.end(); i++)
    {
        string state = *i;
        if (state == init)
        {
            state = '*' + state;
        }
        if (state == final)
        {
            state = '-' + state;
        }
        cout << state << "\t" << mp[make_pair(*i, "a")] << "\t" << mp[make_pair(*i, "b")] << endl;
    }

    return 0;
}