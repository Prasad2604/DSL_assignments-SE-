def max_l(s):
        #l=s.split()
        s1 = str()
        l=[]
        for i in s:
            if i!=" ":
                s1+=i
            else:
                l.append(s1)
                s1 = str()
        if(len(s1)!=0):
            l.append(s1)
        #print(l)
        max1 = len(l[0])
        k=''
        for i in l:
            if len(i)>max1:
                max1 = len(i)
                k=i
        return k
    
def palindrome(s):
        s1=str()
        l=[]
        for i in range(1,len(s)+1):
            l.append(s[-i].lower())
        for j in l:
            s1+=j
        if s==s1:
            return "String is palindrome"
        else:
            return "Not palindrome"

def count_s(s):
        c=0
        ch = input(f"Enter substring you want to search in {s} :-")
        x = len(ch)
        for i in range(len(s)):
            if s[i].lower()==ch[0].lower():
                if s[i:i+x]==ch:
                     c+=1
        if c!=0:
            return c
        else:
            return "No such word present"
    
def count_word(s):
        #l=s.split()
        s1 = str()
        l=[]
        for i in s:
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
    
def search(s):
        s1 = input(f"Enter substring you want to search in {s} :-")
        x = len(s1)
        
        for i in range(len(s)):
            if s[i]==s1[0]:
                if s[i:i+x]==s1:
                     return i       
        return -1
def upper(s):
    s1 = str()
    for i in s:
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
      3.Count a particular charecter in the given string.
      4.Count the frequency of particular word in the given string.
      5.Search for a substring in the given string and return the index of it's 1st occurance.
      6.Convert string to upper case.""")

ans = 'y'
while(ans.lower()=='y'):
    print()
    ch  = int(input("Enter your choice(1-6) :- "))
    print()
    if(ch==1):
          s = input("Enter a string :- ")
          print(max_l(s))
    elif ch==2:
         s = input("Enter a word :- ")
         print(palindrome(s))
    elif ch==3:
         s = input("Enter a string :- ")
         print(count_s(s))
    elif ch==4:
         s = input("Enter a string :- ")
         print(count_word(s))
    elif ch==5:
         s = input("Enter a string :- ")
         print(search(s))
    elif ch==6:
         s=input("Enter a string :- ")
         print(upper(s))
    else:
         print("Please enter a valid choice !!")
    print()
    ans = input("Do you want to continue(y/n)?? :- ")
    
     







