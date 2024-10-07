class Solution {
public:
    int minLength(string s) {
        while(true){
            bool flag = true;
            if(s.length() == 0 ||s.length() == 2) break;
            for(int i=0; i<s.length()-1; i++){
                string str = s.substr(i, 2);
                if(str == "AB" || str == "CD"){
                    flag = false;
                    s.erase(i, 2);
                }
            }
            if(flag) break;
        }
        if(s == "AB" || s == "CD") return 0;
        return s.length();
    }
};