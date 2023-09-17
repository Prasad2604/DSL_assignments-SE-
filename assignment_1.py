def union(l1,l2):
        union= []
        for i in l1:
            union.append(i)
        for j in l2:
            flag=0
            for k in union:
                if j==k:
                    flag=1
                    break
                else:
                    flag=0
            if flag==0:
                union.append(j)
        return union

def inter(l1,l2):
        inter=[]
        for i in l1:
            flag=0
            for j in l2:
                if i==j:
                    flag=1
                    break
                else:
                    flag=0
            if flag==1:
                inter.append(i)
        return inter

def input1(l1,str1):
     k = int(input(f"Enter no of sudent who like to play {str1} :-"))
     print(f"Enter roll no of sudent who like to play {str1} :-")
     
     for i in range(k):
          
          p  = int(input())
          l1.append(p)
     return l1
     
def display(l1,str1):
     print(f"{str1} :- ",l1)
     

c = []
b = []
f = []
total = int(input("Enter total number of students :- "))
cr = input1(c,"cricket")
bad = input1(b,"badminton")
foot = input1(f,"football")

display(cr,"cricket")
display(bad,"badminton")
display(foot,"football")



print()
print("""Choices :- 
      1.Student who play both cricket and badminton 
      2.Student who play either cricket or badminton
      3.No. of Student who neither play cricket nor badminton
      4.No. of Student who play cricket and football but not badminton
      5.No. of Student who don't play any sport.""")
print()

ans = 'y'

while(ans=='y'):

    ch = int(input("Enter the choice(1-5):-"))
    if ch==1:
        display(cr,"cricket")
        display(bad,"badminton")
        print("Student who play both cricket and badminton :- ",inter(cr,bad))
    elif ch==2:
        display(cr,"cricket")
        display(bad,"badminton")
        print("Student who play either cricket or badminton :- ",union(cr,bad))
    elif ch==3:
        display(cr,"cricket")
        display(bad,"badminton")
        
        print("No. of Student who neither play cricket nor badminton :- ",total-len(union(cr,bad)))
    elif ch==4:
        display(cr,"cricket")
        display(bad,"badminton")
        display(foot,"football")
        print("No. of Student who play cricket and football but not badminton :- ",len(inter(cr,foot))-len(inter(cr,inter(bad,foot))))
    elif ch==5:
        display(cr,"cricket")
        display(bad,"badminton")
        display(foot,"football")
        print("No. of Student who don't play any sport :- ",total-len(union(cr,union(bad,foot))))
    else:
         print("Please enter a valid choice!!")
    print()
    ans = input("Do you want to continue(y/n)?? :- ")




