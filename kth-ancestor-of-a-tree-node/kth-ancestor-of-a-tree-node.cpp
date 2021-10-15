#define LIM 50005

class TreeAncestor {
public:
    
    int n, l, up[LIM][22];
    vector<int> adj[LIM];

    void dfs(int u, int p)
    {
        up[u][0] = p;

        for (int i = 1; i <= l; ++i)
        {
            if(up[u][i-1] == -1)
                up[u][i] = -1;
            else
                up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int x : adj[u])
        {
            if (x != p)
                dfs(x, u);
        }
    }

    void init(int root)
    {
        l = ceil(log2(n));

        dfs(root, -1);
    }
    
    TreeAncestor(int _n, vector<int>& parent) 
    {
        n = _n;
        
        for(int i=1; i<n; ++i)
        {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        init(0);
        
//         for(int i=0; i<n; ++i)
//         {
//             for(int j=0; j<2; ++j)
//                 cout << up[i][j] << " ";
            
//             cout << endl;
//         }
    }
    
    int getKthAncestor(int x, int k) 
    {
        for (int i = l; i >= 0; --i)
        {
            if (k >= (1 << i))
            {   
                x = up[x][i];
                k -= (1 << i);
                
                if(x == -1)
                    return x;
            }
        }

        return x;    
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */