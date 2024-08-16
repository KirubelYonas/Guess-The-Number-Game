# Guess-The-Number-Game

## Overview
This is a command-line game written in C++ where the player tries to guess a randomly generated 4-digit number. The digits in the number are non-repeating. The game provides feedback after each guess, indicating how many digits are correct and how many are in the correct position.

## How to Play
1. When you run the program, it will generate a random 4-digit number with unique digits.
2. Your task is to guess this number.
3. After each guess, the game will tell you:
   - How many digits are correct.
   - How many of those correct digits are also in the correct position.
4. The game continues until you guess the number correctly.

## Rules
- The number consists of exactly 4 digits.
- Each digit in the number is unique (no repetitions).
- You must enter a valid 4-digit number with no repeated digits.

## Example
    Enter your guess (a 4-digit number with non-repeating digits): 1234
    Correct numbers: 2 Correct position: 1

    Enter your guess (a 4-digit number with non-repeating digits): 5678
    Correct numbers: 3 Correct position: 2

    Enter your guess (a 4-digit number with non-repeating digits): 5670
    Correct numbers: 4 Correct position: 4
    Congratulations! You guessed the number 5670 correctly in 3 attempts!

## How It Works
- **Random Number Generation:** The game generates a random 4-digit number using the C++ Standard Library's random number generator.
- **Input Validation:** The game checks that your input is a valid 4-digit number with no repeated digits.
- **Feedback:** After each guess, the game compares your guess with the generated number and provides feedback on how many digits are correct and how many are in the correct position.

## Requirements
A C++ compiler that supports C++17 or later.

## License
This project is licensed under the MIT License. Feel free to use and modify the code as you see fit.

## Acknowledgements
This game was inspired  classic Mastermind board game concept.
