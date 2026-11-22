class Solution {
public:
    bool checkString(string s) {

        bool foundB = false;
        for(auto& c : s){
            if(c == 'b') 
            {
                foundB = true;
                continue;
            }

            if(foundB && c == 'a') return false;
        }

        return true;
    }
};