#include <iostream>
#include <map>
#include <set>
using namespace std;

map<pair<string, string>, string> mp;
set<string> state;
set<string> transaction;

int main()
{

    int n;
    cin >> n;

    string initState;
    string finalState;
    string trans;

    string init;
    string final;

    cout << "Enter the init State : ";
    cin >> init;

    cout << "Enter the final state : ";
    cin >> final;

    for (int i = 0; i < n; i++)
    {
        cin >> initState >> trans >> finalState;
        mp[make_pair(initState, trans)] = finalState;
        state.insert(initState);
        state.insert(finalState);
        transaction.insert(trans);
    }

    cout << "state" << "\t";
    for (set<string>::iterator i = transaction.begin(); i != transaction.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;

    for (set<string>::iterator i = state.begin(); i != state.end(); i++)
    {
        if (*i == final || *i == init)
        {
            if (*i == final)
            {
                cout << "-" << *i;
            }
            else
            {
                cout << "*" << *i;
            }
        }
        else
        {
            cout << *i;
        }
        cout << "\t";
        for (set<string>::iterator j = transaction.begin(); j != transaction.end(); j++)
        {
            cout << mp[make_pair(*i, *j)] << "\t";
        }
        cout << endl;
    }

    return 0;
}