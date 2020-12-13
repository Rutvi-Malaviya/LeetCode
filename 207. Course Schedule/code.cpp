class Solution {
public:
    
    bool hasCycle(map<int, vector<int>> &graph, vector<bool> &visited, int node){
        if(visited[node]) return true;
        
        visited[node] = true;
        for(int i: graph[node]){
            if(hasCycle(graph, visited, i)) return true;
            visited[i] = false;
        }
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> graph;
        
        for(auto v: prerequisites){
            graph[v[0]].push_back(v[1]);
        }
        
        vector<bool> visited(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(hasCycle(graph, visited, i)) return false;
            visited[i]=false;
        }
        
        return true;
        
    }
};
