#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Visitor
{
    string name;
    string phone;
    string address;
};

struct Event
{
    string name;
    string venue;
    string time;
};

struct Feedback
{
    string visitorPhone;
    string eventName;
    string feedback;
};

vector<Visitor> visitors;
vector<Event> events;
vector<Feedback> feedbacks;

void addNewVisitor() {
    cout << "--------------------------------------\n";
    Visitor visitor;
    cout << "Enter visitor name: ";
    cin.ignore();
    getline(cin, visitor.name);
    cout << "Enter visitor phone number: ";
    cin >> visitor.phone;
    cout << "Enter visitor address: ";
    cin.ignore();
    getline(cin, visitor.address);
    visitors.push_back(visitor);
    cout << "Visitor added successfully!\n";
    cout << "--------------------------------------\n\n";

    char choice;
    cout << "Enter 'q' to return to the main menu: ";
    cin >> choice;
    if (choice == 'q' || choice == 'Q') {
        cout << "Returning to the main menu...\n";
    } else {
        cout << "Invalid choice! Returning to the main menu...\n";
    }
}


void addFeedback(const string &phone)
{
    cout << "--------------------------------------\n";
    Feedback feedback;
    feedback.visitorPhone = phone;
    cout << "Enter event name for which you want to provide feedback: ";
    cin.ignore();
    getline(cin, feedback.eventName);
    cout << "Enter your feedback: ";
    getline(cin, feedback.feedback);
    feedbacks.push_back(feedback);
    cout << "Feedback added successfully!\n";
    cout << "--------------------------------------\n\n";
}

void addEvent()
{
    cout << "--------------------------------------\n";
    Event event;
    cout << "Enter event name: ";
    cin.ignore();
    getline(cin, event.name);
    cout << "Enter event venue: ";
    getline(cin, event.venue);
    cout << "Enter event time: ";
    getline(cin, event.time);
    events.push_back(event);
    cout << "Event details added successfully!\n";
    cout << "--------------------------------------\n\n";
}

void adminLogin() {
    cout << "--------------------------------------\n";
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    cout << endl;

    if (password == "admin") {
        cout << "Admin access granted!\n\n";

        // Print Visitors in tabular form
        cout << "Visitors:\n";
        cout << "--------------------------------------\n";
        cout << "Name\t\tPhone\t\tAddress\n";
        for (const auto& visitor : visitors) {
            cout << visitor.name << "\t\t" << visitor.phone << "\t\t" << visitor.address << endl;
        }
        cout << "--------------------------------------\n\n";

        // Print Events in tabular form
        cout << "Events:\n";
        cout << "--------------------------------------\n";
        cout << "Name\t\tVenue\t\tTime\n";
        for (const auto& event : events) {
            cout << event.name << "\t\t" << event.venue << "\t\t" << event.time << endl;
        }
        cout << "--------------------------------------\n\n";

    } else {
        cout << "Invalid password\n\n";
    }

    cout << "Enter 'q' to return to the main menu: ";
    char choice;
    cin >> choice;
    if (choice == 'q' || choice == 'Q') {
        cout << "Returning to the main menu...\n";
    } else {
        cout << "Invalid choice! Returning to the main menu...\n";
    }

    cout << "--------------------------------------\n\n";
}

void saveDataToFile()
{
    ofstream outFile("data.txt");
    if (outFile.is_open())
    {
        outFile << "Visitors:\n";
        for (const auto &visitor : visitors)
        {
            outFile << visitor.name << "," << visitor.phone << "," << visitor.address << endl;
        }
        outFile << "\nEvents:\n";
        for (const auto &event : events)
        {
            outFile << event.name << "," << event.venue << "," << event.time << endl;
        }
        outFile << "\nFeedbacks:\n";
        for (const auto &feedback : feedbacks)
        {
            outFile << feedback.visitorPhone << "," << feedback.eventName << "," << feedback.feedback << endl;
        }
        cout << "Data saved successfully to file!\n\n";
    }
    else
    {
        cout << "Unable to open file for saving data!\n\n";
    }
    outFile.close();
}

void loadDataFromFile()
{
    ifstream inFile("data.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            if (line == "Visitors:")
            {
                while (getline(inFile, line) && !line.empty())
                {
                    Visitor visitor;
                    size_t pos = line.find(",");
                    visitor.name = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    visitor.phone = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    visitor.address = line;
                    visitors.push_back(visitor);
                }
            }
            else if (line == "Events:")
            {
                while (getline(inFile, line) && !line.empty())
                {
                    Event event;
                    size_t pos = line.find(",");
                    event.name = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    event.venue = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    event.time = line;
                    events.push_back(event);
                }
            }
            else if (line == "Feedbacks:")
            {
                while (getline(inFile, line) && !line.empty())
                {
                    Feedback feedback;
                    size_t pos = line.find(",");
                    feedback.visitorPhone = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    feedback.eventName = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    feedback.feedback = line;
                    feedbacks.push_back(feedback);
                }
            }
        }
        cout << "Data loaded successfully from file!\n\n";
    }
    else
    {
        cout << "Unable to open file for loading data!\n\n";
    }
    inFile.close();
}
int main() {
    loadDataFromFile();

    int choice;
    do {
        cout << "\n++++++++++ Incandescence 2024 Management System ++++++++++\n";
        cout << "\n++++++++++ Incandescence 2024 Management System ++++++++++\n";
        cout << "1. Add New Visitor\n";
        cout << "2. Add Feedback\n";
        cout << "3. Add Event Details\n";
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
                string phone;
                cout << "Enter your phone number: ";
                cin >> phone;
                addFeedback(phone);
                break;
            }
            case 3:
                addEvent();
                break;
            case 4:
                adminLogin();
                break;
            case 5:
                saveDataToFile();
                cout << "Thank you for using the system. Exiting...\n\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n\n";
        }
    } while (choice != 5);

    return 0;
}

