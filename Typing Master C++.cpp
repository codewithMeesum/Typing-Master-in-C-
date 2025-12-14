#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(string u = "", string p = "") {
        username = u;
        password = p;
    }

    string getUsername() {  // allow to read the private values safely.
	 return username; 
	 }
    string getPassword() { 
	return password;
	 }

    void setUsername(string u) {   // allow to change the private values safely.
	 username = u;
	  }
    void setPassword(string p) { 
	password = p; 
	}

    void saveUser() {    // Save user in clean table
        fstream check("users.txt", ios::in);
        bool fileExists = check.good();
        check.close();

        ofstream fout("users.txt", ios::app);
        if (!fileExists) {
            fout << "====================================\n";
            fout << "         Registered Users\n";
            fout << "====================================\n";
            fout << left << setw(15) << "Username" << setw(15) << "Password" << endl;
            fout << "------------------------------------\n";
        }

        fout << left << setw(15) << username << setw(15) << password << endl;
        fout.close();
    }

    
    static bool userExists(string u) {  // Check if user exists 
        ifstream fin("users.txt");
        if (!fin) return false;
        string usr, pass, line;

        // Skip header lines
        for (int i = 0; i < 5 && getline(fin, line); i++);

        while (fin >> usr >> pass) {
            if (usr == u) {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }


    static bool login(string u, string p) { // Verify login
        ifstream fin("users.txt");
        if (!fin) return false;
        string usr, pass, line;

        
        for (int i = 0; i < 5 && getline(fin, line); i++); //Skip header lines

        while (fin >> usr >> pass) {
            if (usr == u && pass == p) {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }
};

class Test {  //   ABSTRACT CLASS: TEST
protected:
    string text;
    float timeTaken;
    float speed;
    float accuracy;

public:
    virtual void startTest(string username) = 0; // pure virtual function 

    float calculateSpeed(int words, float seconds) {
        return (words / (seconds / 60)); // WPM formula
    }

    float calculateAccuracy(string input) {
        int correct = 0;
        for (size_t i = 0; i < input.size() && i < text.size(); i++)
            if (input[i] == text[i]) correct++;
        return ((float)correct / text.size()) * 100; //accuracy formula in % 
    }

    void saveResult(string username) {
    fstream check("leaderboard.txt", ios::in);
    bool fileExists = check.good();
    check.close();

    ofstream out("leaderboard.txt", ios::app);
    if (!fileExists) {
        out << "===========================================================\n";
        out << "                 Typing Master Leaderboard\n";
        out << "===========================================================\n";
        out << left << setw(15) << "Username"
            << setw(15) << "Speed(WPM)"
            << setw(15) << "Accuracy(%)"
            << setw(15) << "Time(sec)" << endl;
        out << "-----------------------------------------------------------\n";
    }

    out << left << setw(15) << username
        << setw(15) << fixed << setprecision(2) << speed
        << setw(15) << fixed << setprecision(2) << accuracy
        << setw(15) << fixed << setprecision(2) << timeTaken << endl;

    out.close();
}

};

class EasyTest : public Test { // CLASS: EASY TEST
public:
    EasyTest() {
        text = "The quick brown fox jumps over the lazy dog";
    }
    void startTest(string username) override {
        cout << "\nTyping Test (EASY):\n" << text << "\n\nStart typing:\n";
        cin.ignore();
        string input;
        clock_t start = clock();
        getline(cin, input);
        clock_t end = clock();

        timeTaken = float(end - start) / CLOCKS_PER_SEC;
        int words = input.size() / 5;
        speed = calculateSpeed(words, timeTaken);
        accuracy = calculateAccuracy(input);

        cout << "\n===== Result =====\n";
        cout << "Time: " << timeTaken << " sec\n";
        cout << "Speed: " << speed << " WPM\n";
        cout << "Accuracy: " << accuracy << "%\n";

        saveResult(username);
    }
};

class HardTest : public Test {  // CLASS: HARD TEST 
public:
    HardTest() {
        text = "Object oriented programming in C++ allows classes, inheritance and polymorphism to create reusable code.";
    }
    void startTest(string username) override {
        cout << "\nTyping Test (HARD):\n" << text << "\n\nStart typing:\n";
        cin.ignore();
        string input;
        clock_t start = clock();
        getline(cin, input);
        clock_t end = clock();

        timeTaken = float(end - start) / CLOCKS_PER_SEC; // time calculation 
        
        int words = input.size() / 5;
        speed = calculateSpeed(words, timeTaken);
        accuracy = calculateAccuracy(input);

        cout << "\n===== Result =====\n";
        cout << "Time: " << timeTaken << " sec\n";
        cout << "Speed: " << speed << " WPM\n";
        cout << "Accuracy: " << accuracy << "%\n";

        saveResult(username);
    }
};

void viewLeaderboard() {  // VIEW LEADERBOARD 
    ifstream fin("leaderboard.txt");
    if (!fin) {
        cout << "\nNo leaderboard data found yet.\n";
        return;
    }
    cout << "\n========== Leaderboard ==========\n";
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}

void viewUsers() {  // VIEW USERS
    ifstream fin("users.txt");
    if (!fin) {
        cout << "\nNo users registered yet.\n";
        return;
    }
    cout << "\n========== Registered Users ==========\n";
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}

void signup() { // SIGNUP FUNCTION 
    string u, p;
    cout << "\nEnter new username: ";
    cin >> u;
    if (User::userExists(u)) {
        cout << "Username already exists! Try another.\n";
        return;
    }
    cout << "Enter password: ";
    cin >> p;

    User newUser(u, p);
    newUser.saveUser();
    cout << "User registered successfully!\n";
}

bool login(string &loggedUser) {  // LOGIN FUNCTION
    string u, p;
    cout << "\nEnter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;

    if (User::login(u, p)) {
        loggedUser = u;
        cout << "\nLogin successful! Welcome, " << u << "!\n";
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

int main() {
    string loggedUser;
    int choice;

    while (true) {
        cout << "\n========================================\n";
cout << "           Typing Master\n";
cout << "    Developed by Mesum & Mehnaz Ameen \n"; 
cout << "========================================\n";

        cout << "1. Signup\n2. Login\n3. View Leaderboard\n4. View Registered Users\n5. Exit\nChoice: ";
        cin >> choice;
 
        switch (choice) {  // switch statement 
        case 1:
            signup();
            break;
        case 2:
            if (login(loggedUser)) {
                int opt;
                do {   // do while loop 
                    cout << "\nLogged in as " << loggedUser << "\n";
                    cout << "1. Easy Test\n2. Hard Test\n3. View Leaderboard\n4. Logout\nChoice: ";
                    cin >> opt;

                    if (opt == 1) {
                        EasyTest e;
                        e.startTest(loggedUser);
                    } else if (opt == 2) {
                        HardTest h;
                        h.startTest(loggedUser);
                    } else if (opt == 3) {
                        viewLeaderboard();
                    } else if (opt == 4) {
                        cout << "Logged out.\n";
                        loggedUser = "";
                        break;
                    } else {
                        cout << "Invalid choice!\n";
                    }
                } while (opt != 4);
            }
            break;
        case 3:
            viewLeaderboard();
            break;
        case 4:
            viewUsers();
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

