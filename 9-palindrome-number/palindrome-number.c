bool isPalindrome(int x) {
    long reversed = 0;
    int original = x;
    if(x<0){
        return false;
    }
    while(x > 0){
        reversed = reversed * 10 + x%10;
        x /= 10;
    }
    return original == reversed;
}