mp = {}
states = set()
transactions = set()

n = int(input("Enter the number of states : "))
for i in range(n):
    state = input("Enter the state : ")
    trans = input("Enter the transaction : ")
    final = input("Enter the final state : " )
    states.add(state)
    transactions.add(trans)
    states.add(final)
    mp[(state , trans)] = final

print("states" , end = "\t")

for i in transactions:
    print(i , end = "\t")

print()

for i in states:
    print(i , end = "\t")
    for j in transactions:
        print(mp[(i , j)] , end = "\t")
    print()
