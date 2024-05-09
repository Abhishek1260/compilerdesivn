class Parent:
    def __init__(self , name):
        self.name = name
        self.child = []

    def addProd(self , prod):
        child = Child(self , prod)
        self.child.append(child)
        return child

class Child:
    def __init__ (self , parent , prod):
        self.parent = parent 
        self.prod = prod
        if (prod[0] >= 'a' and prod[0] <= 'z'):
            self.lowercase = True
        else:
            self.lowercase = False

mp = {}
prodMp = {}
productions = set()
nonTerminals = set()
first = {}
follow = {}

def findFirst(s , mp , first):
    par = mp[s]
    if s not in first:
        first[s] = set()
    for prod in par.child:
        if prod.lowercase:
            first[s].add(prod.prod[0])
        else:
            if (s == prod.prod[0]):
                continue
            findFirst(prod.prod[0] , mp , first)
            firsts = first[prod.prod[0]]
            for f in firsts:
                first[s].add(f)

def findFollow(s , mp , first ,follow):
    if (s not in follow):
        follow[s] = set()
    prods = []
    for p in productions:
        if s in p:
            prods.append(p)
    for p in prods:
        if (p.find(s) != len(p) - 1):
            if (p[p.find(s) + 1] in nonTerminals):
                firsts = first[p[p.find(s) + 1]]
                for f in firsts:
                    follow[s].add(f)
            else:
                follow[s].add(p[p.find(s) + 1])
        else:
            childClass = prodMp[p]
            if childClass.parent.name != s:
                findFollow(childClass.parent.name , mp , first , follow)
                follows = follow[childClass.parent.name]
                for f in follows:
                    follow[s].add(f)

def solve():
    n = int(input("Enter the number of productions : "))
    for i in range(n):
        start = input("Enter the starting variable : ")
        prod = input("Enter the production : ")
        nonTerminals.add(start)
        productions.add(prod)
        if start in mp:
            prodMp[prod] = mp[start].addProd(prod)
        else:
            parent = Parent(start)
            mp[start] = parent
            prodMp[prod] = parent.addProd(prod)

    start = input("Enter the starting terminal : ")
    first[start] = set()
    follow[start] = set()
    follow[start].add('$')
    for t in nonTerminals:
        findFirst(t , mp , first)

    for t in nonTerminals:
        findFollow(t , mp , first , follow)

    for t in nonTerminals:
        firsts = first[t];
        for f in firsts:
            if f in nonTerminals:
                first[t].remove(f)
        follows = follow[t]
        for f in follows:
            if f in nonTerminals:
                follow[t].remove(f)

    print()
    print("FIRST")
    print()
    print("Non Terminal\tFirst")
    for t in nonTerminals:
        print(f"{t}\t\t{' '.join(first[t])}")

    print()
    print("FOLLOW")
    print()
    print("Non Terminal\tFirst")
    for t in nonTerminals:
        print(f"{t}\t\t{' '.join(follow[t])}")


if __name__ == "__main__":
    solve()
