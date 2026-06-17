#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <chrono>
#include <cstdlib>

const std::string RESET   = "\033[0m";
const std::string RED     = "\033[1;31m";
const std::string GREEN   = "\033[1;32m";
const std::string YELLOW  = "\033[1;33m";
const std::string BLUE    = "\033[1;34m";
const std::string CYAN    = "\033[1;36m";

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void pauseForUser() {
    std::cout << YELLOW << "\nPress Enter to return to the menu..." << RESET;
    std::cin.ignore(10000, '\n'); 
    std::cin.get();
}

void runDivisibleNumbers() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "          PROBLEM 1: DIVISIBLE NUMBERS         " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Finds a pair of integers (x, y) such that a < x <= c" << std::endl;
    std::cout << "             and b < y <= d, where the product (x * y) is cleanly" << std::endl;
    std::cout << "             divisible by (a * b). Returns -1 -1 if impossible." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter values for a, b, c, d (space-separated): ";
    long long a, b, c, d;
    if (!(std::cin >> a >> b >> c >> d)) {
        std::cout << RED << "Invalid inputs!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }

    long long ab = a * b;
    bool found = false;
    
    for (long long x = a + 1; x <= c; x++) {
        long long crnt_gcd = std::gcd(x, ab);
        long long n = ab / crnt_gcd;
        long long y = ((b + n) / n) * n;

        if (y <= d) {
            std::cout << GREEN << "\nOUTPUT: " << x << " " << y << RESET << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << GREEN << "\nOUTPUT: -1 -1" << RESET << std::endl;
    }
    pauseForUser();
}

void runOddSet() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "            PROBLEM 2: ODD SET                 " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Given a multiset containing 2*n integers, this determines" << std::endl;
    std::cout << "             if it can be split into exactly n pairs such that" << std::endl;
    std::cout << "             the sum of elements in every single pair is ODD." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter set size (n): ";
    int n;
    if (!(std::cin >> n)) {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }

    std::cout << "Enter " << 2 * n << " elements (space-separated): ";
    int even_cnt = 0, odd_cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        int num;
        std::cin >> num;
        if (num % 2 == 0) even_cnt++;
        else odd_cnt++;
    }

    if (odd_cnt == n && even_cnt == n) {
        std::cout << GREEN << "\nOUTPUT: YES" << RESET << std::endl;
    } else {
        std::cout << GREEN << "\nOUTPUT: NO" << RESET << std::endl;
    }
    pauseForUser();
}

void runPreparingForOlympiad() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "       PROBLEM 3: PREPARING FOR OLYMPIAD      " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Monocarp and Stereocarp train for n days. If Monocarp trains" << std::endl;
    std::cout << "             on day i, he gets a[i] points, but Stereocarp gets b[i+1]" << std::endl;
    std::cout << "             points on the next day. Maximizes Monocarp's score margin." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter total elements count (n): ";
    int n;
    if (!(std::cin >> n)) {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }

    std::vector<int> a(n);
    std::vector<int> b(n);
    
    std::cout << "Enter sequence values for A: ";
    for (int i = 0; i < n; i++) std::cin >> a[i];
    
    std::cout << "Enter sequence values for B: ";
    for (int i = 0; i < n; i++) std::cin >> b[i];

    long long max_diff = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i + 1]) {
            max_diff += a[i] - b[i + 1];
        }
    }
    max_diff += a[n - 1];
    
    std::cout << GREEN << "\nOUTPUT: " << max_diff << RESET << std::endl;
    pauseForUser();
}

void runMaximumSum() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "             PROBLEM 4: MAXIMUM SUM            " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Performs k total operations on an array. In each move," << std::endl;
    std::cout << "             you can either delete the 2 smallest elements or delete" << std::endl;
    std::cout << "             the 1 largest element. Calculates the maximum possible sum remaining." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter array size (n) and operations limit (k): ";
    int n, k;
    if (!(std::cin >> n >> k)) {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }

    std::vector<int> arr(n);
    std::cout << "Enter element values: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    
    std::sort(arr.begin(), arr.end());
    
    std::vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + arr[i];
    }
    
    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        int front = 2 * i;
        int back = k - i;
        int start = front;
        int end = n - back;
        if (start <= end) {
            long long currentsum = pref[end] - pref[start];
            ans = std::max(ans, currentsum);
        }
    }
    
    std::cout << GREEN << "\nOUTPUT: " << ans << RESET << std::endl;
    pauseForUser();
}

void runMaximumGCD() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "             PROBLEM 5: MAXIMUM GCD            " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Given an integer n, choose two distinct integers a and b" << std::endl;
    std::cout << "             (1 <= a < b <= n) such that their Greatest Common Divisor," << std::endl;
    std::cout << "             gcd(a, b), is as large as possible." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter roof maximum boundary limit (n): ";
    int n;
    if (!(std::cin >> n)) {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }
    
    std::cout << GREEN << "\nOUTPUT: " << n / 2 << RESET << std::endl;
    pauseForUser();
}

