class SE:
    def __init__(self,roll_no):
        self.roll_no = roll_no

    def input1(self,roll_no,str1):
        k = int(input(f"Enter no of sudent who like to play {str1} :-"))
        print(f"Enter roll no of sudent who like to play {str1} :-")

     
        for i in range(k):
          
          p  = int(input())

          if p not in self.roll_no:
              
            self.roll_no.append(p)
        #return self.roll_no
    

    def display(self,roll_no,str1):
     print(f"{str1} :- ",self.roll_no)
   

    def union(self,l1,l2):
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
    
    def inter(self,l1,l2):
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
'''c = [1,4,7,10]
b = [1,5,8,9,10]
f = [1,2,3,4,5,6,7]'''
l1=[]
l2=[]
l3=[]



total  = int(input("Enter total number of students :- "))
c = SE(l1)
b = SE(l2)
f = SE(l3)

# cr = c.input1(c.roll_no,"cricket")
# bd = b.input1(b.roll_no,"badminton")
# fb = f.input1(f.roll_no,"football")

c.input1(c.roll_no,"cricket")
b.input1(b.roll_no,"badminton")
f.input1(f.roll_no,"football")



c.display(c.roll_no,"cricket")
b.display(b.roll_no,"badminton")
f.display(f.roll_no,"football")


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
        c.display(c.roll_no,"cricket")
        b.display(b.roll_no,"badminton")
        print("Student who play both cricket and badminton :- ",c.inter(c.roll_no,b.roll_no))
    elif ch==2:
        c.display(c.roll_no,"cricket")
        b.display(b.roll_no,"badminton")
        print("Student who play either cricket or badminton :- ",c.union(c.roll_no,b.roll_no))
    elif ch==3:
        c.display(c.roll_no,"cricket")
        b.display(b.roll_no,"badminton")
        
        print("No. of Student who neither play cricket nor badminton :- ",total-len(c.union(c.roll_no,b.roll_no)))
    elif ch==4:
        c.display(c.roll_no,"cricket")
        b.display(b.roll_no,"badminton")
        f.display(f.roll_no,"football")
        print("No. of Student who play cricket and football but not badminton :- ",len(c.inter(c.roll_no,f.roll_no))-len(c.inter(c.roll_no,b.inter(b.roll_no,f.roll_no))))
    elif ch==5:
        c.display(c.roll_no,"cricket")
        b.display(b.roll_no,"badminton")
        f.display(f.roll_no,"football")
        print("No. of Student who don't play any sport :- ",total-len(c.union(c.roll_no,b.union(b.roll_no,f.roll_no))))
    else:
         print("Please enter a valid choice!!")
    print()
    ans = input("Do you want to continue(y/n)?? :- ")




