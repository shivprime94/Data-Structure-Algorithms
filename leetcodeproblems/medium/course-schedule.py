class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.adj=[None]*numCourses
        for i in range(numCourses):
            self.adj[i]=[]
        
        for i in prerequisites:
            self.adj[i[0]].append(i[1])
            
        self.visited=[0]*numCourses
        for i in range(numCourses):
            if self.visited[i]==0 and not self.dfs(i):
                return False
            
        return True
    
    def dfs(self,v):
        if self.visited[v]==1:
            return False
        
        self.visited[v]=1
        
        for i in self.adj[v]:
            if not self.dfs(i):
                return False
        
        self.visited[v]=2
        
        return True