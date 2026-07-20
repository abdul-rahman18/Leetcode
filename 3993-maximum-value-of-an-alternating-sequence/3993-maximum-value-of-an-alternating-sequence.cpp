class Solution {
public:
    long long method1(long long n, long long s, long long m)
    {
        if(n==1) return s;

        long long num = s+m + (((n-2)/2) * (m-1));
        //long long next = num - 1;
        
        // long long mx = num;

        // long long idx = 4;

        // while(idx <= n){
        //     num = num*2;
        //     num = num - ( (num-next) - m );
        //     next = num-1;
        //     idx+=2;
        //     mx = max(mx,num);
        // }


        return num;
    }
    
    long long maximumValue(int n, int s, int m) {
        long long ans1 = method1(n,s,m);
        //long long ans2 = method2(n,s,m);

        //long long ans = max(ans1,ans2);

        return ans1;
    }
};