#include <set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int i=0;
        while(i<nums.size()){
            s.insert(nums[i]);
            ++i;
        }
         set<int >::iterator itr;
         nums.clear();
         for(itr=s.begin();itr != s.end();++itr ){
             nums.push_back(*itr);
         }
        return nums.size();
    }
};
