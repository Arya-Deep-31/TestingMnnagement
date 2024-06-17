// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <string>

// using namespace std;

// struct Visitor {
//     string name;
//     string phone;
//     string address;
//     string feedback;
// };

// struct Event {
//     string name;
//     string venue;
//     string time;
//     string date;
//     string club;
// };

// vector<Visitor> visitors;
// vector<Event> events;

// void loadDataFromFile() {
//     ifstream infile("data.txt");
//     if (infile.is_open()) {
//         // Load visitors
//         int visitorCount;
//         infile >> visitorCount;
//         infile.ignore();
//         if (visitorCount < 0) {
//             cerr << "Invalid number of visitors in file: " << visitorCount << endl;
//             return;
//         }
//         visitors.resize(visitorCount);
//         for (int i = 0; i < visitorCount; ++i) {
//             getline(infile, visitors[i].name);
//             getline(infile, visitors[i].phone);
//             getline(infile, visitors[i].address);
//             getline(infile, visitors[i].feedback);
//         }

//         // Load events
//         int eventCount;
//         infile >> eventCount;
//         infile.ignore();
//         if (eventCount < 0) {
//             cerr << "Invalid number of events in file: " << eventCount << endl;
//             return;
//         }
//         events.resize(eventCount);
//         for (int i = 0; i < eventCount; ++i) {
//             getline(infile, events[i].name);
//             getline(infile, events[i].date);
//             getline(infile, events[i].time);
//             getline(infile, events[i].venue);
//             getline(infile, events[i].club);
//         }

//         infile.close();
//     } else {
//         cerr << "Unable to open file: data.txt" << endl;
//     }
// }

// void saveDataToFile() {
//     ofstream outfile("data.txt");
//     if (outfile.is_open()) {
//         // Save visitors
//         outfile << visitors.size() << endl;
//         for (const auto& visitor : visitors) {
//             outfile << visitor.name << endl;
//             outfile << visitor.phone << endl;
//             outfile << visitor.address << endl;
//             outfile << visitor.feedback << endl;
//         }

//         // Save events
//         outfile << events.size() << endl;
//         for (const auto& event : events) {
//             outfile << event.name << endl;
//             outfile << event.date << endl;
//             outfile << event.time << endl;
//             outfile << event.venue << endl;
//             outfile << event.club << endl;
//         }

//         outfile.close();
//     } else {
//         cerr << "Unable to open file for writing: data.txt" << endl;
//     }
// }

// void addNewVisitor() {
//     char choice;
//     do {
//         cout << "--------------------------------------\n";
//         Visitor visitor;
//         cout << "Enter visitor name: ";
//         cin.ignore();
//         getline(cin, visitor.name);
//         cout << "Enter visitor phone number: ";
//         getline(cin, visitor.phone);
//         cout << "Enter visitor address: ";
//         getline(cin, visitor.address);
//         cout << "Enter feedback: ";
//         getline(cin, visitor.feedback);
//         visitors.push_back(visitor);
//         cout << "Visitor added successfully!\n";
//         cout << "--------------------------------------\n\n";

//         cout << "Enter 'q' to add one more visitor or any other key to return to the main menu: ";
//         cin >> choice;
//         cout << endl;
//     } while (choice == 'q' || choice == 'Q');
// }

// void addFeedback(const string& name) {
//     for (auto& visitor : visitors) {
//         if (visitor.name == name) {
//             cout << "Enter feedback: ";
//             cin.ignore();
//             getline(cin, visitor.feedback);
//             cout << "Feedback added successfully!\n";
//             return;
//         }
//     }
//     cout << "Visitor not found!\n";
// }

// void addEvent() {
//     char choice;
//     do {
//         cout << "--------------------------------------\n";
//         Event event;
//         cout << "Enter event name: ";
//         cin.ignore();
//         getline(cin, event.name);
//         cout << "Enter event date (e.g., 24-02-2024): ";
//         getline(cin, event.date);
//         cout << "Enter event time: ";
//         getline(cin, event.time);
//         cout << "Enter event venue: ";
//         getline(cin, event.venue);
//         cout << "Enter hosting club: ";
//         getline(cin, event.club);
//         events.push_back(event);
//         cout << "Event details added successfully!\n";
//         cout << "--------------------------------------\n\n";

//         cout << "Enter 'q' to add one more event or any other key to return to the main menu: ";
//         cin >> choice;
//         cout << endl;
//     } while (choice == 'q' || choice == 'Q');
// }

