"""
DSL Assignment-1

Name: Vivek Gorakh Phadol
Class: SE Computer
Batch: B4
Roll No: 66

Que. Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency
"""

class Student:
    marks = []
    nos = 0

    def get(self):
        for i in range(0,100):
            self.marks.append(0)
        self.nos = int(input("\nEnter Number of Students: "))   
        print("\nEnter DSA marks(For absent student enter -1):")   
        for i in range(0,self.nos):
            self.marks[i] = int(input("\tMarks: "))

    def repeated_marks(self):
        a=[]
        for i in range(0,100): 
            a.append(0)
        for i in range(0,self.nos):
            for j in range(0,100):
                if(self.marks[i]==j):
                    a[j] = a[j] + 1
                j = j + 1 
            i = i + 1

        max=a[0]
        temp=0
        for i in range(0,100):
            if(max<a[i]):
                max=a[i]
                temp=i
        print("\nMarks scored by most of the students : ",temp)

    def average(self):
        sum=0
        avg=0
        x=self.nos
        for i in range(0,self.nos):
            if(self.marks[i]!=-1):
                sum = sum + self.marks[i]
            elif(self.marks[i]==-1):
                x = x - 1
        avg = sum/x
        print("\nAverage Marks : ",round(avg,2))

    def highest_lowest(self):
        max = min = self.marks[0]
        for i in range(0,self.nos):
            if(self.marks[i]!=-1):
                if(self.marks[i]<min):
                    min = self.marks[i]
                if(self.marks[i]!=-1):
                    if(self.marks[i]>max):
                         max = self.marks[i]
        print("\nHighest Marks : ",max,"\n\nLowest Marks : ",min)

    def absent(self):
        count=0
        for i in range(0,self.nos):
            if(self.marks[i]==-1):
                count+=1
        print("\nStudents absent for test are:",count)
        for i in range(0,self.nos):
            if(self.marks[i]==-1):
                print("\tRoll No. :",i+1)

d = Student()
d.get()
d.average()
d.highest_lowest()
d.absent()
d.repeated_marks()

"""
Output

Enter Number of Students: 7

Enter DSA marks(For absent student enter -1):
	Marks: 38
	Marks: 56
	Marks: -1
	Marks: 67  
	Marks: -1
	Marks: 89
	Marks: 25

Average Marks :  55.0

Highest Marks :  89 

Lowest Marks :  25

Students absent for test are: 2
	Roll No. : 3
	Roll No. : 5

Marks scored by most of the students :  25




Enter Number of Students: 5

Enter DSA marks(For absent student enter -1):
	Marks: 87
	Marks: -1
	Marks: 78
	Marks: -1
	Marks: 45

Average Marks :  70.0

Highest Marks :  87 

Lowest Marks :  45

Students absent for test are: 2
	Roll No. : 2
	Roll No. : 4

Marks scored by most of the students :  45


"""
