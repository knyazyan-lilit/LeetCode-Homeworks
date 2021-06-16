class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        int size = nums.size();
        while (i < k) {
            int temp = nums[size-1];
            for (int j =size-1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
            i++;
	}
    }
};
