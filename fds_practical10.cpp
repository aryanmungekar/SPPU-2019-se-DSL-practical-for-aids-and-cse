// Write C++ program for storing appointment schedule for day. Appointments are
// booked randomly using linked list. Set start and end time and min and max

// duration for visit slot. Write functions for-
// a) Display free slots
// b) Book appointment
// c) Cancel appointment ( check validity, time bounds, availability)
// d) Sort list based on time
// e) Sort list based on time using pointer manipulation

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure to represent an appointment
struct Appointment {
    int startTime; // Start time in minutes since midnight
    int endTime;   // End time in minutes since midnight
    string name;   // Name of the person with the appointment
    Appointment* next; // Pointer to the next appointment in the list
};

// Function prototypes
void displayFreeSlots(Appointment* schedule);
void bookAppointment(Appointment*& schedule, int minDuration, int maxDuration);
void cancelAppointment(Appointment*& schedule);
void sortListByTime(Appointment*& schedule);

// Function to display the schedule
void displaySchedule(Appointment* schedule) {
    cout << "Current Schedule:\n";
    while (schedule != nullptr) {
        cout << setw(10) << schedule->startTime << " - " << setw(10) << schedule->endTime << " : " << schedule->name << endl;
        schedule = schedule->next;
    }
    cout << "---------------------------------\n";
}

// Function to display free slots
void displayFreeSlots(Appointment* schedule) {
    sortListByTime(schedule);
    displaySchedule(schedule);
}

// Function to book an appointment
void bookAppointment(Appointment*& schedule, int minDuration, int maxDuration) {
    srand(time(nullptr));
    
    int startTime = rand() % (24 * 60); // Random start time in minutes since midnight
    int duration = minDuration + rand() % (maxDuration - minDuration + 1); // Random duration
    
    int endTime = startTime + duration;
    
    Appointment* newAppointment = new Appointment{startTime, endTime, "Booked", nullptr};
    
    // Check if the new appointment overlaps with existing ones
    Appointment* current = schedule;
    while (current != nullptr) {
        if ((startTime >= current->startTime && startTime < current->endTime) ||
            (endTime > current->startTime && endTime <= current->endTime) ||
            (startTime <= current->startTime && endTime >= current->endTime)) {
            // Overlapping appointment found
            cout << "Appointment overlap detected. Please try again.\n";
            delete newAppointment;
            return;
        }
        current = current->next;
    }
    
    // Add the new appointment to the schedule
    newAppointment->next = schedule;
    schedule = newAppointment;
    
    cout << "Appointment booked successfully.\n";
}

// Function to cancel an appointment
void cancelAppointment(Appointment*& schedule) {
    int startTime;
    cout << "Enter the start time of the appointment to cancel: ";
    cin >> startTime;

    // Find the appointment to cancel
    Appointment* current = schedule;
    Appointment* prev = nullptr;

    while (current != nullptr) {
        if (current->startTime == startTime) {
            // Appointment found, remove it from the list
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                schedule = current->next;
            }
            delete current;
            cout << "Appointment canceled successfully.\n";
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Appointment not found.\n";
}

// Function to sort the list based on start time
void sortListByTime(Appointment*& schedule) {
    if (schedule == nullptr || schedule->next == nullptr) {
        return;
    }

    Appointment* sorted = nullptr;
    Appointment* current = schedule;

    while (current != nullptr) {
        Appointment* next = current->next;

        if (sorted == nullptr || sorted->startTime >= current->startTime) {
            current->next = sorted;
            sorted = current;
        } else {
            Appointment* search = sorted;
            while (search->next != nullptr && search->next->startTime < current->startTime) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    schedule = sorted;
}

int main() {
    Appointment* schedule = nullptr;

    int choice;
    int minDuration, maxDuration;

    do {
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFreeSlots(schedule);
                break;
            case 2:
                cout << "Enter minimum duration for appointment (in minutes): ";
                cin >> minDuration;
                cout << "Enter maximum duration for appointment (in minutes): ";
                cin >> maxDuration;
                bookAppointment(schedule, minDuration, maxDuration);
                break;
            case 3:
                cancelAppointment(schedule);
                break;
            case 4:
                // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    // Free memory before exiting
    while (schedule != nullptr) {
        Appointment* temp = schedule;
        schedule = schedule->next;
        delete temp;
    }

    return 0;
}

