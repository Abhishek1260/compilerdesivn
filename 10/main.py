n = int(input("Enter the number of operations : "))

operations = []
for i in range(n):
    str = input("Enter the operation : ")
    operations.append(str)

for i in operations:
    print("MOV" , i[2] , "R0")
    if (i[3] == '+'):
        print("ADD" , i[4] , "R0")
    elif (i[3] == '-'):
        print("SUB" , i[4] , "R0")
    elif (i[3] == '*'):
        print("MUL" , i[4] , "R0")
    print("MOV" , "R0" , i[0])

