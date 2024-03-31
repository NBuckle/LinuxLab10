#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string caesarCipher(string message, int shift) {
    string encodedMessage = "";
    for (char& ch : message) {
        if (isalpha(ch)) {  // Check if character is an alphabet letter
            char base = isupper(ch) ? 'A' : 'a';  // Set base according to uppercase or lowercase
            char encodedChar = ((ch - base + shift) % 26) + base;  // Apply Caesar cipher shift
            encodedMessage += encodedChar;
        }
    }
    return encodedMessage;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <shift_amount>" << endl;
        return 1;
    }

    int shift = atoi(argv[1]);  // Convert command-line argument to integer

    string message;
    cout << "Enter message: ";
    getline(cin, message);

    // Convert message to uppercase
    for (char& ch : message) {
        ch = toupper(ch);
    }

    string encodedMessage = caesarCipher(message, shift);

    // Print encoded message in blocks of five letters
    int blockCount = 0;
    for (char ch : encodedMessage) {
        cout << ch;
        if (++blockCount % 5 == 0) {
            cout << ' ';
        }
        if (blockCount % 50 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}

