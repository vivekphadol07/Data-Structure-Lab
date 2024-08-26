"""
DSL Assignment-2

Name: Vivek Gorakh Phadol
Class: SE Computer
Batch: B4
Roll No: 66

Que. Write a Python program to compute following operations on String: 
a) To display word with the longest length 
b) To determines the frequency of occurrence of particular character in the string 
c) To check whether given string is palindrome or not 
d) To display index of first appearance of the substring 
e) To count the occurrences of each word in a given stringRE
"""

print("\t******* Main Menu *******\t")
print("1. To display word with the longest length \n2. To determines the frequency of occurrence of particular character in the string \n3. To check whether given string is palindrome or not \n4. To display index of first appearance of the substring \n5. To count the occurrences of each word in a given string \n6. Exit")

while (True):

    ch=int(input("\nEnter your Choice to perform String Operation: "))

    if (ch==1):
        str=input("\nEnter your String:")
        length=0
        longest_word=0
        for word in str.split():
            if (len(word)>length):
                length=len(word)
                longest_word=word
        print("The Word",longest_word,"has longest length",length,"in the String")

    elif (ch==2):
        str=input("\nEnter your String: ")
        char=input("Enter the Character to Calculate its Frequency of Occurrence in the String: ")
        count=0
        for i in str:
            if (i==char):
                count=count+1
        print("The Character",char,"appears",count,"times in the String.")

    elif (ch==3):
        str=input("\nEnter your String: ")
        str_rev=str[::-1]
        if(str==str_rev):
            print("The String",str,"is Palindrome.")
        else:
            print("The String",str,"is not Palindrome.")

    elif (ch==4):
        str=input("\nEnter your String: ")
        str1=input("\nEnter your Substring:")
        if(str.find(str1)==-1):
            print("\nThe String",str1,"is not Substring of",str)
        else:
            position=str.find(str1)
            print("\nThe First Apperance of Substring is found at",position)

    elif (ch==5):
        str=input("\nEnter your String: ")
        data=dict()
        words=str.split()
        for word in words:
            if word in data:
                data[word]+=1
            else:
                data[word]=1
        print(data)

    elif (ch==6): 
        print("Exit")
        exit()
    
    else: 
        print("Invalid Choice. \nPlease Enter Valid Choice.")

"""
Output

        ******* Main Menu *******
1. To display word with the longest length
2. To determines the frequency of occurrence of particular character in the string
3. To check whether given string is palindrome or not
4. To display index of first appearance of the substring
5. To count the occurrences of each word in a given string
6. Exit

Enter your Choice to perform String Operation: 1

Enter your String:hello how are you
The Word hello has longest length 5 in the String

Enter your Choice to perform String Operation: 2  

Enter your String:welcome to python programming
Enter the Character to Calculate its Frequency of Occurrence in the String: p
The Character p appears 2 times in the String.

Enter your Choice to perform String Operation: 3

Enter your String:nayan
The String nayan is Palindrome.

Enter your Choice to perform String Operation: 4

Enter your String:i eat a mango

Enter your Substring:eat

The First Apperance of Substring is found at 2

Enter your Choice to perform String Operation: 5  

Enter your String:the sky is blue and the rose is red.
{'the': 2, 'sky': 1, 'is': 2, 'blue': 1, 'and': 1, 'rose': 1, 'red.': 1}

Enter your Choice to perform String Operation: 6
Exit

"""
