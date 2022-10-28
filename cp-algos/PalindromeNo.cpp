//Function for checking whether a number is a valid palindrome or not
bool isPalindrome(int x) {
        if(x<0){
                return false;
        }
           long int rev_num=0;
            int y=x;
            while(y>0){
                    rev_num = rev_num*10 + y % 10;
                    y=y/10;
            }
            if(rev_num == x){
                    return true;
            }
            return false;
    }
