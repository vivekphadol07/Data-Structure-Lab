'''
DSL Assignment-3

Name: Vivek Gorakh Phadol
Class: SE Computer
Batch: B4
Roll No: 66

Que. Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.

'''

Group_A = []
Group_B = []
Group_C = []
uni = []

def get():
    print("Enter no of students who play Cricket")
    C = int(input())
    global Group_A
    print("Enter the roll no who play cricket")
    for i in range(C):
        cri = int(input("Enter Roll no. "))
        Group_A.append(cri)
    print(Group_A)

    print("Enter no of students who play Badminton")
    B = int(input())
    global Group_B
    print("Enter the roll no who play Badminton")
    for i in range(B):
        bad = int(input("Enter Roll no. "))
        Group_B.append(bad)
    print(Group_B)

    print("Enter no of students who play Football")
    F = int(input())
    global Group_C
    print("Enter the roll no who play Football")
    for i in range(F):
        foot = int(input("Enter Roll no. "))
        Group_C.append(foot)
    print(Group_C)
    print("Enter no. of  student in class")
    U = int(input())
    global uni
    for i in range(U):
        uni.append(i+1)
    print(uni)

#List of student who play both cricket and badminton.
def cri_bad():
    uni_cri_bad = []
    for i in Group_A:
        for j in Group_B:
            if i == j :
                uni_cri_bad.append(j)
    print("Student who play both cricket and badminton")
    print(uni_cri_bad)

#List of student who play either cricket or badminton but not both.
def cri_bad_not_both():
    not_cri_bad =[]
    for i in Group_A :
        if i not in Group_B:
            not_cri_bad.append(i)
    for j in Group_B:
        if j not in Group_A:
            not_cri_bad.append(j)
    print("Student who play either cricket or badminton but not both")
    print(not_cri_bad)

#List of student who play neither cricket nor badminton.
def nei_cri_nor_bad():
    uni_cri_bad = []
    uni_cri_bad.extend(Group_A)
    for j in Group_B:
        if j not in Group_A:
            uni_cri_bad.append(j)

    not_cri_bad = []
    for i in uni:
        if i not in uni_cri_bad:
            not_cri_bad.append(i)
    print("Student who play neither cricket nor badminton")
    print(not_cri_bad)

#List of student heo play cricket and football but not badminton.
def cri_foot_not_bad():
    cri_foot = []
    cri_foot.extend(Group_A)
    for i in Group_C :
        if i not in Group_A:
            cri_foot.append(i)
    final=[]
    for j in cri_foot:
        if j not in Group_B:
            final.append(j)
    print("Student heo play cricket and football but not badminton.")
    print(final)


print("\t******* Main Menu *******\t")
print("1. List of students who play both cricket and badminton. \n2. List of students who play either cricket or badminton but not both. \n3. Number of students who play neither cricket nor badminton. \n4. Number of students who play cricket and football but not badminton. \n5. Exit")

get()

while(True):
    print("\nEnter the choice ")

    choice = int(input())
    if(choice == 1):
        cri_bad()
    elif(choice == 2):
        cri_bad_not_both()
    elif(choice == 3):
        nei_cri_nor_bad()
    elif(choice == 4):
        cri_foot_not_bad()
    elif(choice == 5):
        print("EXIT")
        exit()

'''
Output

        ******* Main Menu *******
1. List of students who play both cricket and badminton.
2. List of students who play either cricket or badminton but not both.
3. Number of students who play neither cricket nor badminton.
4. Number of students who play cricket and football but not badminton.
5. Exit

Enter no of students who play Cricket
5
Enter the roll no who play cricket
Enter Roll no. 1
Enter Roll no. 4
Enter Roll no. 5
Enter Roll no. 8
Enter Roll no. 9
[1, 4, 5, 8, 9]

Enter no of students who play Badminton
5
Enter the roll no who play Badminton
Enter Roll no. 1
Enter Roll no. 2
Enter Roll no. 5
Enter Roll no. 6 
Enter Roll no. 7
[1, 2, 5, 6, 7]

Enter no of students who play Football
3
Enter the roll no who play Football
Enter Roll no. 3
Enter Roll no. 5
Enter Roll no. 9
[3, 5, 9]

Enter no. of  student in class
10
[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Enter the choice 
1
Student who play both cricket and badminton.
[1, 5]

Enter the choice 
2.
Student who play either cricket or badminton but not both.
[4, 8, 9, 2, 6, 7]

Enter the choice 
3
Student who play neither cricket nor badminton.
[3, 10]

Enter the choice 
4
Student heo play cricket and football but not badminton.
[4, 8, 9, 3]

Enter the choice 
5
EXIT

'''