# 🚀 Advanced Expense Optimizer V2.0

## 📝 Project Report & Details

### 📌 Overview
The **Expense Optimizer** is a sophisticated financial tool developed in C++ designed to help users maximize their utility from a fixed monthly budget. Unlike simple tracking apps, this project uses **Dynamic Programming** to intelligently select which expenses to fund and which to skip, based on their relative importance (priority) and cost.

### 🏗️ Problem Statement
When faced with limited financial resources and a long list of desired expenses, individuals often struggle to decide which items provide the most value. Manual calculation is tedious and often suboptimal. This project automates that decision-making process.

### 🧠 Core Algorithm: 0/1 Knapsack
The backbone of this project is the **0/1 Knapsack Problem** algorithm. 
- **Capacity**: Total Monthly Budget.
- **Weights**: Cost of each expense item.
- **Values**: Priority (1-10) assigned by the user.
- **Goal**: Maximize the total priority gain without exceeding the budget.

By using a 2D DP table, the program ensures an optimal solution that is mathematically guaranteed to be the best possible combination of items.

---

### ✨ Key Features
- **Intelligent Optimization**: Uses dynamic programming for optimal resource allocation.
- **Visual Feedback**: Includes a terminal-based loading animation and clean formatted tables.
- **Priority-Based Logic**: Users define what matters most to them.
- **Budget Advisory**: Provides a health check on your spending (Critical, Moderate, or Excellent).
- **Data Integrity**: Robust input validation for budget and costs.

---

### 🛠️ Technical Details
- **Language**: C++
- **Libraries**: `<iostream>`, `<vector>`, `<algorithm>`, `<iomanip>`, `<windows.h>` (for UI effects).
- **Data Structure**: `struct Expense` to store item metadata.
- **Complexity**: $O(N \times W)$ where $N$ is the number of items and $W$ is the budget.

---

### 🚀 How to Run

1. **Prerequisites**:
   - A C++ compiler (GCC/MinGW).
   - Windows OS (due to `windows.h` and `system("cls")`).

2. **Compilation**:
   ```bash
   g++ Expense_Optimizer.cpp -o ExpenseOptimizer.exe
   ```

3. **Execution**:
   ```bash
   ./ExpenseOptimizer.exe
   ```

---

### 📊 Sample Output Report
When running the optimizer, you will see a summary like this:

```text
============================================================
        FINAL OPTIMIZED BUDGET PLAN
============================================================
NAME           CATEGORY       COST      PRIORITY
------------------------------------------------------------
Rent           Housing        500       10
Internet       Utilities      50        8
Groceries      Food           200       9
------------------------------------------------------------
BUDGET SUMMARY:
> Initial Budget      : 800
> Total Spent         : 750
> Remaining Savings   : 50
> Utilization         : 93.75%
> Total Priority Gain : 27

ADVISORY: Critical!
============================================================
```

---

### 📜 Conclusion
The **Expense Optimizer** demonstrates the practical application of classical computer science algorithms in solving real-world financial problems. It provides a scalable and efficient way to manage personal finances scientifically.

---
*Developed as part of the CCC Project series.*