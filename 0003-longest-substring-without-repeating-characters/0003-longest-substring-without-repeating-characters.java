class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> lastSeen = new HashMap<>();
        int best = 0, l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);

            if (lastSeen.containsKey(c) && lastSeen.get(c) >= l)
                l = lastSeen.get(c) + 1;
            
            lastSeen.put(c, r);
            best = Math.max(best, r - l + 1);
        }
        return best;
    }
}