#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current,
                   int openCount, int closeCount, int n) {
        // If the string is complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still can
        if (openCount < n) {
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        }

        // Add ')' if it keeps the string valid
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, n);
        }
    }
};