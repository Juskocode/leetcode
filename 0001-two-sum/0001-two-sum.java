class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> seen = new HashMap<>();
        int y = 0;

        for (int i = 0; i < nums.length; i++)
        {
            y = target - nums[i];
            if (seen.containsKey(y))
                return new int[]{seen.get(y), i};
            seen.put(nums[i], i);
        }
        return new int[]{};
    }
}