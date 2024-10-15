"""
DSL Assignment-4

Que. Write a Program to store roll no. of Sudents in array attended training program in sorted order. 
Write a function for searching whether particular student attended training program or not using binary
and fibonacci search.

"""

list2 = []
n = int(input("Enter the number of students attended the training program: "))

for i in range(n):
    number_input = int(input("\nEnter Roll no: "))
    list2.append(number_input)

print("\nThe details stored are:")
print(list2)


def Binary_Search(list_1, low, high, x):
    if low <= high:
        mid = (low + high) // 2
        if list_1[mid] == x:
            return mid
        elif list_1[mid] > x:
            return Binary_Search(list_1, low, mid - 1, x)
        else:
            return Binary_Search(list_1, mid + 1, high, x)
    else:
        return -1


def Fibonacci_Search(list_2, n, x):
    fib = [0, 1]
    while True:
        m = fib[-1] + fib[-2]
        if m >= n:
            break
        fib.append(m)
    
    offset = -1
    i = 0
    while fib[-1] > 1:
        i = min(offset + fib[-3], n - 1)
        if list_2[i] < x:
            fib = fib[1:]  
            offset = i
        elif list_2[i] > x:
            fib = fib[:-2]  
        else:
            return i
    if fib[-2] and offset + 1 < n and list_2[offset + 1] == x:
        return offset + 1
    return -1


def Searching(list2, n):
    while True:
        print("\n1. Binary Search\n2. Fibonacci Search\n3. Exit")
        choice = int(input("\nEnter your choice: "))

        if choice == 1:
            y = int(input("\nEnter the Roll no to search: "))
            result = Binary_Search(list2, 0, n - 1, y)
            if result != -1:
                print("\nStudent is present at position:", result + 1)
            else:
                print("\nStudent is not present for the program")

        elif choice == 2:
            y = int(input("\nEnter the Roll no to search: "))
            result = Fibonacci_Search(list2, n, y)
            if result != -1:
                print("\nStudent is present at position:", result + 1)
            else:
                print("\nStudent is not present for the program")

        elif choice == 3:
            print("Exiting...")
            break
        else:
            print("Invalid choice")

list2.sort()
print("\nThe sorted list is:")
print(list2)

Searching(list2, n)

'''
OUTPUT :
Enter the number of students attended the training program: 15

Enter Roll no: 12

Enter Roll no: 14

Enter Roll no: 16

Enter Roll no: 18

Enter Roll no: 20

Enter Roll no: 2

Enter Roll no: 4

Enter Roll no: 8

Enter Roll no: 6

Enter Roll no: 1

Enter Roll no: 7

Enter Roll no: 9

Enter Roll no: 17

Enter Roll no: 19

Enter Roll no: 11

The details stored are:
[12, 14, 16, 18, 20, 2, 4, 8, 6, 1, 7, 9, 17, 19, 11]

The sorted list is:
[1, 2, 4, 6, 7, 8, 9, 11, 12, 14, 16, 17, 18, 19, 20]

1. Binary Search
2. Fibonacci Search
3. Exit

Enter your choice: 1 

Enter the Roll no to search: 12

Student is present at position: 9

1. Binary Search
2. Fibonacci Search
3. Exit

Enter your choice: 2

Enter the Roll no to search: 12

Student is present at position: 9

1. Binary Search
2. Fibonacci Search
3. Exit

Enter your choice: 3
Exiting...

'''
