/*
FDS Assignment-13

Que. A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. 
Obtain a data representation mapping a deque into a one- dimensional array. Write C++ program to simulate deque
with functions to add and delete elements from either end of the deque.
*/

#include <iostream>
using namespace std;
# define M 5

int getData();

class Dequeue
{
    int data[M];
    int front;
    int rear;

    public:
        Dequeue()
        {
            front = rear = -1;
        }
        bool isFull();
        bool isEmpty();
        void insertAtFront(int);
        void insertAtRear(int);
        void deleteFromFront();
        void deleteFromRear();
        void display();
};

bool Dequeue::isEmpty()
{
    return front == -1 && rear == -1;
}
bool Dequeue::isFull()
{
    return  (front == 0 && rear == M - 1) || (front == rear + 1) ;
}

void Dequeue::insertAtFront(int val)
{
    if(isFull())
    {
        cout << "DE-Queue is full"<<endl;
        return;
    }
    else if(isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
        front = M-1;
    
    else
        front--;
        
    data[front] = val;
    cout << "enqueued " << val << " to front" <<endl <<endl;
}

void Dequeue::insertAtRear(int val)
{
    if(isFull())
    {
        cout << "DE-Queue is full"<<endl;
        return;
    }
    else if(isEmpty())
    {
        front++;
        rear++;
    }
    else if(rear == M-1)
        rear = 0;
    
    else
        rear++;
    
    data[rear] = val;
    cout << "enqueued " << val << " to rear" <<endl <<endl;
}

void Dequeue::deleteFromFront()
{
    int temp = data[front];  

    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    else if(front == rear)
        front = rear = -1;

    else if(front == M-1)
        front = 0;

    else 
        front++;
    
    cout << "dequeued " << temp << " from front" <<endl <<endl;
}

void Dequeue::deleteFromRear()
{
    int temp = data[rear]; 

    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }

    else if(front == rear)
        front = rear = -1;

    else if( rear == 0)
        rear = M-1;
    
    else
        rear--;

    cout << "dequeued " << temp << " from rear" <<endl <<endl;

}

void Dequeue::display()
{    
    if(isEmpty())
    {
        cout << "DE-Queue is empty"<<endl;
        return;
    }
    cout << endl << "DE-Queue is :   ";

    for(int i=front; i!=rear; i=(i+1)%M)
    {
        cout << data[i] << " ";
    }
    cout << data[rear];
    cout << endl;
    cout << endl;
}


int main () 
{
    int x, ch;
    Dequeue deque;

    while(true)
    {
        cout << endl
             << "    DE-QUEUE OPERATIONS    " << endl
             << endl
             << "1-Insert At Front" << endl
             << "2-Insert At Rear" << endl
             << "3-Delete From Front" << endl
             << "4-Delete From Rear" << endl
             << "5-Display" << endl
             << "0-Exit" << endl;
        cout << " ==>your choice ";
        cin >> ch;
        cout << endl;

        switch(ch){
            case 1:
                x = getData();
                deque.insertAtFront(x);
                break;
            case 2:
                x = getData();
                deque.insertAtRear(x);
                break;
            case 3:
                deque.deleteFromFront();
                break;
            case 4:
                deque.deleteFromRear();
                break;
            case 5:
                deque.display();
                break;
            case 0:
                cout << ". . . . . Terminating . . . . ." << endl;
                exit(0);
            default:
                cout << "Invalid choice";
                break;
        }
    }
    return 0;
}

int getData()
{
    cout << "   ==>Enter data  ";
    int x;
    cin >> x;
    cout << endl;
    return x;
}


/*
Output

    DE-QUEUE OPERATIONS    

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Rear
5-Display
0-Exit
 ==>your choice 1

   ==>Enter data  10

enqueued 10 to front


    DE-QUEUE OPERATIONS    

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Rear
5-Display
0-Exit
 ==>your choice 2

   ==>Enter data  20

enqueued 20 to rear


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Rear
5-Display
0-Exit
 ==>your choice 4

dequeued 20 from rear


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Rear
5-Display
0-Exit
 ==>your choice 5


DE-Queue is :   10


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Rear
5-Display
0-Exit
 ==>your choice 3

dequeued 10 from front


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Rear
5-Display
0-Exit
 ==>your choice 0

. . . . . Terminating . . . . .

*/