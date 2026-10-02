class Solution {
public:
    int N;
    vector<string>strs;

    void generate(string str, int idx, int oc, int cc) {

        if(idx == 2 * N){
            strs.push_back(str);
            return;
        }

        if(oc < N) {
            str += '(';
            generate(str, idx+1, oc+1, cc);
            str.pop_back();
        }

        if(oc > cc) {
            str += ')';
            generate(str, idx+1, oc, cc+1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        generate("", 0, 0, 0);
        return strs;
    }
};