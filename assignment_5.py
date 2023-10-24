def in_list():
    l = []
    n = int(input("Enter number of elements of the list :- "))
    for i in range(n):
        x = int(input(f"Element {i+1} :- "))
        l.append(x)
    return l

def SelectionSort(l):
    n = len(l)
    for i in range(n-1):
        minindex = i
        for j in range(i+1,n):
            if l[j]<l[minindex]:
                minindex = j
        l[i],l[minindex] = l[minindex],l[i]
        print(f"{i+1} pass :- ",l)
    return l

def BubbleSort(l):
    n = len(l)
    for i in range(n-1):
        swaped = 0
        for j in range(0,n-i-1):
            if l[j+1]<l[j]:
                swaped = 1
                l[j+1],l[j] = l[j],l[j+1]
            
        print(f"{i+1} pass :- ",l)
        if swaped==0:
            return l
    return l

def InsertionSort(l):
    n = len(l)
    for i in range(1,n):
        key = l[i]
        j = i-1
        while j>=0 and key<l[j]:
            l[j+1] = l[j]
            j-=1
        l[j+1] = key
        print(f"{i} pass :- ",l)
    return l

def ShellSort(l):
    n = len(l)
    gap = n//2
    while gap>=1:
        for j in range(gap,n):
            i = j-gap
            while i>=0:
                if l[i]>l[i+gap]:
                    l[i],l[i+gap] = l[i+gap],l[i]
                    i = i-gap
                else:
                    break
        gap //=2
        
    return l





l = in_list()
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
        print("Sorted List :- ",SelectionSort(l))
        print("-----------------------------------------")
    elif ch==2:
        print("---------Bubble Sort Result-----------")
        print("Sorted List :- ",BubbleSort(l))
        print("-----------------------------------------")
    elif ch==3:
        print("---------Insertion Sort Result-----------")
        print("Sorted List :- ",InsertionSort(l))
        print("-----------------------------------------")
    elif ch==4:
        print("---------Shell Sort Result-----------")
        print("Sorted List :- ",ShellSort(l))
        print("-----------------------------------------")
    else:
        print("Invalid Choice!!")
    ans = input("Do you want to continue(y/n)?? :- ")



