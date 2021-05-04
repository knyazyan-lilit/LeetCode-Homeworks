// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=n;
        while(i-1>0){
            if(isBadVersion(i) == true && isBadVersion(i-1) == false){
                return i;
                break;
            }
            else{
                i--;
            }
        }
        return i;
    }
};


