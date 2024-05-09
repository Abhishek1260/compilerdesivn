#include <iostream>
#include <map>
#include <set>
using namespace std;

map<pair<string, string>, string> mp;

set<string> s;
set<string> states;

int main()
{

    int n;
    cin >> n;

    string initState;
    string endState;
    string trans;

    string init;
    string final;

    cout << "enter init state : ";
    cin >> init;
    cout << "enter final state : ";
    cin >> final;

    cout << "Enter all States : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> initState >> trans >> endState;
        mp[make_pair(initState, trans)] = endState;
        s.insert(initState);
        states.insert(trans);
    }

    cout << "Initial"
         << "\t";
    for (set<string>::iterator i = states.begin(); i != states.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;

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
        cout << state << "\t";
        for (set<string>::iterator j = states.begin(); j != states.end(); j++)
        {
            cout << mp[make_pair(*i, *j)] << "\t";
        }
        cout << endl;
    }

    return 0;
}