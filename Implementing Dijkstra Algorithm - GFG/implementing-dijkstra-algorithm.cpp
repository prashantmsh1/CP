//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


const int N=1e5+10;
const int   INF=1e9+10;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > p;
        vector<int> vis(N,0);
        vector<int> dis(V,INF);
        p.push({0,S});
        dis[S]=0;
        while(!p.empty()){
            auto it=p.top();
            p.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]) continue;
            vis[node]=1;
            
            for(auto it:adj[node]){
                int child=it[0];
                int weight=it[1];
                if(dis[node]+weight<dis[child]){
                    dis[child]=dis[node]+weight;
                    p.push({dis[child],child});
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends