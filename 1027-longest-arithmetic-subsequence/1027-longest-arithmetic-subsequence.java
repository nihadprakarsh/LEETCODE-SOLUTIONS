class Solution {
    int[][] dp = new int[1001][1003];
    
    public int find(int ind, int[] nums, int diff) {
        if(dp[ind][diff+501] != -1) return dp[ind][diff+501];
        
        int a = 1;
        
        if(diff == -501) {
            for(int i=ind+1; i<nums.length; ++i)
                a = Math.max(a, Math.max(1+find(i, nums, nums[i]-nums[ind]), find(i, nums, diff)));
        } else {
            for(int i=ind+1; i<nums.length; ++i) {
                if(nums[i]-nums[ind] == diff)
                    a = Math.max(a, 1+find(i, nums, diff));
            }
        }
        
        return dp[ind][diff+501] = a;
    }
    
    public int longestArithSeqLength(int[] nums) {
        Arrays.stream(dp).forEach(a -> Arrays.fill(a, -1));
        return find(0, nums, -501);
    }
}
