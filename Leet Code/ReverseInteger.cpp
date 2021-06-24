class Solution {
public:
    void reverseString(string& s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            ++i;
            --j;
        }
    }
    int reverse(int x) {
        string s =to_string(x);
        string tmp;
        if(s[0]=='-'){
            tmp="-";
            s.erase(0,1);
            reverseString(s);
            s.insert(0,tmp);
        }
        else{
            reverseString(s);
        }
        try {
            return stoi(s);
        } 
        catch(std::out_of_range e) { 
            return 0;
        }
    }
};
