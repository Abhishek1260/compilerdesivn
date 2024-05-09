keywords = set()
operators = set()

def prepare():
    keywords.add("if");
    keywords.add("else");
    keywords.add("while");
    keywords.add("for");
    keywords.add("do");
    keywords.add("char");
    keywords.add("bool");
    keywords.add("string");
    keywords.add("int");

    operators.add("+");
    operators.add("-");
    operators.add("/");
    operators.add("*");
    operators.add("{");
    operators.add("}");
    operators.add(";");
    operators.add("=");
    operators.add("==");
    operators.add("!=");
    operators.add("<");
    operators.add(">");
    operators.add("<=");
    operators.add(">=");
    operators.add("&&");
    operators.add("||");
    operators.add("!");

prepare()

def isConstant(str):
    for i in range(len(str)):
        if not (str[i] >= '0' and str[i] <= '9'):
            return False;
    return True

ques = input("Enter the string to check : ")
start = 0
for i in range(len(ques)):
    if (ques[i] == ' '):
        if ques[start : i] in keywords:
            print("Keyword" , ques[start : i])
        elif ques[start : i] in operators:
            print("Operator" , ques[start : i])
        else:
            if isConstant(ques[start : i]):
                print("Constant" , ques[start : i])
            else:
                print("Identifier" , ques[start : i])
        start = i + 1


