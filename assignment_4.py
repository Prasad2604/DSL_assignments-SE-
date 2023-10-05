import math
def linerSearch(l,key):
    found =0
    for i in range(len(l)):
        if(l[i]==key):
            return i
    return -1

def BinarySearch(l,key):
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

def SentinalSearch(l,key):
    temp = l[-1]
    l[-1]= key
    i=0
    while(l[i]!=key):
        i+=1
    l[-1]=temp
    if(i<len(l)-1 or key==l[-1]):
        return i
    return -1

def sort(arr):
    N = len(arr)
    for i in range(1,N):
        key = arr[i]
        j = i-1
        while j>=0 and key<arr[j]:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key

def get_list():
    l=[]
    n = int(input("Enter number of elements of list :- "))
    for i in range(n):
        x = int(input(f"Enter element {i+1} :- "))
        l.append(x)
    sort(l)
    return l

def Fib(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        a = 0
        b = 1
        i = 1
        c=0
        while(i<n):
            c=a+b
            a=b
            b=c
            i+=1
        return c

def FibonacciSearch(arr,key):
    m=0
    N = len(arr)
    while(Fib(m)<N):
        m+=1
    offset = -1
    while(Fib(m)>1):
        mid = min(offset+Fib(m-2),N)
        if(key>arr[mid]):
            m-=1
            offset = mid
        elif(key<arr[mid]):
            m-=2
        else:
            return mid
    if(not Fib(m-1) and arr[offset-1]==key):
        return offset-1
    
    return -1
  

l1 = get_list()
print()
print("Sorted List is :- ",l1)

ans = 'y'
while(ans.lower()=='y'):
    print()
    key = int(input("Enter element which you need to search :- "))
    print()
    print("""Choices :-
      1.Linear Search
      2.Sentinal Search
      3.Binary Search
      4.Fibonacci Search""")
    print()
    ch = int(input("Enter Choice :- "))

    if ch==1:
        print("-----------Liner serach result--------")
        print(f"{key} is present at index :- ",linerSearch(l1,key))
        print("--------------------------------------")
    elif ch==2:
        
        print("---------Sentinal Search Result-------")
        print(f"{key} is present at index :- ",SentinalSearch(l1,key))
        print("--------------------------------------")
    elif ch==3:

        print("-----------Binary Search Result-------")
        print(f"{key} is present at index :- ",BinarySearch(l1,key))
        print("--------------------------------------")

    elif ch==4:
        
        print("---------Fibonacci Search Result-------")
        print(f"{key} is present at index :- ",FibonacciSearch(l1,key))
        print("--------------------------------------")

    else:
        print("Invalid choice!!")
    
    ans = input("Do you want to continue(y/n)?? :- ")


