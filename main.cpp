#include <iostream> // Include input/output stream library
#include <cstdlib> // Include C standard general utilities library
#include <vector> // Include vector container library
#include <ctime> // Include C time library for time-related functions
using namespace std; // Using standard namespace

// Define a structure for a block in the blockchain
struct Block {
    int id; // Block ID
    string current_hash, previous_hash, timestamp, info; // Hashes, timestamp, and information stored in the block
};

// Function to generate a random hash
string generateRandomHash() {
    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Define possible characters for the hash
    string randHash = ""; // Initialize an empty string for the hash
    for (int i = 0; i < 20; i++) { // Loop to generate a 20-character hash
        int index = rand() % 62; // Generate a random index within the range of characters
        randHash += chars[index]; // Append a randomly selected character to the hash string
    }
    return randHash; // Return the generated hash
}

// Function to print a block's information
void printBlock(Block block) {
    cout << "Block " << block.id << " | " << block.current_hash << " | "; // Print block ID and current hash
    cout << block.previous_hash << " | " << block.timestamp << " | " << block.info << endl << endl; // Print previous hash, timestamp, and information
}

// Function to collect data for a new block
string collectData() {
    cout << "1. Please enter ID, name, type & location of your product\n2. Once done, enter 'q' then press 'Enter' key to exit data entry\n\nexp:\tID:101\n\tname:milk\n\ttype:chocolate\n\tlocation:MY\n\tq " << endl << endl; // Display instructions for data entry
    string dt = "", a; // Initialize variables for data and user input
    while (true) { // Infinite loop to collect data until 'q' is entered
        cin >> a; // Read user input
        if (a == "q") { // If 'q' is entered, break out of the loop
            break;
        }

        if (dt.length() > 0) { // If data already exists, append a separator
            dt += " | ";
        }
        dt += a; // Append the entered data to the string
    }
    return dt; // Return the collected data
}

// Function to get the current timestamp
string getTimestamp() {
    time_t rawtime; // Define a variable to hold raw time data
    time(&rawtime); // Get the current time
    struct tm *timeinfo; // Structure for time information
    char buffer[20]; // Buffer to store formatted time string
    timeinfo = localtime(&rawtime); // Get local time
    strftime(buffer, sizeof(buffer), "%d%m%Y: %H:%M", timeinfo); // Format the time string
    return string(buffer); // Return the formatted time string
}

int main(void) {
    int lastId = 0; // Initialize the last block ID
    string lastHash = ""; // Initialize the last block's hash
    vector<Block> blocks; // Initialize a vector to store blocks
    cout << "Hi, Welcome to May May's Blockchain program!" << endl; // Display welcome message
    while (true) { // Infinite loop to interact with the user
        cout << "Please enter a command : \n"; // Prompt the user for input
        cout << "enter 'n' to store new block\n enter 'p' to print block list\n enter 'q' to quit: " << endl; // Display options
        char command; // Variable to store user command
        cin >> command; // Read user input
        if (command == 'n') { // If the user wants to store a new block
            string data = collectData(); // Collect data for the new block
            string blockHash = generateRandomHash(); // Generate a hash for the new block
            string parentBlockHash = blockHash; // Set the parent block hash initially to the current block's hash
            int id = 0; // Initialize block ID
            string timestamp = getTimestamp(); // Get the current timestamp
            if (lastId != 0) { // If there are existing blocks
                id = lastId; // Set the ID to the last ID
                parentBlockHash = lastHash; // Set the parent block hash to the last block's hash
            }
            Block newBlock = { // Create a new block
                id,
                blockHash,
                parentBlockHash,
                timestamp,
                data}; // Initialize block attributes
            lastHash = blockHash; // Update the last block's hash
            lastId += 1; // Increment the last block ID
            blocks.push_back(newBlock); // Add the new block to the blockchain vector
            system("cls"); // Clear the screen
        } else if (command == 'q') { // If the user wants to quit
            break; // Exit the program
        } else if (command == 'p') { // If the user wants to print the block list
            for (const Block &block : blocks) { // Iterate through the blocks in the blockchain
                printBlock(block); // Print each block's information
            }
        } else { // If the user enters an invalid command
            cout << "Please enter a valid command." << endl; // Notify the user
        }
    }

    return 0; // Return 0 to indicate successful execution
}

/*Hash Function Improvement: You could replace the simple random hash function
with a more secure and efficient hash function like SHA-256, which is commonly used
in block chain technology for its cryptographic properties.

Data Validation: Implement data validation mechanisms to ensure that the data entered by the user
is in the correct format and does not contain any malicious content.

Block chain Integrity: Implement mechanisms to ensure the integrity of the block chain,
such as checking the validity of the hashes and maintaining a consistent data structure.

Optimization: Optimize the code for better performance, especially if dealing with large amounts of data.
This could involve using more efficient data structures or algorithms where applicable.

Security: Consider adding security features such as encryption to protect the data stored in the blocks
and prevent unauthorized access or tampering.

These are just a few suggestions to consider for improving the efficiency and security of the block chain implementation.


*/
