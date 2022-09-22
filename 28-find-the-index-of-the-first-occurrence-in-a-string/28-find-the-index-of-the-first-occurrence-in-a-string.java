class Solution {
    public int strStr(String haystack, String needle) {
        int pos=haystack.indexOf(needle);
        if(pos>=0)
            return pos;
        return -1;
    }
}