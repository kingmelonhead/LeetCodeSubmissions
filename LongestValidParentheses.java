class Solution {
    public int longestValidParentheses(String s) {
        
        int longest = 0, left = 0, right = 0;
        
        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i) == '(') left++;
            else right++;
            if (left == right) longest = Math.max(longest, 2 * left);
            else if (right > left) left = right = 0;
        } // end of for loop
        
        left = right = 0;
        
        for (int i = s.length() - 1; i >= 0; i--){
            if (s.charAt(i) == '(') left++;
            else right++;
            if (left == right) longest = Math.max(longest, 2 * left);
            else if (left > right) left = right = 0;
        } // end of for loop
        
        return longest;
    }
}
