#include <iostream>

using namespace std;

class SeatNode {
public:
    int seatNumber;
    bool isBooked;
    SeatNode* next;
    SeatNode* prev;

    SeatNode(int num) : seatNumber(num), isBooked(false), next(nullptr), prev(nullptr) {}
};

class Cinemax {
private:
    SeatNode* rows[10]; // Array to store head pointers for each row

public:
    Cinemax() {
        // Initialize rows and create the doubly circular linked list for each row
        for (int i = 0; i < 10; i++) {
            rows[i] = nullptr;
            SeatNode* prev = nullptr;
            for (int j = 1; j <= 7; j++) {
                SeatNode* newSeat = new SeatNode(j);
                if (!rows[i]) {
                    rows[i] = newSeat;
                    rows[i]->next = rows[i];
                    rows[i]->prev = rows[i];
                } else {
                    newSeat->prev = prev;
                    newSeat->next = rows[i];
                    prev->next = newSeat;
                    rows[i]->prev = newSeat;
                }
                prev = newSeat;
            }
        }

        // Randomly book some seats
        rows[0]->isBooked = true; // Row 1, Seat 1
        rows[4]->next->isBooked = true; // Row 5, Seat 2
    }

    void displayAvailableSeats() {
        cout << "Available seats:\n";
        for (int i = 0; i < 10; i++) {
            cout << "Row " << i + 1 << ": ";
            SeatNode* temp = rows[i];
            bool hasAvailableSeats = false;
            do {
                if (!temp->isBooked) {
                    cout << temp->seatNumber << " ";
                    hasAvailableSeats = true;
                }
                temp = temp->next;
            } while (temp != rows[i]);

            if (!hasAvailableSeats) {
                cout << "All seats booked";
            }
            cout << endl;
        }
    }

    void bookSeat(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid row or seat number.\n";
            return;
        }

        SeatNode* temp = rows[row - 1];
        do {
            if (temp->seatNumber == seat) {
                if (temp->isBooked) {
                    cout << "Seat already booked.\n";
                } else {
                    temp->isBooked = true;
                    cout << "Seat " << seat << " in Row " << row << " successfully booked.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);

        cout << "Seat not found.\n";
    }

    void cancelBooking(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid row or seat number.\n";
            return;
        }

        SeatNode* temp = rows[row - 1];
        do {
            if (temp->seatNumber == seat) {
                if (!temp->isBooked) {
                    cout << "Seat is not booked.\n";
                } else {
                    temp->isBooked = false;
                    cout << "Booking for Seat " << seat << " in Row " << row << " successfully cancelled.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);

        cout << "Seat not found.\n";
    }

    ~Cinemax() {
        // Cleanup memory
        for (int i = 0; i < 10; i++) {
            SeatNode* current = rows[i];
            SeatNode* temp;
            do {
                temp = current;
                current = current->next;
                delete temp;
            } while (current != rows[i]);
        }
    }
};

int main() {
    Cinemax theater;
    int choice, row, seat;

    do {
        cout << "\nCinemax Ticket Booking System\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            theater.displayAvailableSeats();
            break;
        case 2:
            cout << "Enter row number (1-10): ";
            cin >> row;
            cout << "Enter seat number (1-7): ";
            cin >> seat;
            theater.bookSeat(row, seat);
            break;
        case 3:
            cout << "Enter row number (1-10): ";
            cin >> row;
            cout << "Enter seat number (1-7): ";
            cin >> seat;
            theater.cancelBooking(row, seat);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