void runXORwice() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "               PROBLEM 6: XORWICE              " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Given two integers a and b, find an integer x such that" << std::endl;
    std::cout << "             the bitwise value of (a XOR x) + (b XOR x) is completely" << std::endl;
    std::cout << "             minimized. Relies on bitwise optimization parameters." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter space-separated integers a and b: ";
    long long a, b;
    if (!(std::cin >> a >> b)) {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }
    
    long long result = a ^ b;
    std::cout << GREEN << "\nOUTPUT: " << result << RESET << std::endl;
    pauseForUser();
}

void runGrasshopperOnLine() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "       PROBLEM 7: GRASSHOPPER ON THE LINE     " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: You are at coordinate 0 and want to hop to coordinate x." << std::endl;
    std::cout << "             You can jump any distance except lengths that are divisible" << std::endl;
    std::cout << "             by k. Computes the minimum number of jumps needed." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter destination point coordinate (x) and step constraint (k): ";
    int x, k;
    if (!(std::cin >> x >> k)) {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        clearInputBuffer();
        return;
    }

    if (x % k != 0) {
        std::cout << GREEN << "\nOUTPUT:\n1\n" << x << RESET << std::endl;
    } else {
        std::cout << GREEN << "\nOUTPUT:\n2\n" << x - 1 << " 1" << RESET << std::endl;
    }
    pauseForUser();
}

void runNightAtMuseum() {
    std::cout << CYAN << "\n==============================================" << std::endl;
    std::cout << "         PROBLEM 8: NIGHT AT THE MUSEUM       " << std::endl;
    std::cout << "==============================================" << RESET << std::endl;
    std::cout << "DESCRIPTION: Simulates a physical circular alphabet printing wheel." << std::endl;
    std::cout << "             Calculates the minimum number of total clockwise or" << std::endl;
    std::cout << "             counter-clockwise rotations required to spell a word." << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;

    std::cout << "Enter your target word characters: ";
    std::string name;
    std::cin.ignore(); 
    std::getline(std::cin, name);

    int total_rotations = 0;
    char current_letter = 'a';
    for (size_t i = 0; i < name.length(); i++) {
        char letter = name[i];
        int diff = std::abs(letter - current_letter);
        int short_path = std::min(diff, 26 - diff);
        total_rotations += short_path;
        current_letter = letter;
    }
    
    std::cout << GREEN << "\nOUTPUT: " << total_rotations << RESET << std::endl;
    
    std::cout << YELLOW << "\nPress Enter to return to the menu..." << RESET;
    std::cin.get();
}

void printBanner() {
    std::cout << YELLOW << "\n=================================================" << RESET << std::endl;
    std::cout << BLUE   << "       CODEFORCES INTERACTIVE ENGINE PANEL       " << RESET << std::endl;
    std::cout << YELLOW << "=================================================" << RESET << std::endl;
}

int main() {
    int choice = 0;

    while (true) {
        printBanner();
        std::cout << "Select a problem solution module to evaluate:" << std::endl;
        std::cout << "1. Divisible Numbers Solver" << std::endl;
        std::cout << "2. Odd Set Configuration Balance" << std::endl;
        std::cout << "3. Preparing for the Olympiad Tracker" << std::endl;
        std::cout << "4. Maximum Sum Subarray Optimization" << std::endl;
        std::cout << "5. Maximum GCD Calculator" << std::endl;
        std::cout << "6. XORwice Value Evaluator" << std::endl;
        std::cout << "7. Grasshopper Line Path Simulation" << std::endl;
        std::cout << "8. Night at the Museum Wheel Matrix" << std::endl;
        std::cout << "9. " << RED << "Exit Suite Engine Application" << RESET << std::endl;
        
        std::cout << "\nEnter selection ID index (1-9): ";
        if (!(std::cin >> choice)) {
            std::cout << RED << "Please select a numeric option index!" << RESET << std::endl;
            clearInputBuffer();
            continue;
        }

        if (choice == 9) {
            std::cout << RED << "\nShutting down framework dashboards. Good luck with Stardance!" << RESET << std::endl;
            break;
        }

        auto startTime = std::chrono::high_resolution_clock::now();

        switch (choice) {
            case 1: runDivisibleNumbers(); break;
            case 2: runOddSet(); break;
            case 3: runPreparingForOlympiad(); break;
            case 4: runMaximumSum(); break;
            case 5: runMaximumGCD(); break;
            case 6: runXORwice(); break;
            case 7: runGrasshopperOnLine(); break;
            case 8: runNightAtMuseum(); break;
            default:
                std::cout << RED << "Selected option out of bounds range." << RESET << std::endl;
                break;
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
        std::cout << YELLOW << ">> Diagnostic Compute Time Profile: " << elapsed.count() << " ms." << RESET << std::endl;
    }

    return 0;
}
