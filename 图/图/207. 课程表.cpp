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

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> course(numCourses);
//         vector<int> indegree(numCourses, 0);
//         for(auto& pre : prerequisites)
//         {
//             course[pre[1]].emplace_back(pre[0]);
//         }

//         auto dfs = [&](this auto&& dfs, int i) -> bool{
//             //正在访问
//             indegree[i] = 1;
//             for(auto c : course[i])
//             {
//                 if(indegree[c] == 1 || (indegree[c] == 0 && dfs(c)))
//                 {
//                     //找到环了
//                     return true;
//                 }
//             }
//             indegree[i] = 2;
//             return false;
//         };

//         for(int i = 0; i < numCourses; i++)
//         {
//             if(indegree[i] == 0 && dfs(i))
//                 return false;
//         }
//         return true;
//     }
// };