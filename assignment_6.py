def Partition(arr,s,e):
    pivot = arr[s]
    cnt = 0
    for i in range(s+1,e+1):
        if(arr[i]<pivot):
            cnt+=1
    pivotIndex = s+cnt
    arr[pivotIndex],arr[s]=arr[s],arr[pivotIndex]
    i = s
    j = e
    while(i<pivotIndex and j>pivotIndex):
        while(arr[i]<=pivot):
            i+=1
        while(arr[j]>pivot):
            j-=1
        if(i<pivotIndex and j>pivotIndex):
            arr[i],arr[j] = arr[j],arr[i]
            i+=1
            j-=1

    return pivotIndex




def quickSort(arr,s,e):
    if s>=e:
        return
    p = Partition(arr,s,e)
    quickSort(arr,s,p-1)
    quickSort(arr,p+1,e)

def in_list():
    l = []
    p = int(input("Enter number of elements :- "))
    for i in range(p):
        x = int(input(f"Enter element {i+1} :- "))
        l.append(x)
    return l

arr = in_list()
quickSort(arr,0,len(arr)-1)
print("Sorted array is :- ",arr)
