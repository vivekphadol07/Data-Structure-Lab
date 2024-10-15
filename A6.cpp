/*
DSL Assignment-6

Que. Write a python program to store first year percentage of students in amray.
     Write function for sorting array of floating point numbers in ascending order using 
     quick sortt and display top 5 scores.
*/

#include <iostream>

using namespace std;

void quick_sort(float arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    float pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main() {
    
    int num;
    cout << "\nEnter the Number of Students for which you want to Enter their Percentage: ";
    cin >> num;

    float percentages[100]; // Assume a maximum of 100 students
    for (int i = 0; i < num; i++) {
        cout << "Enter the Percentage of Student: ";
        cin >> percentages[i];
    }
    quick_sort(percentages, 0, num - 1);

    cout << "Top 5 scores:" << endl;
    for (int i = 1 ; i <= 5 ; i++) {
        cout << percentages[num-i] << endl;
    }
    return 0;
}


/*
OUTPUT:
Enter the Number of Students for which you want to Enter their Percentage: 10
Enter the Percentage of Student: 90
Enter the Percentage of Student: 89
Enter the Percentage of Student: 99
Enter the Percentage of Student: 97
Enter the Percentage of Student: 67
Enter the Percentage of Student: 80
Enter the Percentage of Student: 91
Enter the Percentage of Student: 86
Enter the Percentage of Student: 77
Enter the Percentage of Student: 81

Top 5 scores:
99
97
91
90
89

*/