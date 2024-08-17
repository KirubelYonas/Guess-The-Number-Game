//Code by AXER-doc && KirubelYonas
string generateRandomNumber() {
    // Vector containing all digit characters
    vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Create a random number generator
    random_device rd;  // Obtain a random number from hardware
    mt19937 g(rd());  // Seed the generator

    // Shuffle the digits to randomize them
    shuffle(digits.begin(), digits.end(), g);

    // Convert the first 4 characters to a string and return it
    return string(digits.begin(), digits.begin() + 4);
}

// Function to check if a given number string has any duplicate digits
bool hasDuplicateDigits(const string &number) {
    unordered_set<char> seen;  // Set to track seen digits
    for (const auto c : number) {
        // If insertion fails, digit is a duplicate
        if (!seen.insert(c).second) return true;
    }
    return false;
}

// Function to check if a string contains only digit characters
bool isNumeric(const string &s) {
    return all_of(s.begin(), s.end(), [](char c){ return isdigit(c); });
}

// Function to get the user's guess from input stream
string getUserGuess(istream &in = cin, ostream &out = cout) {
    string guess;
    out << "Enter your guess (a 4-digit number with non-repeating digits): ";
    in >> guess;
    return guess;
}

// Function to compare the user's guess to the randomly generated number
pair<int, int> checkGuess(const string &randomNumber, const string &userGuess) {
    int correctNumbers = 0;   // Number of correct digits
    int correctPosition = 0;  // Number of digits in the correct position

    unordered_set<char> randomNumberSet(randomNumber.begin(), randomNumber.end());  // Set of digits in the random number

    // Iterate through each digit in the user's guess
    for (int i = 0; i < 4; ++i) {
        if (randomNumber[i] == userGuess[i]) {
            // Digit is correct and in the correct position
            correctNumbers++;
            correctPosition++;
        } else if (randomNumberSet.count(userGuess[i])) {
            // Digit is correct but in the wrong position
            correctNumbers++;
        }
    }

    return make_pair(correctNumbers, correctPosition);
}

// Function to handle the guessing process with feedback and attempt limits
int acceptGuess(const string &expected, istream &in = cin, ostream &out = cout, int maxAttempts = 10) {
    int attempts = 0;  // Number of attempts made by the user

    // Loop until the user either guesses correctly or exceeds max attempts
    while (attempts < maxAttempts) {
        string userGuess = getUserGuess(in, out);
        
        // Check if the input is a valid numeric string
        if (!isNumeric(userGuess)) {
            out << "Invalid input. Please enter a 4-digit number with non-repeating digits." << endl;
            continue;
        }
        
        // Check the guess and provide feedback
        auto feedback = checkGuess(expected, userGuess);
        out << "Correct numbers: " << feedback.first << " Correct position: " << feedback.second << endl;
        attempts++;
        
        // If the user has guessed correctly, congratulate them and exit the loop
        if (feedback.second == 4) {
            out << "Congratulations! You guessed the number " << expected << " correctly in " << attempts << " attempts!" << endl;
            break;
        }
    }

    // If maximum attempts are reached, reveal the correct number
    if (attempts >= maxAttempts) {
        out << "Max attempts reached. The correct number was " << expected << "." << endl;
    }
    return attempts;  // Return the number of attempts made
}

// Main function to seed the random number generator, generate a random number, and start the guessing game
int _main(istream &in = cin, ostream &out = cout) {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator (not needed with mt19937)
    string randomNumber = generateRandomNumber();  // Generate the random number
    acceptGuess(randomNumber, in, out);  // Start the guessing process
    return 0;  // Return success
}
