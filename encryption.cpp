#include <iostream>
#include <string>

using namespace std;

// Define the encryption and decryption functions
string encrypt(string message, int key) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = ((c - 65) + key) % 26 + 65;
        }
        result += c;
    }
    return result;
}

string decrypt(string message, int key) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = ((c - 65) - key + 26) % 26 + 65;
        }
        result += c;
    }
    return result;
}

int main() {
    // Get the message and key from the user
    string message;
    int key;
    cout << "Enter a message: ";
    getline(cin, message);
    cout << "Enter a key (1-25): ";
    cin >> key;

    // Encrypt the message and print the result
    string encrypted = encrypt(message, key);
    cout << "Encrypted message: " << encrypted << endl;

    // Decrypt the message and print the result
    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}

