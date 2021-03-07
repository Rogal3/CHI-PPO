// 5697. Check if Binary String Has at Most One Segment of Ones

class Solution {
    public boolean checkOnesSegment(String s) {
        int i = 0;
        for (; i < s.length() && s.charAt(i) == '1'; i++);
        for (; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                break;
            }
        }
        return i == s.length();
    }
}
