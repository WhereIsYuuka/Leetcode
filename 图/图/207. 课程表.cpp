class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            numCourses--;
            for(auto it : graph[cur])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return numCourses == 0;
    }
};