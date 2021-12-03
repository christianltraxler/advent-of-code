#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Initialize couter for increases, start at -1 to account to initial increase from first number
    int numIncreases = -1;
    // Initialize string for the file to parse the txt
    string fileName = "./day1.txt";
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
        // Intialize the variable storing the previous number
        int previousNum = -9999;

        // Iterate through every line of the file
        while (getline(inFile, line)) {
            // If the previous number is less than the current number, an increase occured
            if (previousNum < stoi(line)) {
                // Increment the counter
                numIncreases++;
            }

            // Set the previousNum for the next iteration
            previousNum = stoi(line);
        }
    }

    // Output the total number of increases 
    cout << "Number of Increases: " << numIncreases << endl;
    
    return 0;
}