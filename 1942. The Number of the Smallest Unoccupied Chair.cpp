
class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int t){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int f = a[t][0];                             
        sort(a.begin(), a.end());
        int n=0;                                      
        set<int> s;
        for(auto v: a){
            int at = v[0];                            
            int lt = v[1];                            
            int cs;                                   
            while(!q.empty() && q.top().first<=at){       
                s.insert(q.top().second);
                q.pop();
            }
			
            if(s.size()!=0){         
                cs=*(s.begin());
                s.erase(s.begin());
            }
            else{
                cs=n;
                n++;
            }
            q.push({lt, cs});       
            if(f==at){               
                return cs;
            }
        }
        return 0;
    }
};