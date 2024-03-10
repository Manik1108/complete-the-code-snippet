#include<iostream>
#include<cstring>
using namespace std;

class sample {
public:
    char *name;

    // Default constructor
    sample() {
nullptr;
    }

    // Parameterized constructor with deep copy
    sample(const char *str) {
        int length = strlen(str);
        name = new char[length + 1];
        strcpy(name, str);
    }

    // Copy constructor with deep copy
    sample(const sample& other) {
        if (other.name != nullptr) {
            int length = strlen(other.name);
            name = new char[length + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }

    // Destructor to release memory
    ~sample() {
        delete[] name;
    }
};

int main(int argc, char *argv[]) {
    sample user1("chitkara");
    sample user2 = user1; // This invokes the copy constructor, performing a deep copy

    // Modify user2's name without affecting user1
    delete[] user2.name; // Free the previously allocated memory
    user2.name = new char[strlen("dummy") + 1]; // Allocate new memory for user2's name
    strcpy(user2.name, "dummy");

    // Print user1's and user2's names
    cout << "User1's name: " << user1.name << endl;
    cout << "User2's name: " << user2.name << endl;

    return 0;
}
