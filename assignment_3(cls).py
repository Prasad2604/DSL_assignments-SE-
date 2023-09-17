class Matrix:
    
    def __init__(self,rows,col,l1):
        self.rows = rows
        self.col = col
        self.l1 = l1
    def in_mat(self):
        # rows = int(input("Enter no. of rows :- "))
        # col = int(input("Enter no. of columns :- "))
        self.l1 = []

        for i in range(self.rows):
            l=[]
            for i in range(self.col):
                x = int(input())
                l.append(x)
            self.l1.append(l)
        # return l1
    
    def display_mat(self,l):
        for i in l:
            print(i)
    def add_mat(self,l1,l2):
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
    def sub_mat(self,l1,l2):
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
    def trans_mat(self,l1):
        trans = []
        for i in range(len(l1[0])):
                l = []
                for j in range(len(l1)):
                    k = l1[j][i]
                    l.append(k)
                trans.append(l)
        return trans

    def multiplication(self,l1,l2):
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
l1=[]
l2=[]
a = Matrix(int(input("Enter no of rows :- ")),int(input("Enter no of columns :- ")),l1)
l1 = a.in_mat()
b = Matrix(int(input("Enter no of rows :- ")),int(input("Enter no of columns :- ")),l2)
l2 = b.in_mat()
c = Matrix
print("matrix 1 is :-")
a.display_mat(a.l1)
print("matrix 2 is :-")
b.display_mat(b.l1)

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
        p = (a.add_mat(a.l1,b.l1))
        print("Addition is :- ")
        a.display_mat(p)
    elif ch==2:    
        q = (a.sub_mat(a.l1,b.l1))
        print("Subtraction is :- ")
        a.display_mat(q)
    elif ch==3:
        print("matrix 1 is :-")
        a.display_mat(a.l1)
        print()
        print("matrix 2 is :-")
        b.display_mat(b.l1)
        print()
        x = int(input("Which matrix you wanna find transpose for(1/2)?? :- "))
        if x==1:
            r = (a.trans_mat(a.l1))
            print("transpose is :- ")
            a.display_mat(r)
        else:
            r = (b.trans_mat(b.l1))
            print("transpose is :- ")
            b.display_mat(r)
            
    elif ch==4:
        s = (a.multiplication(a.l1,b.l1))
        print("Multiplication is :- ")
        a.display_mat(s)
    else:
        print("Invalid choice")
    print()
    ans = input("Do you want to continue(y/n)?? :- ")
    print()


    
        