class Solution {

    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> graph(numCourses);
            vector<int> inside(numCourses);
            vector<int> res;
            for(auto p : prerequisites)
            {
                graph[p[1]].push_back(p[0]);
                inside[p[0]]++;
            }
            queue<int> q;
            for(int i = 0; i < numCourses; i++)
            {
                if(inside[i] == 0)
                    q.push(i);
            }
            while(!q.empty())
            {
                int tmp = q.front();
                q.pop();
                res.push_back(tmp);
                numCourses--;
                for(auto it : graph[tmp])
                {
                    inside[it]--;
                    if(inside[it] == 0)
                        q.push(it);
                }
            }
            if(numCourses == 0)
                return res;
            else
                return {};
        }
    }; 