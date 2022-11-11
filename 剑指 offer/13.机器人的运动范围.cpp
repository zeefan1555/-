class Solution {
private:
    vector<vector<int>> vis;
    int ans;
    int Sumxy(int a){
        int ret = 0;
        while(a!=0){
            ret += a%10;
            a=a/10;
        }
        return ret;
    }

    int dfs(int x, int y, int k, int m, int n){
        // ❓为啥要=号呢
        if( x >= m || y >= n||Sumxy(x)+Sumxy(y) > k || vis[x][y] == 1) return 0;// 1️⃣越界 2️⃣超过 K3️⃣被访问过
        vis[x][y] = 1; 
        // 💡机器人只会往右走或者往下走
        return 1+dfs(x+1, y, k, m, n) + dfs(x, y+1, k, m, n);// 如果能走到递归会自然加 1
        
    }

public:
           
    int movingCount(int m, int n, int k) {
        vis = vector<vector<int>>(m,vector<int>(n)); 
        return dfs(0,0,k, m, n);

    }
};