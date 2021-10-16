int dfs(int node, int c, int col[], vector<vector<int>> &adj){
    col[node]=c;
    for(int child:adj[node]){
        // if colour of child is same as that of node return 0
        if(col[child]==c) return 0;
        // col[child]==-1 means child is not visited
        if(col[child]==-1 && dfs(child, (c^1), col, adj)==0) return 0;
    }
    return 1;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    for(auto v:B){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    int col[A+1];
    memset(col, -1, sizeof(col));
    for(int i=1; i<=A; i++){
        if(col[i]==-1 && dfs(i, 0, col, adj)==0) return 0;
    }
    return 1;
}
