#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of operations : ";
    cin >> n;

    vector<string> ques;

    for (int i = 0; i < n; i++)
    {
        string res;
        cin >> res;
        ques.push_back(res);
    }

    set<string> registersUsed;

    for (int i = 0; i < n; i++)
    {
        cout << "MOV" << " " << ques[i][2] << " " << "R0" << endl;
        registersUsed.insert("R0");
        if (ques[i][3] == '+')
        {
            cout << "ADD" << " " << ques[i][4] << " " << "R0" << endl;
        }
        else if (ques[i][3] == '*')
        {
            cout << "MUL" << " " << ques[i][4] << " " << "R0" << endl;
        }
        else if (ques[i][3] == '-')
        {
            cout << "SUB" << " " << ques[i][4] << " " << "R0" << endl;
        }
        cout << "MOV" << " " << "R0" << " " << ques[i][0] << endl;
    }
}