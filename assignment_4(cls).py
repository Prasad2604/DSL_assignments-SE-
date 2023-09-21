import math
class Search:

    def __init__(self,n):
        self.n = n
    
    def sort(self,arr):
        for i in range(1,self.n):
            key = arr[i]
            j=i-1
            while j>=0 and key<arr[j]:
                arr[j+1]=arr[j]
                j-=1
            arr[j+1]=key
    
    def get_list(self):
        l=[]
        for i in range(self.n):
            x = int(input(f"Enter element {i+1} :- "))
            l.append(x)
        s.sort(l)
        return l
    
    def linerSearch(self,l,key):
        found =0
        for i in range(len(l)):
            if(l[i]==key):
                return i
        return -1
    
    def SentinalSearch(self,l,key):
        temp = l[-1]
        l[-1]= key
        i=0
        while(l[i]!=key):
            i+=1
        l[-1]=temp
        if(i<len(l)-1 or key==l[-1]):
            return i
        return -1
    

    def BinarySearch(self,l,key):
        l.sort()
        s = 0
        e = len(l)-1
        mid = math.floor(s+(e-s)/2)
        while(s<=e):
            if(l[mid]==key):
                return mid
            elif(l[mid]>key):
                e = mid-1
            else:
                s = mid+1
            mid = math.floor(s+(e-s)/2)
        return -1
    
    
s = Search(int(input("Enter number of elements of list :- ")))

l1 = s.get_list()
print("Sorted List is :- ",l1)

ans = 'y'
while(ans.lower()=='y'):
    print()
    key = int(input("Enter element which you need to search :- "))
    print()
    print("""Choices :-
      1.Linear Search
      2.Sentinal Search
      3.Binary Search""")
    print()
    ch = int(input("Enter Choice :- "))

    if ch==1:
        print("-----------Liner serach result--------")
        print(f"{key} is present at index :- ",s.linerSearch(l1,key))
        print("--------------------------------------")
    elif ch==2:
        
        print("---------Sentinal Search Result-------")
        print(f"{key} is present at index :- ",s.SentinalSearch(l1,key))
        print("--------------------------------------")
    elif ch==3:

        print("-----------Binary Search Result-------")
        print(f"{key} is present at index :- ",s.BinarySearch(l1,key))
        print("--------------------------------------")

    else:
        print("Invalid choice!!")
    
    ans = input("Do you want to continue(y/n)?? :-")