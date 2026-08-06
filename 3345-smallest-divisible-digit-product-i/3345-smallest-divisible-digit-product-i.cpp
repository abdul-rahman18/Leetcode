class Solution {
public:
    int digitProduct(int n){
        int p=1;
        while(n>0)
            {
                p*=n%10;
                n=n/10;
            }
        return p;
    }
    int smallestNumber(int n, int t) {
        int ans;
        for(int i=n;i<=100;i++)
        {
            int x=digitProduct(i);
            if(x%t==0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};