class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> myStack;
        pair<char, int> s_top;
        string result = "";
        myStack.push(make_pair(s[0], 1));
        for(int i = 1; i < s.length(); i++) {
            if(myStack.empty()) {
                myStack.push(make_pair(s[i], 1));
                continue;
            }
            s_top = myStack.top();
            if(s[i] == s_top.first) {
                myStack.pop();
                myStack.push(make_pair(s[i], s_top.second + 1));
            }
            else{
                myStack.push(make_pair(s[i], 1));
            }
            
            s_top = myStack.top();
            if(s_top.second % k == 0) myStack.pop();
            else {
                myStack.pop();
                myStack.push(make_pair(s[i], s_top.second % k));
            }
        }
        while(!myStack.empty()) {
            s_top = myStack.top();
            for(int i = 0; i < s_top.second; i++)
                result += s_top.first;
            myStack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
