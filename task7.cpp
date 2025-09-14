#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Find all indices of a given element in an array
 *
 * @param arr: Vector containing the elements
 * @param key: Element to search for
 * @return: Vector containing all indices where the key is found
 */
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;

    // Iterate through the array and collect matching indices
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }

    return indices;
}

/**
 * Alternative implementation using STL algorithms
 */
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

/**
 * Generic template version that works with any data type
 */
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

/**
 * Utility function to print vector contents
 */
void printVector(const vector<int>& vec, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * Utility function to print array contents
 */
void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * Run comprehensive tests
 */
void runTests() {
    cout << "=== Find All Indices - Test Cases ===" << endl;
    cout << endl;

    // Test Case 1: Multiple occurrences
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

    // Additional Test Cases
    cout << "=== Additional Test Cases ===" << endl;
    cout << endl;

    // Test Case 4: Single occurrence
    cout << "Test 4 - Single occurrence:" << endl;
    vector<int> arr4 = {10, 20, 30, 40, 50};
    int key4 = 30;
    vector<int> result4 = findAllIndices(arr4, key4);
    printArray(arr4, "Array");
    cout << "Key: " << key4 << endl;
    printVector(result4, "Indices");
    cout << "Expected: [2]" << endl;
    cout << endl;

    // Test Case 5: All elements are the same
    cout << "Test 5 - All elements are the same:" << endl;
    vector<int> arr5 = {7, 7, 7, 7, 7};
    int key5 = 7;
    vector<int> result5 = findAllIndices(arr5, key5);
    printArray(arr5, "Array");
    cout << "Key: " << key5 << endl;
    printVector(result5, "Indices");
    cout << "Expected: [0, 1, 2, 3, 4]" << endl;
    cout << endl;

    // Test Case 6: Key at first and last positions
    cout << "Test 6 - Key at first and last positions:" << endl;
    vector<int> arr6 = {8, 1, 2, 3, 8};
    int key6 = 8;
    vector<int> result6 = findAllIndices(arr6, key6);
    printArray(arr6, "Array");
    cout << "Key: " << key6 << endl;
    printVector(result6, "Indices");
    cout << "Expected: [0, 4]" << endl;
    cout << endl;

    // Test Case 7: Negative numbers
    cout << "Test 7 - With negative numbers:" << endl;
    vector<int> arr7 = {-1, 5, -1, 0, -1, 3};
    int key7 = -1;
    vector<int> result7 = findAllIndices(arr7, key7);
    printArray(arr7, "Array");
    cout << "Key: " << key7 << endl;
    printVector(result7, "Indices");
    cout << "Expected: [0, 2, 4]" << endl;
    cout << endl;

    // Test Case 8: Large array with multiple occurrences
    cout << "Test 8 - Large array:" << endl;
    vector<int> arr8;
    for (int i = 0; i < 20; i++) {
        arr8.push_back(i % 5);  // Creates pattern: 0,1,2,3,4,0,1,2,3,4,...
    }
    int key8 = 2;
    vector<int> result8 = findAllIndices(arr8, key8);
    printArray(arr8, "Array");
    cout << "Key: " << key8 << endl;
    printVector(result8, "Indices");
    cout << "Expected: [2, 7, 12, 17]" << endl;
    cout << endl;

    // Test STL version
    cout << "=== Testing STL Implementation ===" << endl;
    vector<int> stl_result = findAllIndicesSTL(arr1, key1);
    cout << "STL version result for Test 1: ";
    printVector(stl_result, "Indices");
    cout << endl;

    // Test Generic version with strings
    cout << "=== Testing Generic Version with Strings ===" << endl;
    vector<string> strArr = {"apple", "banana", "apple", "cherry", "apple"};
    string strKey = "apple";
    vector<int> strResult = findAllIndicesGeneric(strArr, strKey);
    cout << "String Array: [";
    for (int i = 0; i < strArr.size(); i++) {
        cout << "\"" << strArr[i] << "\"";
        if (i < strArr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Key: \"" << strKey << "\"" << endl;
    printVector(strResult, "Indices");
    cout << "Expected: [0, 2, 4]" << endl;
}

/**
 * Interactive function for user testing
 */
void interactiveTest() {
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

    // Run predefined tests
    runTests();

    // Menu for user choice
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
