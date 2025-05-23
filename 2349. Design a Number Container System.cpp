class NumberContainers {
    public:
     map<int,int> hm;
        map<int,set<int>> mp;
    
        
        
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            
         if(hm.count(index)!=0){
             int a = hm[index];
             
           
            set<int>::iterator it;
             
             it = mp[a].find(index);
             mp[a].erase(it);
           
             
            
             hm[index]= number;
             
             if(mp.count(number)!=0 && mp[number].size()!=0){
                 
                 mp[number].insert(index);
            
             }
             else{
                 set<int> st ;
                 st.insert(index);
                 mp[number] = st;
             }
             
         }
            else{
                
                hm[index] = number;
                   if(mp.count(number)!=0){
                 
                 mp[number].insert(index);
            
             }
             else{
                 set<int> st ;
                 st.insert(index);
                 mp[number] = st;
             }
                
            }
            
            
            
        }
        
        
        
        int find(int number) {
            
           if(mp.count(number)!=0 && mp[number].size()!=0){
               
               return *mp[number].begin();
           }
            
            return -1;
    
        }
    };
    