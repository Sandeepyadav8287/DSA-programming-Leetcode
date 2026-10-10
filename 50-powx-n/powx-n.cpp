class Solution {
public:
    double myPow(double x, int n) {
        double ans =1.0 ;
        long long N = n;
        if(N == 1){
            return x;
        }
       
        if(N < 0){
            N = -N;
            
        }

    while(N >0){
        if(N %2 == 1){
            ans *= x;
        }

        x *= x;
        N /=2;
    }


        return n <0 ? 1.0/ans :ans;
    }
};