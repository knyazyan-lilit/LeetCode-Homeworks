class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle==""){
            return 0;
        }
        if(haystack.size()<needle.size()){
            return -1;
        }
         int size=needle.size();
         int i=0;
         int j=0;
         int equals = 0;
         while(i<haystack.size()){
             equals=0;
             while(j<size){
                 if(haystack[i]==needle[j])
                 {
                     ++equals;
                     ++j;
                     ++i;
                     if(equals==size){
                         return i-size;
                     }
                 }
                 else{break;}
             }

              j=0;
              i=i-equals+1;
         }
            return -1;
    }
};
