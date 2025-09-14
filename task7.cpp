#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }

    return indices;
}

vector<int> findAllIndicesSTL(const vector<int>& arr, int key) {
    vector<int> indices;

    // Find first occurrence
    auto it = arr.begin();
    while ((it = find(it, arr.end(), key)) != arr.end()) {
        // Calculate index and add to result
        indices.push_back(distance(arr.begin(), it));
        // Move iterator to next position
        ++it;
    }

    return indices;
}

template<typename T>
vector<int> findAllIndicesGeneric(const vector<T>& arr, const T& key) {
    vector<int> indices;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }

    return indices;
}


void printVector(const vector<int>& vec, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
void runTests() {
    cout << "=== Find All Indices - Test Cases ===" << endl;
    cout << endl;

    // Case 1: Multiple occurrences
    cout << "Test 1 - Multiple occurrences:" << endl;
    vector<int> arr1 = {1, 3, 5, 3, 7, 3, 9};
    int key1 = 3;
    vector<int> result1 = findAllIndices(arr1, key1);
    printArray(arr1, "Array");
    cout << "Key: " << key1 << endl;
    printVector(result1, "Indices");
    cout << "Expected: [1, 3, 5]" << endl;
    cout << endl;

    // Test Case 2: Key not present
    cout << "Test 2 - Key not present:" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int key2 = 10;
    vector<int> result2 = findAllIndices(arr2, key2);
    printArray(arr2, "Array");
    cout << "Key: " << key2 << endl;
    printVector(result2, "Indices");
    cout << "Expected: [] (empty)" << endl;
    cout << endl;

    // Test Case 3: Empty array
    cout << "Test 3 - Empty array:" << endl;
    vector<int> arr3 = {};
    int key3 = 5;
    vector<int> result3 = findAllIndices(arr3, key3);
    printArray(arr3, "Array");
    cout << "Key: " << key3 << endl;
    printVector(result3, "Indices");
    cout << "Expected: [] (empty)" << endl;
    cout << endl;

    void interactiveTest(){
        cout << "=== Interactive Testing ===" << endl;
        int n, key;

        cout << "Enter the size of the array: ";
        cin >> n;

        if (n <= 0) {
            cout << "Array size must be positive!" << endl;
            return;
        }

        vector<int> arr(n);
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Enter the key to search for: ";
        cin >> key;

        vector<int> result = findAllIndices(arr, key);

        cout << "\nResult:" << endl;
        printArray(arr, "Array");
        cout << "Key: " << key << endl;
        printVector(result, "Found at indices");

        if (result.empty()) {
            cout << "Key not found in the array!" << endl;
        } else {
            cout << "Total occurrences: " << result.size() << endl;
        }
    }

    /**
     * Performance comparison function
     */
    void performanceTest() {
        cout << "=== Performance Test ===" << endl;

        // Create a large array
        vector<int> largeArr;
        const int size = 1000000;
        const int searchKey = 42;

        // Fill array with random values, inserting search key at regular intervals
        for (int i = 0; i < size; i++) {
            if (i % 1000 == 0) {
                largeArr.push_back(searchKey);
            } else {
                largeArr.push_back(rand() % 1000);
            }
        }

        cout << "Testing with array size: " << size << endl;
        cout << "Search key: " << searchKey << endl;

        // Test basic implementation
        vector<int> result = findAllIndices(largeArr, searchKey);
        cout << "Found " << result.size() << " occurrences" << endl;

        // Show first few indices
        cout << "First few indices: ";
        for (int i = 0; i < min(10, (int)result.size()); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    int main() {
        cout << "Find All Indices of an Element in Array" << endl;
        cout << "=======================================" << endl;
        cout << endl;

        // Run tests
        runTests();

        // Menu
        cout << "\nChoose an option:" << endl;
        cout << "1. Interactive test with your input" << endl;
        cout << "2. Performance test with large array" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice (1-3): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                interactiveTest();
            break;
            case 2:
                performanceTest();
            break;
            case 3:
                cout << "Goodbye!" << endl;
            break;
            default:
                cout << "Invalid choice!" << endl;
        }

        return 0;
    }
}