// // void adminLogin() {
// //     cout << "--------------------------------------\n";
// //     string password;
// //     cout << "Enter admin password: ";
// //     cin >> password;
// //     cout << endl;

// //     if (password == "admin") {
// //         cout << "Admin access granted!\n\n";

// //         // Print Visitors in tabular form
// //         cout << "Visitors:\n";
// //         cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
// //         cout << "Name\t\t\tPhone\t\t\tAddress\t\t\tFeedback\n";
// //         for (const auto& visitor : visitors) {
// //             cout << visitor.name << "\t\t" << visitor.phone << "\t\t" << visitor.address << "\t\t" << visitor.feedback << endl;
// //         }
// //         cout << "---------------------------------------------------------------------------------------------------------------------------------------\n\n";

// //         // Print Events in tabular form
// //         cout << "Events:\n";
// //         cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
// //         cout << "Name\t\t\tDate\t\t\tTime\t\t\tVenue\t\t\tClub\n";
// //         for (const auto& event : events) {
// //             cout << event.name << "\t\t" << event.date << "\t\t" << event.time << "\t\t\t" << event.venue << "\t\t" << event.club << endl;
// //         }
// //         cout << "---------------------------------------------------------------------------------------------------------------------------------------\n\n";

// //     } else {
// //         cout << "Invalid password\n\n";
// //     }

// //     cout << "Enter 'q' to return to the main menu: ";
// //     char choice;
// //     cin >> choice;
// //     cout << endl;
// // }





// void searchVisitor() {
//     string searchTerm;
//     cout << "Enter name or phone number to search: ";
//     cin.ignore();
//     getline(cin, searchTerm);

//     bool found = false;
//     cout << "Visitor Found: \nName\t\tPhone\t\tAddress\t\tFeedback\n";
//     cout << "--------------------------------------------------------\n";
//     for (const auto& visitor : visitors) {
//         if (visitor.name.find(searchTerm) != string::npos || visitor.phone.find(searchTerm) != string::npos) {
//             cout << visitor.name << "\t\t" << visitor.phone << "\t\t" << visitor.address << "\t\t" << visitor.feedback << endl;
//             found = true;
//         }
//     }

//     if (!found) {
//         cout << "No visitor found with the given search term.\n";
//     }
// }





// void viewAllVisitors() {
//     cout << "Visitors:\n";
//     cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
//     cout << "Name\t\t\tPhone\t\t\tAddress\t\t\tFeedback\n";
//     for (const auto& visitor : visitors) {
//         cout << visitor.name << "\t\t" << visitor.phone << "\t\t" << visitor.address << "\t\t" << visitor.feedback << endl;
//     }
//     cout << "---------------------------------------------------------------------------------------------------------------------------------------\n\n";
// }



// void viewAllEvents() {
//     cout << "Events:\n";
//     cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
//     cout << "Name\t\t\tDate\t\t\tTime\t\t\tVenue\t\t\tClub\n";
//     for (const auto& event : events) {
//         cout << event.name << "\t\t" << event.date << "\t\t" << event.time << "\t\t\t" << event.venue << "\t\t" << event.club << endl;
//     }
//     cout << "---------------------------------------------------------------------------------------------------------------------------------------\n\n";
// }




// void editVisitor() {
//     string phone;
//     cout << "Enter phone number of the visitor to edit: ";
//     cin.ignore();
//     getline(cin, phone);

//     for (auto& visitor : visitors) {
//         if (visitor.phone == phone) {
//             cout << "Enter new name (or press enter to keep current): ";
//             string newName;
//             getline(cin, newName);
//             if (!newName.empty()) visitor.name = newName;

//             cout << "Enter new address (or press enter to keep current): ";
//             string newAddress;
//             getline(cin, newAddress);
//             if (!newAddress.empty()) visitor.address = newAddress;

//             cout << "Enter new feedback (or press enter to keep current): ";
//             string newFeedback;
//             getline(cin, newFeedback);
//             if (!newFeedback.empty()) visitor.feedback = newFeedback;

//             cout << "Visitor details updated successfully!\n";
//             saveDataToFile();
//             return;
//         }
//     }
//     cout << "No visitor found with the given phone number.\n";
// }

// void deleteVisitor() {
//     string phone;
//     cout << "Enter phone number of the visitor to delete: ";
//     cin.ignore();
//     getline(cin, phone);

//     for (auto it = visitors.begin(); it != visitors.end(); ++it) {
//         if (it->phone == phone) {
//             visitors.erase(it);
//             cout << "Visitor deleted successfully!\n";
//             saveDataToFile();
//             return;
//         }
//     }
//     cout << "No visitor found with the given phone number.\n";
// }






