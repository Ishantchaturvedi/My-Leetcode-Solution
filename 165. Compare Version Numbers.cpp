class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size()||j<version2.size()){
            int sum1=0,sum2=0;
            if(i<version1.size()){
                string s1;
                while(i<version1.size()&&version1[i]!='.'){
                    s1.push_back(version1[i]);
                    i++;
                }
                i++;
                sum1=stoi(s1);
            }
            if(j<version2.size()){
                string s2;
                while(j<version2.size()&&version2[j]!='.'){
                    s2.push_back(version2[j]);
                    j++;
                }
                j++;
                sum2=stoi(s2);
            }
            if(sum1>sum2) return 1;
            if(sum2>sum1) return -1;
        }
        return 0;
    }
};