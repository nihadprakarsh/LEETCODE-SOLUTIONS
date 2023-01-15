class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        pre = [0] * len(arr)
        x = 0
        ans = 0
        for i in range(n):
            pre[i] = x
            x ^= arr[i]
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j, n):
                    l = pre[j] ^ pre[i]
                    r = pre[k] ^ pre[j] ^ arr[k]
                    if l == r:
                        ans += 1
        return ans

        