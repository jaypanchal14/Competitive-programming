#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a sequence of item costs matches given notification counts
bool isValidSequence(const vector<int>& notifications, const vector<int>& itemCosts) {
    vector<int> calculatedNotifications(itemCosts.size(), 1);
    
    for (int i = 1; i < itemCosts.size(); ++i) {
        if (itemCosts[i] < itemCosts[i - 1]) {
            calculatedNotifications[i] = calculatedNotifications[i - 1] + 1;
        } else {
            calculatedNotifications[i] = 1;
        }
    }
    
    return calculatedNotifications == notifications;
}

// Function to generate all permutations of item costs and validate them against given notification counts
void generateValidPermutations(const vector<int>& notifications, vector<int>& itemCosts, vector<vector<int>>& validPermutations, vector<bool>& used) {
    if (itemCosts.size() == notifications.size()) {
        if (isValidSequence(notifications, itemCosts)) {
            validPermutations.push_back(itemCosts);
        }
        return;
    }
    
    for (int i = 0; i < used.size(); ++i) {
        if (!used[i]) {
            itemCosts.push_back(i); // Using index i as item cost
            used[i] = true;
            generateValidPermutations(notifications, itemCosts, validPermutations, used);
            used[i] = false;
            itemCosts.pop_back();
        }
    }
}

int main() {
    // Example with given notification counts and order prices in increasing order
    vector<int> notifications = {1, 2, 3, 1, 2};
    vector<int> orderPrices = {10, 15, 20, 25, 30}; // Assume prices are in increasing order
    
    int n = notifications.size();
    
    // Vector to store valid permutations of item costs
    vector<vector<int>> validPermutations;
    
    // Vector to store current permutation of item costs being generated
    vector<int> itemCosts;
    
    // Vector to keep track of used item costs
    vector<bool> used(n, false);
    
    // Generate valid permutations
    generateValidPermutations(notifications, itemCosts, validPermutations, used);
    
    // Output valid permutations
    cout << "Valid permutations of item costs:" << endl;
    for (const auto& perm : validPermutations) {
        for (int i : perm) {
            cout << orderPrices[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
