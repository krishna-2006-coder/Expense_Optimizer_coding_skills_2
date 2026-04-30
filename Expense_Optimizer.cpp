#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

struct Expense {
    string name;
    string category;
    int cost;
    int priority;
};

void clearScreen() {
    system("cls");
}

void showLoading() {
    cout << "Optimizing your budget: [";
    for(int i = 0; i < 20; ++i) {
        cout << "#" << flush;
        Sleep(50);
    }
    cout << "] 100%\n";
}

void printLine() {
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
}

int main() {
    int n, budget;

    clearScreen();
    cout << "============================================================\n";
    cout << "        ADVANCED EXPENSE OPTIMIZER V2.0\n";
    cout << "============================================================\n";

    cout << "Enter Total Monthly Budget: ";
    while(!(cin >> budget) || budget <= 0) {
        cout << "Invalid input. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Number of Expense Items: ";
    while(!(cin >> n) || n <= 0) {
        cout << "Invalid input. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<Expense> items(n);

    for (int i = 0; i < n; i++) {
        printLine();
        cout << "ITEM #" << i + 1 << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: ";
        getline(cin, items[i].name);

        cout << "Category: ";
        getline(cin, items[i].category);

        cout << "Cost: ";
        cin >> items[i].cost;

        cout << "Priority (1-10): ";
        cin >> items[i].priority;
    }

    showLoading();

    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {
            if (items[i - 1].cost <= w) {
                dp[i][w] = max(
                    items[i - 1].priority + dp[i - 1][w - items[i - 1].cost],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<Expense> selected;
    int res = dp[n][budget];
    int w = budget;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            selected.push_back(items[i - 1]);
            res -= items[i - 1].priority;
            w -= items[i - 1].cost;
        }
    }

    clearScreen();
    cout << "============================================================\n";
    cout << "        FINAL OPTIMIZED BUDGET PLAN\n";
    cout << "============================================================\n";

    cout << left << setw(15) << "NAME"
         << setw(15) << "CATEGORY"
         << setw(10) << "COST"
         << "PRIORITY\n";

    printLine();

    int totalSpent = 0;

    for (const auto& item : selected) {
        cout << left << setw(15) << item.name
             << setw(15) << item.category
             << setw(10) << item.cost
             << item.priority << endl;
        totalSpent += item.cost;
    }

    printLine();

    double utilization = (double)totalSpent / budget * 100;

    cout << "BUDGET SUMMARY:\n";
    cout << "> Initial Budget      : " << budget << endl;
    cout << "> Total Spent         : " << totalSpent << endl;
    cout << "> Remaining Savings   : " << budget - totalSpent << endl;
    cout << "> Utilization         : " << fixed << setprecision(2) << utilization << "%\n";
    cout << "> Total Priority Gain : " << dp[n][budget] << endl;

    cout << "\nADVISORY: ";
    if(utilization > 90) cout << "Critical!\n";
    else if(utilization > 50) cout << "Moderate.\n";
    else cout << "Excellent savings!\n";

    cout << "============================================================\n";

    return 0;
}
