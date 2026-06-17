# My Codeforces Problem Suite

This is a simple terminal project. I really like competitive programming, so I wanted to group y recent solved Codeforces solutions into a single C++ file that anyone can run and interact with.

## What it does
Instead of just being a bunch of random `.cpp` files, this program runs an active menu loop in your terminal. 
* You choose a problem from the menu (1 to 8).
* The app prints a short message explaining what that specific problem wants you to solve.
* It asks you to type in the inputs.
* It runs the solution logic, prints out the correct output (`YES`, `NO`, or numbers), and prints how many milliseconds your computer took to calculate it.
* It pauses so you can actually read the answer, and goes back to the menu when you press Enter.

## Problems Included
1. **Divisible Numbers(Easy Version)**: Finds a math pair (x, y) divisible by (a * b).
2. **Odd Set** : Checks if an array can be split into pairs that add up to odd numbers.
3. **Preparing for the Olympiad** : Calculates the maximum training score margin.
4. **Maximum Sum** : Deletes elements to find the biggest leftover sum.
5. **Maximum GCD** : Quickly finds the largest Greatest Common Divisor in a range.
6. **XORwice** : Uses bitwise XOR math to minimize two numbers.
7. **Grasshopper on the Line** : Simulates jump distances to cross a line safely.
8. **Night at the Museum** : Calculates the fastest way to spin a wheel to spell a word.

## Project Demo
Watch the full video demo of the program running here: **[Watch on YouTube](YOUR_YOUTUBE_LINK_HERE)** 
OR
Try it yourself: **[Github releases](https://github.com/Isha-saleem/Codeforces_Problemset_Suite/releases/tag/v1.0.0)**

## How to Install and Run
To ensure the output executable can run smoothly on any machine without needing independent system libraries like `libstdc++` pre-installed, compile it using the static flag:
```bash
g++ -std=c++17 -static main.cpp -o suite
