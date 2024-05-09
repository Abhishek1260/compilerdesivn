def prec(ch):
    if (ch == '^'):
        return 3
    elif (ch == '*' or ch == '/'):
        return 2
    elif (ch == '+' or ch == '-'):
        return 1
    return -1

def postfix(str):
    st = []
    res = ""
    for i in str:
        if (i >= 'a' and i <= 'z'):
            res += i
        else:
            while (len(st) != 0 and prec(st[len(st) - 1]) >= prec(i)):
                res += st.pop()
            st.append(i)
    while (len(st) != 0):
        res += st.pop()
    return res

def prefix(str):
    str = str[::-1]
    str = postfix(str)
    str = str[::-1]
    return str

print(postfix("a+b*c-d/e"))
print(prefix("a+b*c-d/e"))

print(postfix("a+b"))
print(prefix("a+b"))

