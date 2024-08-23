University Registration System 
This project simulates the paper-based registration system used by the Continuous Education Program (CEP) at Addis Ababa Science and Technology University. The simulation replicates the various steps involved in the registration process, including eligibility checks, payment processing, and course registration, using a C++ application with a menu-driven interface.
Features
•	Eligibility Check: Determines if a student is eligible for registration based on their previous grades.
•	Payment Processing: Validates payment using transaction IDs and marks the student as paid.
•	Course Registration: Allows students to register for courses by entering course names or numbers.
•	Registration Confirmation: Provides a summary of registered courses and confirms the student's registration.
Data Structures and Algorithms
•	Vector (std::vector): Used to store the list of courses a student has registered for.
•	Unordered Map (std::unordered_map): Used to store the course catalog, allowing quick lookups of course names and numbers.
•	Eligibility Check Algorithm: Simple comparison to determine if a student’s grade meets the registration threshold.
•	Payment Validation Algorithm: Ensures that the payment transaction ID is provided before proceeding with registration.
•	Course Registration Algorithm: Handles both name-based and number-based course registration with validation against the course catalog.
System Requirements
•	Development Environment: Code::Blocks IDE or any other C++ compiler.
•	C++ Standard: C++11 or later.
1.	Clone the Repository:
git clone JobGirma/Eyob-Melaku-Birhanu-Tadiyos-https-github.com-Eyob-Melaku-Birhanu-Tadiyos-online-registration-system 
2.	Open the Project:
Open the project in Code::Blocks or your preferred C++ IDE.
3.	Build and Run:
Build the project and run the application to start the simulation.
Usage
1.	Main Menu:
o	Upon running the program, the main menu will appear with options to check eligibility, make a payment, register for courses, and confirm registration.
2.	Navigating the Menu:
o	Use the menu options to simulate the steps in the registration process. Each step is dependent on the previous one (e.g., you must check eligibility before making a payment).
3.	Course Registration:
o	You can register for courses by entering either the course name or number. The system will validate your input against the course catalog.
Analysis and Evaluation
•	Time Complexity: The system efficiently handles registration tasks with constant and linear time complexities for most operations, ensuring quick responses even with a larger course catalog.
•	Space Complexity: The use of vectors and unordered maps ensures that memory usage is minimal and scalable.
Limitations and Future Work
•	The current payment validation is simplified; a more secure method could be implemented in future versions.
•	Searching by course number involves iterating through the catalog, which could be optimized.

