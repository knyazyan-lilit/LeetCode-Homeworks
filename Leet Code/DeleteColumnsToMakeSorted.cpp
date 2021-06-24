class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleted=0;
        for(int j=0;j<strs[0].size();++j){
                int i=0;
                while(i+1<strs.size()){
                    if(strs[i][j]>strs[i+1][j]){
                    ++deleted;
                    break;
                    }
                    else{
                        ++i;
                    }
                 }
        }
        return deleted;
       
    }
};
