#include<iostream>
#include<unordered_set>
using namespace std;

/*
Description:
Design a phone directory that initially has maxNumbers empty slots that can store numbers.
The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.
Implement the PhoneDirectory class:
-PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
-int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
-bool check(int number) Returns true if the slot number is available and false otherwise.
-void release(int number) Recycles or releases the slot number.
Example:
Input
["PhoneDirectory", "get", "get", "check", "get", "check", "release", "check"]
[[3], [], [], [2], [], [2], [2], [2]]
Output
[null, 0, 1, true, 2, false, null, true]
*/

class PhoneDirectory {

private:
    unordered_set<int> available;

public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available.insert(i);
        }
    }

    int get() {
        if (available.empty()) {
            return -1;
        }
        int x = *available.begin();
        available.erase(x);
        return x;
    }

    bool check(int number) {
        return available.count(number);
    }

    void release(int number) {
        available.insert(number);
    }

};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */