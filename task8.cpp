#include <iostream>
#include <string>
using namespace std;

int findPattern(const string& text, const string& pattern) {
    if (pattern.empty()) return 0;

    if (pattern.length() > text.length()) return -1;

    // Naive pattern matching algorithm
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        int j = 0;
        // Check if pattern matches at position i
        while (j < pattern.length() && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == pattern.length()) {
            return i;
        }
    }

    return -1; // Pattern not found
}

int main() {
    // Test cases
    string text1 = "hello world";
    string text2 = "programming";
    string text3 = "test";

    // Pattern at the beginning
    cout << "Pattern at beginning: " << findPattern(text1, "hello") << endl;

    // Pattern at the end
    cout << "Pattern at end: " << findPattern(text1, "world") << endl;

    // Pattern not present
    cout << "Pattern not present: " << findPattern(text2, "xyz") << endl;

    // Empty pattern
    cout << "Empty pattern: " << findPattern(text3, "") << endl;

    // Additional test - pattern in middle
    cout << "Pattern in middle: " << findPattern(text1, "lo w") << endl;

    return 0;
}