// void adminLogin() {
//     cout << "--------------------------------------\n";
//     string password;
//     cout << "Enter admin password: ";
//     cin >> password;
//     cout << endl;

//     if (password == "admin") {
//         int adminChoice;
//         do {
//             cout << "Admin access granted!\n\n";
//             cout << "1. View All Visitors\n";
//             cout << "2. View All Events\n";
//             cout << "3. Search Visitor\n";
//             cout << "4. Edit Visitor\n";
//             cout << "5. Delete Visitor\n";
//             cout << "6. Add Event Details\n";
//             cout << "7. Logout\n";
//             cout << "Enter your choice: ";
//             cin >> adminChoice;

//             switch (adminChoice) {
//                 case 1:
//                     viewAllVisitors();
//                     break;
//                 case 2:
//                     viewAllEvents();
//                     break;
//                 case 3:
//                     searchVisitor();
//                     break;
//                 case 4:
//                     editVisitor();
//                     break;
//                 case 5:
//                     deleteVisitor();
//                     break;
//                 case 6:
//                     addEvent();
//                     break;
//                 case 7:
//                     cout << "Logging out...\n";
//                     break;
//                 default:
//                     cout << "Invalid choice. Please try again.\n";
//             }
//         } while (adminChoice != 7);
//     } else {
//         cout << "Invalid password\n\n";
//     }

//     cout << "Enter 'q' to return to the main menu: ";
//     char choice;
//     cin >> choice;
//     cout << endl;
// }






// int main() {
//     loadDataFromFile();

//     int choice;
//     do {
//         cout << "\n++++++++++    Welcome to Incand Management 2024 System    +++++++++\n";
//         cout << "\n1. Add New Visitor\n";
//         cout << "2. Add Feedback\n";
//         cout << "3. Know About Incand\n";
//         cout << "4. Admin Login\n";
//         cout << "5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         cout << endl;

//         switch (choice) {
//             case 1:
//                 addNewVisitor();
//                 break;
//             case 2: {
//                 string name;
//                 cout << "Enter your name: ";
//                 cin.ignore();
//                 getline(cin, name);
//                 addFeedback(name);
//                 break;
//             }
//             case 3:
//                 cout << "Incand is the annual cultural fest of NIT Silchar, featuring a wide range of events and performances.\n";
//                 cout << "It is a celebration of art, music, dance, and literature, attracting participants from all over the country.\n";
//                 cout << "JThe 2024 theme was seen as a breeze of wind around the riverside dream of the campus! ~ The Rivertopian Dream \n";
                
//                 break;
//             case 4:
//                 adminLogin();
//                 break;
//             case 5:
//                 saveDataToFile();
//                 cout << "Exiting program.\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 5);

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Visitor {
    string name;
    string phone;
    string address;
    string feedback;
};

struct Event {
    string name;
    string venue;
    string time;
    string date;
    string club;

    bool operator<(const Event& other) const {
        return date < other.date;
    }
};

struct VisitorNode {
    Visitor data;
    VisitorNode* next;
};

struct EventNode {
    Event data;
    EventNode* next;
};

class VisitorList {
private:
    VisitorNode* head;

public:
    VisitorList() : head(nullptr) {}

