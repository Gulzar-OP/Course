#include<iostream>
#include<map>
using namespace std;
int main() {
    // Create a map to store key-value pairs
    map<string, int> ageMap;

    // Inserting values into the map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // Accessing and printing values from the map
    cout << "Alice's age: " << ageMap["Alice"] << endl;
    cout << "Bob's age: " << ageMap["Bob"] << endl;
    cout << "Charlie's age: " << ageMap["Charlie"] << endl;

    ageMap["Bob"] = 26; // Updating Bob's age
    cout << "Bob's updated age: " << ageMap["Bob"] << endl;
    
    // Iterating through the map and printing all key-value pairs
    cout << "All entries in the map:" << endl;
    for (const auto& entry : ageMap) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}