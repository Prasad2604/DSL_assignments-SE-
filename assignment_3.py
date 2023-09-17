def in_mat():
    rows = int(input("Enter no. of rows :- "))
    col = int(input("Enter no. of columns :- "))
    print()
    l1 = []

    for i in range(rows):
        print(f"Enter elements of row {i+1} below ")
        l=[]
        for i in range(col):
            x = int(input())
            l.append(x)
        l1.append(l)
    return l1
def display_mat(l1):
    for i in l1:
        print(i)

print("Matrix 1")
l1 = in_mat()
print("matrix 1 is :-")
display_mat(l1)
print()
print("Matrix 2")
l2 = in_mat()

print("matrix 2 is :-")
display_mat(l2)

def add_mat(l1,l2):
    add = []
    if len(l1)==len(l2) and len(l1[0])==len(l2[0]):
        for i in range(len(l1)):
            l = []
            for j in range(len(l1[0])):
                k = l1[i][j]+l2[i][j]
                l.append(k)
            add.append(l)
        return add
    else:
        return "Addition of matrix is not possible"
def sub_mat(l1,l2):
    sub = []
    if len(l1)==len(l2) and len(l1[0])==len(l2[0]):
        for i in range(len(l1)):
            l = []
            for j in range(len(l1[0])):
                k = l1[i][j]-l2[i][j]
                l.append(k)
            sub.append(l)
        return sub
    else:
        return "Subtraction of matrix is not possible"
def trans_mat(l1):
    trans = []
    for i in range(len(l1[0])):
            l = []
            for j in range(len(l1)):
                k = l1[j][i]
                l.append(k)
            trans.append(l)
    return trans

def multiplication(l1,l2):
    y= []
    if(len(l1)==len(l2[0])):
        for i in range(len(l1)):
            x=[]
            for j in range(len(l2[0])):
                k1=0
                for k in range(len(l1[0])):
                    k1 += l1[i][k]*l2[k][j]
                x.append(k1)
            y.append(x)
        return y
    else:
        return "Multiplication of matrix is not possible"


print()
print("""Choices :-
      1.Addition of matrix
      2.Subtraction of matrix
      3.Transpose of matrix
      4.Multiplication of matrix""")
print()


ans = 'y'
while(ans=='y'):
    ch = int(input("Enter your choice :- "))
    if ch==1:
        p = (add_mat(l1,l2))
        print("Addition is :- ")
        display_mat(p)
    elif ch==2:    
        q = (sub_mat(l1,l2))
        print("Subtraction is :- ")
        display_mat(q)
    elif ch==3:
        print("matrix 1 is :-")
        display_mat(l1)
        print()
        print("matrix 2 is :-")
        display_mat(l2)
        print()
        x = int(input("Which matrix you wanna find transpose for(1/2)?? :- "))
        if x==1:
            r = (trans_mat(l1))
            print("transpose is :- ")
            display_mat(r)
        else:
            r = (trans_mat(l2))
            print("transpose is :- ")
            display_mat(r)
            
    elif ch==4:
        s = (multiplication(l1,l2))
        print("Multiplication is :- ")
        display_mat(s)
    else:
        print("Invalid choice")
    print()
    ans = input("Do you want to continue(y/n)?? :- ")
    print()
