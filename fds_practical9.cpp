// The ticket booking system of Cinemax theater has to be implemented using C++
// program. There are 10 rows and 7 seats in each row. Doubly circular linked list has
// to be maintained to keep track of free seats at rows. Assume some random
// booking to start with. Use array to store pointers (Head pointer) to each row. On
// demand
// a) The list of available seats is to be displayed
// b) The seats are to be booked
// c) The booking can be cancelled.

#include <iostream>

using namespace std;

// Node structure to represent a seat in the theater
struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;
};

// Function to initialize a new seat
Seat* createSeat(int seatNumber) {
    Seat* newSeat = new Seat;
    newSeat->seatNumber = seatNumber;
    newSeat->isBooked = false;
    newSeat->next = nullptr;
    newSeat->prev = nullptr;
    return newSeat;
}

// Function to initialize a row with seats
Seat* initializeRow(int seatsPerRow) {
    Seat* head = nullptr;
    Seat* current = nullptr;

    for (int i = 1; i <= seatsPerRow; ++i) {
        Seat* newSeat = createSeat(i);
        if (!head) {
            head = newSeat;
            current = newSeat;
        } else {
            current->next = newSeat;
            newSeat->prev = current;
            current = newSeat;
        }
    }

    // Make the list circular
    if (current) {
        current->next = head;
        head->prev = current;
    }

    return head;
}

// Function to display the list of available seats in a row
void displayAvailableSeats(Seat* head) {
    Seat* current = head;

    cout << "Available seats: ";
    do {
        if (!current->isBooked) {
            cout << current->seatNumber << " ";
        }
        current = current->next;
    } while (current != head);

    cout << endl;
}

// Function to book a seat
void bookSeat(Seat* &head, int seatNumber) {
    Seat* current = head;

    do {
        if (current->seatNumber == seatNumber && !current->isBooked) {
            current->isBooked = true;
            cout << "Seat " << seatNumber << " booked successfully." << endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Seat " << seatNumber << " is already booked or invalid." << endl;
}

// Function to cancel a booked seat
void cancelBooking(Seat* &head, int seatNumber) {
    Seat* current = head;

    do {
        if (current->seatNumber == seatNumber && current->isBooked) {
            current->isBooked = false;
            cout << "Booking for seat " << seatNumber << " cancelled successfully." << endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Seat " << seatNumber << " is not booked or invalid." << endl;
}

int main() {
    const int rows = 10;
    const int seatsPerRow = 7;

    // Array to store pointers to each row
    Seat* rowHeads[rows];

    // Initialize each row
    for (int i = 0; i < rows; ++i) {
        rowHeads[i] = initializeRow(seatsPerRow);
    }

    // Sample bookings
    int seatToBook, seatToCancel;
    cout << "Enter seat number to book: ";
    cin >> seatToBook;
    bookSeat(rowHeads[2], seatToBook);

    cout << "Enter seat number to book: ";
    cin >> seatToBook;
    bookSeat(rowHeads[5], seatToBook);

    cout << "Enter seat number to book: ";
    cin >> seatToBook;
    bookSeat(rowHeads[8], seatToBook);

    // Display available seats
    displayAvailableSeats(rowHeads[2]);

    // Sample cancellations
    cout << "Enter seat number to cancel: ";
    cin >> seatToCancel;
    cancelBooking(rowHeads[5], seatToCancel);

    // Display available seats again
    displayAvailableSeats(rowHeads[5]);

    // Clean up memory
    for (int i = 0; i < rows; ++i) {
        delete rowHeads[i];
    }

    return 0;
}