    void addVisitor(const Visitor& visitor) {
        VisitorNode* newNode = new VisitorNode{visitor, nullptr};
        if (!head) {
            head = newNode;
        } else {
            VisitorNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    VisitorNode* getHead() const {
        return head;
    }

    void searchVisitor(const string& searchTerm) {
        VisitorNode* temp = head;
        bool found = false;
        cout << "Visitor Found: \nName\t\tPhone\t\tAddress\t\tFeedback\n";
        cout << "--------------------------------------------------------\n";
        while (temp) {
            if (temp->data.name.find(searchTerm) != string::npos || temp->data.phone.find(searchTerm) != string::npos) {
                cout << temp->data.name << "\t\t" << temp->data.phone << "\t\t" << temp->data.address << "\t\t" << temp->data.feedback << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No visitor found with the given search term.\n";
        }
    }

    void editVisitor(const string& phone) {
        VisitorNode* temp = head;
        while (temp) {
            if (temp->data.phone == phone) {
                cout << "Enter new name (or press enter to keep current): ";
                string newName;
                getline(cin, newName);
                if (!newName.empty()) temp->data.name = newName;

                cout << "Enter new address (or press enter to keep current): ";
                string newAddress;
                getline(cin, newAddress);
                if (!newAddress.empty()) temp->data.address = newAddress;

                cout << "Enter new feedback (or press enter to keep current): ";
                string newFeedback;
                getline(cin, newFeedback);
                if (!newFeedback.empty()) temp->data.feedback = newFeedback;

                cout << "Visitor details updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No visitor found with the given phone number.\n";
    }

    void deleteVisitor(const string& phone) {
        VisitorNode* temp = head;
        VisitorNode* prev = nullptr;
        while (temp) {
            if (temp->data.phone == phone) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                cout << "Visitor deleted successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "No visitor found with the given phone number.\n";
    }

    void viewAllVisitors() {
        VisitorNode* temp = head;
        cout << "Visitors:\n";
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Name\t\t\tPhone\t\t\tAddress\t\t\tFeedback\n";
        while (temp) {
            cout << temp->data.name << "\t\t" << temp->data.phone << "\t\t" << temp->data.address << "\t\t" << temp->data.feedback << endl;
            temp = temp->next;
        }
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n\n";
    }
};

class PriorityQueue {
private:
    vector<Event> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(const Event& event) {
        heap.push_back(event);
        heapifyUp(heap.size() - 1);
    }

    Event extractMin() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        Event minEvent = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minEvent;
    }

    Event peekMin() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

class EventList {
private:
    EventNode* head;
    PriorityQueue eventQueue;

public:
    EventList() : head(nullptr) {}

    void addEvent(const Event& event) {
        EventNode* newNode = new EventNode{event, nullptr};
        if (!head) {
            head = newNode;
        } else {
            EventNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        eventQueue.insert(event);
    }

    EventNode* getHead() const {
        return head;
    }

    void viewAllEvents() {
        EventNode* temp = head;
        cout << "Events:\n";
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Name\t\t\tDate\t\t\tTime\t\t\tVenue\t\t\tClub\n";
        while (temp) {
            cout << temp->data.name << "\t\t" << temp->data.date << "\t\t" << temp->data.time << "\t\t\t" << temp->data.venue << "\t\t" << temp->data.club << endl;
            temp = temp->next;
        }
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n\n";
    }

    void viewNextEvent() {
        if (!eventQueue.isEmpty()) {
            Event nextEvent = eventQueue.peekMin();
            cout << "Next upcoming event:\n";
            cout << "Name: " << nextEvent.name << "\nDate: " << nextEvent.date << "\nTime: " << nextEvent.time << "\nVenue: " << nextEvent.venue << "\nClub: " << nextEvent.club << endl;
        } else {
            cout << "No upcoming events.\n";
        }
    }
};

VisitorList visitors;
EventList events;

void loadDataFromFile() {
    ifstream infile("data.txt");
    if (infile.is_open()) {
        int visitorCount;
        infile >> visitorCount;
        infile.ignore();
        for (int i = 0; i < visitorCount; ++i) {
            Visitor visitor;
            getline(infile, visitor.name);
            getline(infile, visitor.phone);
            getline(infile, visitor.address);
            getline(infile, visitor.feedback);
            visitors.addVisitor(visitor);
        }

        int eventCount;
        infile >> eventCount;
        infile.ignore();
        for (int i = 0; i < eventCount; ++i) {
            Event event;
            getline(infile, event.name);
            getline(infile, event.date);
            getline(infile, event.time);
            getline(infile, event.venue);
            getline(infile, event.club);
            events.addEvent(event);
        }

        infile.close();
    } else {
        cerr << "Unable to open file: data.txt" << endl;
    }
}

void saveDataToFile() {
    ofstream outfile("data.txt");
    if (outfile.is_open()) {
        VisitorNode* tempVisitor = visitors.getHead();
        int visitorCount = 0;
        while (tempVisitor) {
            ++visitorCount;
            tempVisitor = tempVisitor->next;
        }
        outfile << visitorCount << endl;

        tempVisitor = visitors.getHead();
        while (tempVisitor) {
            outfile << tempVisitor->data.name << endl;
            outfile << tempVisitor->data.phone << endl;
            outfile << tempVisitor->data.address << endl;
            outfile << tempVisitor->data.feedback << endl;
            tempVisitor = tempVisitor->next;
        }

        EventNode* tempEvent = events.getHead();
        int eventCount = 0;
        while (tempEvent) {
            ++eventCount;
            tempEvent = tempEvent->next;
        }
        outfile << eventCount << endl;

        tempEvent = events.getHead();
        while (tempEvent) {
            outfile << tempEvent->data.name << endl;
            outfile << tempEvent->data.date << endl;
            outfile << tempEvent->data.time << endl;
            outfile << tempEvent->data.venue << endl;
            outfile << tempEvent->data.club << endl;
            tempEvent = tempEvent->next;
        }

        outfile.close();
    } else {
        cerr << "Unable to open file for writing: data.txt" << endl;
    }
}

void addNewVisitor() {
    char choice;
    do {
        cout << "--------------------------------------\n";
        Visitor visitor;
        cout << "Enter visitor name: ";
        cin.ignore();
        getline(cin, visitor.name);
        cout << "Enter visitor phone number: ";
        getline(cin, visitor.phone);
        cout << "Enter visitor address: ";
        getline(cin, visitor.address);
        cout << "Enter feedback: ";
        getline(cin, visitor.feedback);
        visitors.addVisitor(visitor);
        cout << "Visitor added successfully!\n";
        cout << "--------------------------------------\n\n";

        cout << "Enter 'q' to add one more visitor or any other key to return to the main menu: ";
        cin >> choice;
        cout << endl;
    } while (choice == 'q' || choice == 'Q');
}

void addFeedback(const string& name) {
    cout << "Enter visitor phone number: ";
    string phone;
    cin.ignore();
    getline(cin, phone);
    visitors.editVisitor(phone);
}

void addEvent() {
    char choice;
    do {
        cout << "--------------------------------------\n";
        Event event;
        cout << "Enter event name: ";
        cin.ignore();
        getline(cin, event.name);
        cout << "Enter event date (e.g., 24-02-2024): ";
        getline(cin, event.date);
        cout << "Enter event time: ";
        getline(cin, event.time);
        cout << "Enter event venue: ";
        getline(cin, event.venue);
        cout << "Enter hosting club: ";
        getline(cin, event.club);
        events.addEvent(event);
        cout << "Event details added successfully!\n";
        cout << "--------------------------------------\n\n";

        cout << "Enter 'q' to add one more event or any other key to return to the main menu: ";
        cin >> choice;
        cout << endl;
    } while (choice == 'q' || choice == 'Q');
}

void adminLogin() {
    cout << "--------------------------------------\n";
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    cout << endl;

    if (password == "admin") {
        cout << "Admin access granted!\n\n";

        int adminChoice;
        do {
            cout << "1. View All Visitors\n";
            cout << "2. View All Events\n";
            cout << "3. Search Visitor\n";
            cout << "4. Edit Visitor\n";
            cout << "5. Delete Visitor\n";
            cout << "6. Add Event\n";
            cout << "7. View Next Upcoming Event\n";
            cout << "8. Exit Admin Menu\n";
            cout << "Enter your choice: ";
            cin >> adminChoice;
            cout << endl;

            switch (adminChoice) {
                case 1:
                    visitors.viewAllVisitors();
                    break;
                case 2:
                    events.viewAllEvents();
                    break;
                case 3: {
                    string searchTerm;
                    cout << "Enter name or phone number to search: ";
                    cin.ignore();
                    getline(cin, searchTerm);
                    visitors.searchVisitor(searchTerm);
                    break;
                }
                case 4: {
                    string phone;
                    cout << "Enter phone number of the visitor to edit: ";
                    cin.ignore();
                    getline(cin, phone);
                    visitors.editVisitor(phone);
                    break;
                }
                case 5: {
                    string phone;
                    cout << "Enter phone number of the visitor to delete: ";
                    cin.ignore();
                    getline(cin, phone);
                    visitors.deleteVisitor(phone);
                    break;
                }
                case 6:
                    addEvent();
                    break;
                case 7:
                    events.viewNextEvent();
                    break;
                case 8:
                    cout << "Exiting Admin Menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (adminChoice != 8);

    } else {
        cout << "Invalid password\n\n";
    }
}

int main() {
    loadDataFromFile();

    int choice;
    do {
        cout << "\n++++++++++    Welcome to Incand 2024 System Management System   +++++++++\n";
        cout << "\n1. Add New Visitor\n";
        cout << "2. Add Feedback\n";
        cout << "3. Know About Incand\n";
        cout << "4. Admin Login\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addNewVisitor();
                break;
            case 2: {
                string name;
                cout << "Enter your name: ";
                cin >> name;
                addFeedback(name);
                break;
            }
            case 3:
                cout << "Incand is the annual cultural fest of NIT. It features various events such as music, dance, drama, and literary activities. It is a platform for students to showcase their talents and enjoy a break from their academic routines.\n";
                break;
            case 4:
                adminLogin();
                break;
            case 5:
                saveDataToFile();
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
