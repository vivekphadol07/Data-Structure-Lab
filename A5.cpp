/*
DSL Assignment-5

Que. Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
*/
#include <iostream>
using namespace std;

void bubble_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selection_sort(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}


int main() {
    cout << "Which Sorting Operation do you want to Perform?" << endl;
    cout << "\t1. Bubble Sort \n\t2. Selection Sort" << endl;
    int ch;
    cin >> ch;

    int num;
    cout << "\nEnter the Number of Students for which you want to Enter their Percentage: ";
    cin >> num;

    float arr[100]; // Assume a maximum of 100 students
    for (int i = 0; i < num; i++) {
        cout << "Enter the Percentage of Student: ";
        cin >> arr[i];
    }

    if (ch == 1) {
        bubble_sort(arr, num);
    } else if (ch == 2) {
        selection_sort(arr, num);
    } else {
        cout << "Invalid Choice." << endl;
        return 0;
    }


    cout << "Top 5 Students' Marks are:" << endl;
    for (int i =  1; i <= 5; i++) {
        cout<<arr[num - i]<<endl;
    }

    return 0;
}


/*
Output

Which Sorting Operation you want to Perform 
        1. Selection Sort
        2. Bubble Sort

Enter your choice: 1

Enter the Number of Students for which you want to Enter thier Percentage: 8
Enter the Percentage of Student: 98
Enter the Percentage of Student: 65
Enter the Percentage of Student: 34
Enter the Percentage of Student: 57
Enter the Percentage of Student: 68
Enter the Percentage of Student: 48
Enter the Percentage of Student: 19
Enter the Percentage of Student: 56

Top 5 Students Marks are:
98
68
65
57
56




Which Sorting Operation you want to Perform 
        1. Selection Sort
        2. Bubble Sort

Enter your choice: 2

Enter the Number of Students for which you want to Enter thier Percentage: 7
Enter the Percentage of Students: 45
Enter the Percentage of Students: 68
Enter the Percentage of Students: 97
Enter the Percentage of Students: 63
Enter the Percentage of Students: 53
Enter the Percentage of Students: 84
Enter the Percentage of Students: 75

Top 5 Students Marks are:
97
63
75
68
45



Which Sorting Operation you want to Perform 
        1. Selection Sort
        2. Bubble Sort

Enter your choice: 5
Invalid Choice.

*/