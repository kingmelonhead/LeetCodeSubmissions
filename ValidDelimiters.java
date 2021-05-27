class Solution {
    public boolean isValid(String s) {
        int openIn = 0;
        List<Character> open = new ArrayList<Character>();
        open.add('0');
        for (int i = 0; i < s.length() ; i++){
            if (s.charAt(i) == ')'){
                if (open.get(openIn) != '(') return false;
                else open.remove(openIn--);
            }
            else if(s.charAt(i) == '}'){
                if (open.get(openIn) != '{') return false;
                else open.remove(openIn--);
            }
            else if (s.charAt(i) == ']'){
                if (open.get(openIn) != '[') return false;
                else open.remove(openIn--);
            }
            else {
                open.add(s.charAt(i));
                openIn++;
            }
        }
        if (open.size() == 1) return true;
        else return false;
    }
}
