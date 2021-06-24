class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;
        int c=0;
        while(i<nums.size()){
           if(nums[i]>nums[(i+1)%nums.size()]){
               ++c;
           } 
           ++i;
        }
         if(c<2){
            return true;
         }
        return false;
    }
};
      
    

