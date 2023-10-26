class QuickSort:

    def __init__(self,n):
        self.n = n
    
    def in_list(self):
        l = []
        for i in range(self.n):
            x = int(input(f"Enter element {i+1} :- "))
            l.append(x)
        return l
    
    def Partition(self,arr,s,e):
        pivot = arr[s]
        cnt=0
        for i in range(s+1,e+1):
            if(arr[i]<=pivot):
                cnt+=1
        pivotIndex = s+cnt
        arr[s],arr[pivotIndex]=arr[pivotIndex],arr[s]
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

    def quickSort(self,arr,s,e):
        if s>=e :
            return
        p = self.Partition(arr,s,e)
        self.quickSort(arr,s,p-1)
        self.quickSort(arr,p+1,e)

t = QuickSort(int(input("Enter number of elements :- ")))
arr = t.in_list()
print("------------------------------------")
print("List :- ",arr)
print()


t.quickSort(arr,0,len(arr)-1)

print("---------Quick Sort Result-----------")
print("Sorted List is :- ",arr)
print("-------------------------------------")