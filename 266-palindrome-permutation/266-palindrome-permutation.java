class Solution {
    public boolean canPermutePalindrome(String s) {
        int n=s.length();
        Map<Character,Integer> ht =new TreeMap<>();
        for(int i=0;i<n;i++){
            if(ht.containsKey(s.charAt(i))){
            int z=ht.get(s.charAt(i));
            ht.put(s.charAt(i),z+1);
            }
            else{
                ht.put(s.charAt(i),1);
            }
            
        }
        int o=0;
        for(Map.Entry<Character,Integer> it:ht.entrySet()){
            int a=it.getKey();
            int b=it.getValue();
            if(b%2!=0)o++;
        }
        if(o<=1)return true;
        return false;
        
    }
}