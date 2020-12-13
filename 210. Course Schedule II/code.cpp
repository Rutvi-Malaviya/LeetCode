class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> graph;
        map<int, int> incoming;
        
        for(auto v: prerequisites){
            graph[v[1]].push_back(v[0]);
            incoming[v[0]]++;
        } 
        
        vector<int> ans;
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(incoming[i]==0) q.push(i);
        }
        
        while(q.size()){
            int c = q.front(); q.pop();
            
            ans.push_back(c);
            
            for(int i: graph[c]){
                incoming[i]--;
                if(incoming[i]==0) q.push(i);
            }
        }
        
        if(ans.size()<numCourses) return {};
        return ans;
        
    }
};
