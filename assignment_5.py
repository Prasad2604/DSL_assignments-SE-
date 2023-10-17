def in_list():
    n = int(input("Enter number of elements of the list :- "))
    l = []
    for i in range(n):
        x = int(input(f"Enter element {i+1} :- "))
        l.append(x)
    return l

def SelectionSort(l):
    n = len(l)
    for i in range(n-1):
        minindex = i
        for j in range(i+1,n):
            if(l[j]<l[minindex]):
                minindex = j
        l[i],l[minindex]=l[minindex],l[i]
    return l

# l =[5,4,3,2,1,20,9,45]
# print(SelectionSort(l))

def BubbleSort(l):
    n  = len(l)
    for i in range(n):
        for j in range(0,n-i-1):
            if l[j]>l[j+1]:
                l[j],l[j+1] = l[j+1],l[j]
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
    return l

def ShellSort(l):
    n = len(l)
    gap = n//2
    while(gap>=1):
        for j in range(gap,n):
            i = j-gap
            while(i>=0):
                if l[i]>l[i+gap]:
                    l[i],l[i+gap] = l[i+gap],l[i]
                else:
                    break
                i = i-gap
        gap //=2
    return l

l = in_list()

ans = 'y'
while(ans=='y'):
    print()
    print("""Choices :- 
          1.Sort an array using Selection Sort.
          2.Sort an array using Bubble Sort.
          3. Sort an array using Insertion Sort.
          4.Sort an array using Shell Sort.""")
    
    print()

    ch = int(input("Enter your choice :- "))

    if ch==1:
        print("--------------Selection Sort Result--------------")
        print("Selection Sort :- ",SelectionSort(l))
        print("-------------------------------------------------")
    elif ch==2:
        print("--------------Bubble Sort Result-----------------")
        print("Bubble Sort :- ",BubbleSort(l))
        print("-------------------------------------------------")
    elif ch==3:
        print("--------------Insertion Sort Result--------------")
        print("Insertion Sort :- ",InsertionSort(l))
        print("-------------------------------------------------")
    elif ch==4:
        print("--------------Shell Sort Result------------------")
        print("Shell Sort :- ",ShellSort(l))
        print("-------------------------------------------------")
    else:
        print("Invalid Choice")
    ans = input("Do you want to continue(y/n)?? :- ")
