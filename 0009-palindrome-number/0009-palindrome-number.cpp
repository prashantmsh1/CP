class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        
        long int rem=0;
        long int dig=0;
        if(x<0)
            return false;
        else{
            while(num!=0){
            rem=num%10;
            dig=dig*10+rem;
            num=num/10;
        }
        }
        
        if(x==dig)
            return true;
        else 
            return false;
    }
    
};