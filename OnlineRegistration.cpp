#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Student structure
struct Student {
    int id;
    string name;
    double previousGrade;
    bool isEligible;
    bool hasPaid;
    string transactionID;
    vector<string> registeredCourses;
};

// Function prototypes
void checkEligibility(Student &student);
void makePayment(Student &student);
void registerCourses(Student &student, unordered_map<string, int> &courseCatalog);
void confirmRegistration(Student &student);
void showMenu(Student &student, unordered_map<string, int> &courseCatalog);

int main() {
    // Sample course catalog
    unordered_map<string, int> courseCatalog = {
        {"Data Structures", 101},
        {"Algorithms", 102},
        {"Operating Systems", 103},
        {"Database Systems", 104}
    };

    // Sample student data
    Student student = {1, "Eyob Girma", 3.5, false, false, "", {}};

    showMenu(student, courseCatalog);

    return 0;
}

void showMenu(Student &student, unordered_map<string, int> &courseCatalog) {
    int choice;

    do {
        cout << "\n*** University Registration System ***\n";
        cout << "1. Check Eligibility\n";
        cout << "2. Make Payment\n";
        cout << "3. Register for Courses\n";
        cout << "4. Confirm Registration\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkEligibility(student);
                break;
            case 2:
                makePayment(student);
                break;
            case 3:
                registerCourses(student, courseCatalog);
                break;
            case 4:
                confirmRegistration(student);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void checkEligibility(Student &student) {
    if (student.previousGrade >= 2.0) {
        student.isEligible = true;
        cout << "Student is eligible to register for the next semester.\n";
    } else {
        student.isEligible = false;
        cout << "Student is not eligible to register for the next semester.\n";
    }
}

void makePayment(Student &student) {
    if (student.isEligible) {
        cout << "Please enter your payment transaction ID: ";
        cin >> student.transactionID;

        if (!student.transactionID.empty()) {
            cout << "Payment successful. Transaction ID: " << student.transactionID << ". Please proceed to the finance office.\n";
            student.hasPaid = true;
        } else {
            cout << "Invalid Transaction ID. Payment failed.\n";
        }
    } else {
        cout << "Student is not eligible. Cannot proceed with payment.\n";
    }
}

void registerCourses(Student &student, unordered_map<string, int> &courseCatalog) {
    if (!student.hasPaid) {
        cout << "Please complete the payment before registering for courses.\n";
        return;
    }

    int numCourses;
    cout << "Enter the number of courses you want to register for: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        string input;
        cout << "Enter course name or course number: ";
        cin >> ws;
        getline(cin, input);

        bool courseFound = false;

        // Check if input is a course name
        if (courseCatalog.find(input) != courseCatalog.end()) {
            student.registeredCourses.push_back(input);
            courseFound = true;
        } else {
            // Check if input is a course number
            int courseNumber = stoi(input);
            for (const auto &course : courseCatalog) {
                if (course.second == courseNumber) {
                    student.registeredCourses.push_back(course.first);
                    courseFound = true;
                    break;
                }
            }
        }

        if (courseFound) {
            cout << "Course registered successfully.\n";
        } else {
            cout << "Course not found in catalog.\n";
        }
    }
}

void confirmRegistration(Student &student) {
    if (student.registeredCourses.empty()) {
        cout << "No courses registered. Please register for courses first.\n";
    } else {
        cout << "Registration confirmed. You are registered for the following courses:\n";
        for (const string &course : student.registeredCourses) {
            cout << "- " << course << endl;
        }
        cout << "Your student ID card has been updated.\n";
    }
}
