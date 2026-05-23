class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();

        stack<int> s;

        for(int i = 0; i < n; i++) {

            if(!(tokens[i] == "*" || tokens[i] == "/" ||
                 tokens[i] == "+" || tokens[i] == "-")) {

                s.push(stoi(tokens[i]));
            }

            else {

                int a, b;

                a = s.top();
                s.pop();

                b = s.top();
                s.pop();

                if(tokens[i] == "*") {
                    s.push(b * a);
                }

                else if(tokens[i] == "/") {
                    s.push(b / a);
                }

                else if(tokens[i] == "+") {
                    s.push(b + a);
                }

                else if(tokens[i] == "-") {
                    s.push(b - a);
                }
            }
        }

        return s.top();
    }
};