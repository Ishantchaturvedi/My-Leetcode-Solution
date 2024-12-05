class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0;
        int j = 0;
        while(i < start.length() && j < target.length()){
            if(start[i] == '_'){
                i++;
                continue;
            }
            if(target[j] == '_'){
                j++;
            }
            else if(start[i] == target[j] && start[i] == 'L' && i >= j){
                j++;
                i++;
            }
            else if(start[i] == target[j] && start[i] == 'R' && i <= j){
                j++;
                i++;
            }
            else{
                return false;
            }
        }
        while(i < start.length()){
            if(start[i] != '_'){
                return false;
            }
            i++;
        }
        while(j < target.length()){
            if(target[j] != '_'){
                return false;
            }
            j++;
        }
        return true;
    }
};