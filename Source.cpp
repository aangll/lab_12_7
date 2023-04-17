#include <iostream>
#include <string>

using namespace std;

struct Subscriber {
    string last_name;
    string phone_number;
    double arrears;
    Subscriber* next;
};

// function to add a new subscriber to the list
void addSubscriber(Subscriber*& head, string last_name, string phone_number, double arrears) {
    Subscriber* new_subscriber = new Subscriber;
    new_subscriber->last_name = last_name;
    new_subscriber->phone_number = phone_number;
    new_subscriber->arrears = arrears;
    new_subscriber->next = nullptr;

    if (head == nullptr) {
        head = new_subscriber;
    }
    else {
        Subscriber* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
}

// function to create a new list of subscribers who owe more than a specified amount
Subscriber* createNewList(Subscriber* head, double threshold) {
    Subscriber* new_head = nullptr;
    Subscriber* current = head;
    while (current != nullptr) {
        if (current->arrears > threshold) {
            addSubscriber(new_head, current->last_name, current->phone_number, current->arrears);
        }
        current = current->next;
    }
    return new_head;
}

// function to print the list of subscribers
void printList(Subscriber* head) {
    Subscriber* current = head;
    while (current != nullptr) {
        cout << current->last_name << ", " << current->phone_number << ", " << current->arrears << endl;
        current = current->next;
    }
}

int main() {
    Subscriber* head = nullptr;
    int num_subscribers;
    double threshold;

    // prompt user to input number of subscribers
    cout << "Enter the number of subscribers: ";
    cin >> num_subscribers;

    // loop through each subscriber and add to the list
    for (int i = 0; i < num_subscribers; i++) {
        string last_name, phone_number;
        double arrears;
        cout << "Enter subscriber's last name: ";
        cin >> last_name;
        cout << "Enter subscriber's phone number: ";
        cin >> phone_number;
        cout << "Enter subscriber's payment arrears: ";
        cin >> arrears;
        addSubscriber(head, last_name, phone_number, arrears);
    }

    // prompt user to input threshold for arrears
    cout << "Enter the arrears threshold: ";
    cin >> threshold;

    // create a new list of subscribers who owe more than the threshold
    Subscriber* new_head = createNewList(head, threshold);

    // print the original list and the new list
    cout << "Original list of subscribers:" << endl;
    printList(head);
    cout << endl << "List of subscribers with arrears above the threshold:" << endl;
    printList(new_head);

    return 0;
}