#include <set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {        
        int i=0;
        set<int> s;
        while(i<nums.size()){
            s.insert(nums[i]);
            ++i;
        }
        if(s.size()==nums.size()){
            return false;
        }
        return true;
    }
};
