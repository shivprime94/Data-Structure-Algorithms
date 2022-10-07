class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> lol = new TreeMap<Integer, Integer>();
        for(int i : nums){
            if(lol.containsKey(i)) lol.put(i, lol.get(i)+1);
            else lol.put(i, 1);
        }
        for(int i : lol.keySet()){
            if(lol.get(i)==1) return i;
        }
        return 0;
    }
}
