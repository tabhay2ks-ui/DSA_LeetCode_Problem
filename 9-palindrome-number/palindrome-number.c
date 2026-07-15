bool isPalindrome(int x) {
    long long reversed = 0;
    int original = x;
    int remainder;
    if(x<0){
        return false;
    }
    while(x != 0){
        remainder = x%10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }
    return original == reversed;
}