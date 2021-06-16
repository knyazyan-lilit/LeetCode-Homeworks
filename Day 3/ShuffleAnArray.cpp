#include <ctime>

class Solution {
private:
    vector<int> nums;
    unordered_map<int, int> m;
public:
    Solution(vector<int>& nums) {
      for(int i=0;i<nums.size();++i){
          this->nums.push_back(nums[i]);
          m.insert({i,nums[i]});
      }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        int i=0;
        while(i<nums.size()){
            nums[i]= m[i];
            ++i;
        }
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
            for (int i=0; i<nums.size(); ++i)
            {
               int r = rand()%nums.size();
                std::swap(nums[i],nums[r]);
            }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
