class Sort:

    def __init__(self,n):
        self.n = n
    
    def in_list(self):
        l = []
        for i in range(self.n):
            x = int(input(f"Element {i+1} :- "))
            l.append(x)
        return l
    
    def SelectionSort(self,l):
        for i in range(self.n-1):
            minindex = i
            for j in range(i+1,self.n):
                if l[j]<l[minindex]:
                    minindex = j
            l[i],l[minindex] = l[minindex],l[i]
            print(f"{i+1} pass :- ",l)
        return l
    
    def BubbleSort(self,l):
        for i in range(self.n-1):
            swaped = 0
            for j in range(0,self.n-i-1):
                if l[j+1]<l[j]:
                    swaped = 1
                    l[j+1],l[j] = l[j],l[j+1]
                
            print(f"{i+1} pass :- ",l)
            if swaped==0:
                return l
        return l
    
    def InsertionSort(self,l):
        for i in range(1,self.n):
            key = l[i]
            j = i-1
            while j>=0 and key<l[j]:
                l[j+1] = l[j]
                j-=1
            l[j+1] = key
            print(f"{i} pass :- ",l)
        return l
    
    def ShellSort(self,l):
        gap = self.n//2
        while gap>=1:
            for j in range(gap,self.n):
                i = j-gap
                while i>=0:
                    if l[i]>l[i+gap]:
                        l[i],l[i+gap] = l[i+gap],l[i]
                        i = i-gap
                    else:
                        break
            gap //=2
        return l

s = Sort(int(input("Enter number of elements of the list :- ")))

l = s.in_list()
print()
print("List is :- ",l)

ans = 'y'
while(ans.lower()=='y'):
    print()
    print("""Choices :- 
          1.Sort list using Selection Sort.
          2.Sort list using Bubble Sort.
          3.Sort list using Insertion Sort.
          4.Sort list using Shell Sort.""")
    print()
    ch = int(input("Enter your choice :- "))

    if ch==1:
        print("---------Selection Sort Result-----------")
        print("Sorted List :- ",s.SelectionSort(l))
        print("-----------------------------------------")
    elif ch==2:
        print("---------Bubble Sort Result-----------")
        print("Sorted List :- ",s.BubbleSort(l))
        print("-----------------------------------------")
    elif ch==3:
        print("---------Insertion Sort Result-----------")
        print("Sorted List :- ",s.InsertionSort(l))
        print("-----------------------------------------")
    elif ch==4:
        print("---------Shell Sort Result-----------")
        print("Sorted List :- ",s.ShellSort(l))
        print("-----------------------------------------")
    else:
        print("Invalid Choice!!")
    ans = input("Do you want to continue(y/n)?? :- ")

    