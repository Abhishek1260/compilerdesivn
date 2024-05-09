#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

class Prods
{
public:
    string prod;
    bool startingLower;

    Prods(string prod)
    {
        this->prod = prod;
        if (prod[0] >= 'a' && prod[0] < 'z')
        {
            this->startingLower = true;
        }
        else
        {
            this->startingLower = false;
        }
    }
};

class Parent
{
public:
    char s;
    vector<Prods *> prods;

    Parent(char prod_parent)
    {
        s = prod_parent;
    }

    void add_prod(string production)
    {
        Prods *prod = new Prods(production);
        prods.push_back(prod);
    }
};

map<char, Parent *> mp;

map<char, set<char> > first;

void findFirst(char s)
{
    Parent *par = mp[s];
    for (int i = 0; i < par->prods.size(); i++)
    {
        Prods *prod = par->prods[i];
        if (prod->startingLower == true)
        {
            first[s].insert(prod->prod[0]);
        }
        else
        {
            findFirst(prod->prod[0]);
            set<char> firsts = first[prod->prod[0]];
            for (set<char>::iterator j = firsts.begin(); j != firsts.end(); j++)
            {
                first[s].insert(*j);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    char parent;
    string prod;

    for (int i = 0; i < n; i++)
    {
        cin >> parent >> prod;
        if (mp[parent])
        {
            mp[parent]->add_prod(prod);
        }
        else
        {
            Parent *par = new Parent(parent);
            mp[parent] = par;
            par->add_prod(prod);
        }
    }

    char start = 'B';

    findFirst(start);

    for (set<char>::iterator i = first[start].begin(); i != first[start].end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
}