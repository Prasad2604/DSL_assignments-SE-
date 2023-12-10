class SE:

    # def __inti__(self,roll_no):
    #     self.roll_no = roll_no
    def __init__(self,roll_no):
        self.roll_no = roll_no
    def in_lst(self,s):
        n = int(input(f"Enter number of students who like to play {s} :- "))
        while(n>0):
            i=1
            x = int(input(f"Enter roll number of student {i} :- "))
            self.roll_no.append(x)
            n-=1
            i+=1
    def Union(self,l1,l2):
        union=[]
        for i in l1:
            union.append(i)
        for i in l2:
            if i not in union:
                union.append(i)
        return union
    def intersection(self,l1,l2):
        inter = []
        for i in l1:
            if i in l2:
                inter.append(i)
        return inter
    def display(self,s):
        print(f"Student who like {s} :- ",self.roll_no)

# s = SE()
l1=[]
l2=[]
l3=[]

n = int(input("Enter the total number of students :- "))
c = SE(l1)
b = SE(l2)
f = SE(l3)

c.in_lst("cricket")
c.display("cricket")
b.in_lst("badminton")
b.display("badminton")
f.in_lst("football")
f.display("football")
print("Union :- ",c.Union(c.roll_no,b.roll_no))
print("Intersection :- ",c.intersection(c.roll_no,b.roll_no))

# c.display("cricket")
# b.display("badminton")
# f.display("football")

