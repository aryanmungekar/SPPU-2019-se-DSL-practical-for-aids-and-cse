// Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to: 
// a) Add and delete the members as well as president or even secretary. 
// b) Compute total number of members of club 
// c) Display members


#include<iostream>
using namespace std;

class Student {
public:
    int prn;
    string name;
    Student *next;
};

Student *head = NULL;

void addStudent() {
    Student *newStudent = new Student;
    cout << "Enter PRN: ";
    cin >> newStudent->prn;
    cout << "Enter name: ";
    cin >> newStudent->name;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        Student *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void deleteStudent() {
    if (head == NULL) {
        cout << "Club member list is empty" << endl;
        return;
    }

    int prn;
    cout << "Enter PRN of the student to delete: ";
    cin >> prn;

    if (head->prn == prn) {
        Student *temp = head;
        head = head->next;
        delete temp;
    } else {
        Student *prev = head;
        Student *curr = head->next;
        while (curr != NULL && curr->prn != prn) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            delete curr;
        } else {
            cout << "Student with PRN " << prn << " is not a member of the club" << endl;
        }
    }
}

int totalMembers() {
    int count = 0;
    Student *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayMembers() {
    if (head == NULL) {
        cout << "Club member list is empty" << endl;
        return;
    }

    Student *temp = head;
    while (temp != NULL) {
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "Enter 1 to add a student, 2 to delete a student, 3 to display members, 4 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                cout << "Total number of members: " << totalMembers() << endl;
                displayMembers();
                break;
            case 4:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}

