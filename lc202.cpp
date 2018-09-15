//leetcode: 202. Happy Number
//solution 1:
//update n, check if it equal to 16(endless unhappy number)
//foreach round each digit pow(n%2,2) and get the next digit by n/10 
class Solution {
public:
    bool isHappy(int n) {
        int prev = -1;
        int sum = 0;
        if (n == 1) return true;
        
        while(prev != n && n != 16){
            prev = n;
            sum = 0;
            while(n > 9){
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            sum += (n % 10) * (n % 10);
            if(sum == 1) return true;
            n = sum;
        }
        return false;
    }
};
//solution 2: use Floyd Cycle detection algorithm
class Solution {
public:
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        do{
            fast = happySum(fast);
            fast = happySum(fast);
            slow = happySum(slow);
            if(fast == 1) return true;
        }while (fast != slow);
        return false;
    }
    
    int happySum(int n){
        int sum = 0;
        while (n > 0){
            int d = n % 10;
            sum += d*d;
            n /= 10;           
        }
        return sum;
    }
    
    
};