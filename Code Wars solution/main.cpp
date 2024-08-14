//Code by AXER-doc
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::make_pair;
using std::mt19937;
using std::ostream;
using std::pair;
using std::random_device;
using std::string;
using std::vector;

string generateRandomNumber() {
    vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Initialize random number generator
    random_device rd;  // Obtain a random number from hardware
    mt19937 g(rd());  // Seed the generator

    // Shuffle digits
    shuffle(digits.begin(), digits.end(), g);

    // Return the first 4 digits as a string
    return string(digits.begin(), digits.begin() + 4);
}

bool hasDuplicateDigits(const string &number) {
    vector<bool> seen(10, false);
    for (const auto c : number) {
        if (seen[c - '0']) return true;
        seen[c - '0'] = true;
    }
    return false;
}

bool isNumeric(const string &s) {
    return all_of(s.begin(), s.end(), [](char c){ return isdigit(c); });
}

string getUserGuess(istream &in = cin, ostream &out = cout) {
    string guess;
    out << "Enter your guess (a 4-digit number with non-repeating digits): ";
    in >> guess;
    return guess;
}

pair<int, int> checkGuess(const string &randomNumber, const string &userGuess) {
    int correctNumbers = 0;
    int correctPosition = 0;

    for (int i = 0; i < 4; ++i) {
        if (randomNumber[i] == userGuess[i]) {
            correctNumbers++;
            correctPosition++;
        } else if (count(randomNumber.begin(), randomNumber.end(), userGuess[i])) {
            correctNumbers++;
        }
    }

    return make_pair(correctNumbers, correctPosition);
}

int acceptGuess(const string &expected, istream &in = cin, ostream &out = cout) {
    int attempts = 0;
    while (true) {
        string userGuess = getUserGuess(in, out);
        if (userGuess.length() != 4 || hasDuplicateDigits(userGuess) || !isNumeric(userGuess)) {
            out << "Invalid input. Please enter a 4-digit number with non-repeating digits." << endl;
            continue;
        }
        auto [corNum, corPos] = checkGuess(expected, userGuess);
        out << "Correct numbers: " << corNum << " Correct position: " << corPos << endl;
        attempts++;
        if (corPos == 4) {
            out << "Congratulations! You guessed the number " << expected << " correctly in " << attempts << " attempts!" << endl;
            break;
        }
    }
    return attempts;
}

int _main(istream &in = cin, ostream &out = cout) {
    // Seed rand since random_shuffle _probably_ uses it.
    srand(static_cast<unsigned>(time(0)));
    string randomNumber = generateRandomNumber();
    acceptGuess(randomNumber, in, out);
    return 0;
}
// TEST CASES
/*
// Your game should output as followed in the description 
// Not sure how to put a test case for these type of codes

// this feels a lot like it might've been an interesting
// homework assignment or something, given the presence of a main
// function and the lack of main functions in how kata/kumite work.
// I'm still for it for the half-interesting aspect, but definitely
// a bit odd.

using std::istringstream;
using std::ostringstream;

Describe(Tests) {
  It(Guess_Test_1) {
    istringstream in("8903");
    ostringstream out;
    acceptGuess("8903", in, out);
    Assert::That(out.str(), Equals("Enter your guess (a 4-digit number with non-repeating digits): "
                                   "Correct numbers: 4 Correct position: 4\n"
                                   "Congratulations! You guessed the number 8903 correctly in 1 attempts!\n"));
  }
  It(Guess_Test_2) {
    istringstream in("8903\n9012");
    ostringstream out;
    acceptGuess("9012", in, out);
    Assert::That(out.str(), Equals("Enter your guess (a 4-digit number with non-repeating digits): "
                                   "Correct numbers: 2 Correct position: 0\n"
                                   "Enter your guess (a 4-digit number with non-repeating digits): "
                                   "Correct numbers: 4 Correct position: 4\n"
                                   "Congratulations! You guessed the number 9012 correctly in 2 attempts!\n"));
  }
};*/
