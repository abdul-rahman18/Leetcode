class Solution {
public:
    double myPower(double x, long n) {
        if(n == 1) return x;

        if(n == 0) return double(1);

        if(n < 0) return 1 / myPower(x, -n);

        double power = myPower(x,n/2);

        if(n % 2 != 0) return x * power * power;

        return power * power;
    }

    double myPow(double x, int n) {
        return myPower(x,n);
    }
};