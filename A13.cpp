/*
FDS Assignment-12

Que. Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array.
*/

#include <iostream>
using namespace std;
#define size 5

class pizza
{
    int porder[size];
    int front,rear;
    public:
        pizza()
        {
            front=rear=-1;
        }
        int qfull()
        {
            if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
                return 1;
            else
                return 0;
        }
        int qempty()
        {
            if(front==-1)
                return 1;
            else
                return 0;
        }
        void accept_order(int);
        void make_payment(int);
        void order_in_queue();
};

void pizza::accept_order(int item)
{
    if(qfull())
        cout<<"\nVery Sorry !!!! No more orders..\n";
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%size;
        }
        porder[rear]=item;
    }
}

void pizza::make_payment(int n)
{
    int item;
    //char ans;
    if(qempty())
        cout<<"\nSorry !!! Order is not there...\n";
    else
    {
        cout<<"\nDeliverd orders as follows...\n";
        for(int i=0;i<n;i++)
        {
            item=porder[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front=(front+1)%size;
            }
            cout<<"\t"<<item;
        }
        cout<<"\nTotal amount to pay : "<<n*100;
        cout<<"\nThank you Visit Again....\n";
    }
}

void pizza::order_in_queue()
{
    int temp;
    if(qempty())
    {
        cout<<"\nSorry !! There is no pending order...\n";
    }
    else
    {
        temp=front;
        cout<<"\nPending Order as follows..\n";
        while(temp!=rear)
        {
            cout<<"\t"<<porder[temp];
            temp=(temp+1)%size;
        }
        cout<<"\t"<<porder[temp];
    }
}

int main()
{
    pizza p1;
    int ch,k,n;
    do
    {
        cout<<"\n\t***** Welcome To Pizza Parlor *******\n";
        cout<<"\n1.Accept Order\n2.Make Payment\n3.Pending Orders\n4.Exit\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\nWhich Pizza do u like most....\n";
                    cout<<"\n1.Veg Soya Pizza\n2.Veg Butter Pizza\n3.Egg_Pizza";
                    cout<<"\nPlease Enter Your Order: ";
                    cin>>k;
                    p1.accept_order(k);
                    break;
            case 2:cout<<"\nHow many Pizza ?";
                    cin>>n;
                    p1.make_payment(n);
                    break;
            case 3:cout<<"\n Following orders are in queue to deliver....as follows..\n";
                    p1.order_in_queue();
                    break;
            case 4: cout<<"Exit"<<endl;
                    exit(0);
            default:
                    cout<<"Invalid Choice";
        }
    }
    while(ch!=4);
    return 0;
}


/*
Output

        ***** Welcome To Pizza Parlor *******

1.Accept Order
2.Make Payment
3.Pending Orders
4.Exit
Enter Your Choice: 1

Which Pizza do u like most....

1.Veg Soya Pizza
2.Veg Butter Pizza
3.Egg_Pizza
Please Enter Your Order: 1

        ***** Welcome To Pizza Parlor *******

1.Accept Order
2.Make Payment
3.Pending Orders
4.Exit
Enter Your Choice: 1

Which Pizza do u like most....

1.Veg Soya Pizza
2.Veg Butter Pizza
3.Egg_Pizza
Please Enter Your Order: 2

        ***** Welcome To Pizza Parlor *******

1.Accept Order
2.Make Payment
3.Pending Orders
4.Exit
Enter Your Choice: 2

How many Pizza ?1

Deliverd orders as follows...
        1
Total amount to pay : 100
Thank you Visit Again....

        ***** Welcome To Pizza Parlor *******

1.Accept Order
2.Make Payment
3.Pending Orders
4.Exit
Enter Your Choice: 3

 Following orders are in queue to deliver....as follows..

Pending Order as follows..
        2
        ***** Welcome To Pizza Parlor *******

1.Accept Order
2.Make Payment
3.Pending Orders
4.Exit
Enter Your Choice: 4

*/


