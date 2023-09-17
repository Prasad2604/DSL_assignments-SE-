class Strings:

    def __init__(self,s):
        self.s = s
    
    def max_l(self):
        #l=self.s.split()
        s = str()
        l=[]
        for i in self.s:
            if i!=" ":
                s+=i
            else:
                l.append(s)
                s = str()
        if(len(s)!=0):
            l.append(s)
        #print(l)
        max1 = len(l[0])
        k=0
        for i in l:
            if len(i)>max1:
                max1 = len(i)
                k=i
        return k
    
    def palindrome(self):
        s1=str()
        l=[]
        for i in range(1,len(self.s)+1):
            l.append(self.s[-i].lower())
        for j in l:
            s1+=j
        if self.s==s1:
            return "String is palindrome"
        else:
            return "Not palindrome"

    def count_s(self):
        c=0
        ch = input(f"Enter charecter you want to search in {self.s} :-")
        x = len(ch)
        for i in range(len(self.s)):
            if self.s[i]==ch[0]:
                if self.s[i:i+x]==ch:
                    c+=1
        if c!=0:
            return c
        else:
            return "No such word present"
    
    def count_word(self):
        #l=self.s.split()
        s1 = str()
        l=[]
        for i in self.s:
            if i!=" ":
                s1+=i
            else:
                l.append(s1)
                s1 = str()
        if(len(s1)!=0):
            l.append(s1)
        w = input("Enter word you wanna count :-")
        c=0
        for i in l:
            if w==i:
                c+=1
        if c!=0:
            return c
        else:
            return "No such word present"
    
    def search(self):
        s1 = input(f"Enter substring you want to search in {self.s} :-")
        x = len(s1)
        for i in range(len(self.s)):
            if self.s[i]==s1[0]:
                if self.s[i:i+x]==s1:
                     return i
        return -1
    def Upper(self):
        s1 = str()
        for i in self.s:
            if ord(i)>=65 and ord(i)<=90:
                s1+=i
            elif ord(i)>=97 and ord(i)<=122:
                s1+=chr(ord(i)-32)
            else:
                s1+=i
                
        return s1
            
print("""Choices :-
      1.Find word with maximum length in the given string.
      2.Check whether a given word is palindrome or not.
      3.Count a particular substring in the given string.
      4.Count the frequency of particular word in the given string.
      5.Search for a substring in the given string and return the index of it's 1st occurance.
      6.Convert any string to upper case.
      """)

ans = 'y'
while(ans.lower()=='y'):
    print()
    ch  = int(input("Enter your choice(1-6) :- "))
    print()
    if ch==1:
        s1 = Strings(input("Enter a string :- "))
        print(s1.max_l())
    elif ch==2:
        s2 = Strings(input("Enter a word :- "))
        print(s2.palindrome())
    elif ch==3:
        s3 = Strings(input("Enter a string :- "))
        print(s3.count_s())
    elif ch==4:
        s5 = Strings(input("Enter a string :- "))
        print(s5.count_word())

    elif ch==5:
        s4 = Strings(input("Enter a string :- "))
        print(s4.search())
    
    elif ch==6:
        s6 = Strings(input("Enter a string :- "))
        print(s6.Upper())
    else:
        print("Please enter a valid choice !!")
    print()
    
    ans = input("Do you want to continue(y/n)?? :- ")