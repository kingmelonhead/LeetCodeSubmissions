class Solution {
    public boolean isPalindrome(int x) {
        int dupe = x;
        if (dupe < 0) return false; // neagtive nums cant be palindromes
        long temp = 0;
        while (dupe > 0){
            temp = (10 * temp) + (dupe % 10);
            dupe /= 10;
        }
        if (x == temp) return true;
        return false;
    }
}
