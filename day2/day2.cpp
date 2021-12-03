#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Initialize couter for increases, start at -1 to account to initial increase from first number
    int numIncreases = 0;
    // Initialize string for the file to parse the txt
    string fileName = "./day2.txt";
    // Initialize the ifstream
    ifstream inFile;

    // Open the file
    inFile.open(fileName);

    if (!inFile.is_open()) {
        // If the file cannot be opened, print error message and exit
        cout << "Unable to open " << fileName << endl;
        exit(1);
    } else {
        // If the file can be opened

        // Initialize the string storing the current line of the txt file
        string line;
        // Intialize the variable storing the three previous numbers
        int previousNums[3] {0, 0, 0};
        // Initialize the variable storing the previous sum
        int previousSum = 0;
        // Intialize a variable that manages the previousNums
        int n = 0;

        // Iterate through every line of the file
        while (getline(inFile, line)) {
            
            if (previousNums[0] != 0 && previousNums[1] != 0 && previousNums[2] != 0) {
                // If the previous sum is less than the current sum, an increase occured
                if (previousSum < previousSum + stoi(line) - previousNums[n]) {
                    // Increment the counter
                    numIncreases++;
                }
            }

            // Set variables for next iteration
            previousSum += stoi(line) - previousNums[n]; // Update previousSum
            previousNums[n] = stoi(line); // Update last previousNums inserted with newest number
            if (n < 2) { // Update previousNums manager
                n++;
            } else {
                n = 0;
            }
        }
    }

    // Output the total number of increases 
    cout << "Number of Increases: " << numIncreases << endl;
    
    return 0;
}