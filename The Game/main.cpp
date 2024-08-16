// Code by oantby && KirubelYonas
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

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

string getUserGuess() {
    string guess;
    cout << "Enter your guess (a 4-digit number with non-repeating digits): ";
    cin >> guess;
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

int main() {
    // Seed rand since random_shuffle _probably_ uses it.
    srand(static_cast<unsigned>(time(0)));

    string randomNumber = generateRandomNumber();

    int attempts = 0;

    while (true) {
        string userGuess = getUserGuess();
        if (userGuess.length() != 4 || hasDuplicateDigits(userGuess) || !isNumeric(userGuess)) {
            cout << "Invalid input. Please enter a 4-digit number with non-repeating digits." << endl;
            continue;
        }

        auto [corNum, corPos] = checkGuess(randomNumber, userGuess);
        cout << "Correct numbers: " << corNum << " Correct position: " << corPos << endl;

        attempts++;

        if (corPos == 4) {
            cout << "Congratulations! You guessed the number " << randomNumber << " correctly in " << attempts << " attempts!" << endl;
            break;
        }
    }

    return 0;
}
