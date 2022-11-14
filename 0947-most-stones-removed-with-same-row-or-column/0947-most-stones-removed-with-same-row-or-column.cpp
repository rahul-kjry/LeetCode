class Solution {
	public:
	int findPar(vector<int> &parent,int node) {
		if(node == parent[node])return node;
		return parent[node] = findPar(parent,parent[node]);
	}
	void unite(vector<int>&rank,vector<int>&parent,int u,int v) {
		u = findPar(parent,u);
		v = findPar(parent,v);
		if(rank[u] < rank[v])parent[u] = v;
		else if(rank[u] > rank[v])parent[v] = u;
		else {
			parent[v] = u;
			rank[u]++;
		}
		return;
	}
public:
	int removeStones(vector<vector<int>>& stones)  {
		int n = stones.size();
		vector<int>parent(n),rank(n,0);
		for(int i = 0; i < n; ++i)parent[i] = i;
		for(int i = 0;i < n;i++) {
			for(int j = 0; j < n; j++) {
				if(i!=j && findPar(parent,i)!=findPar(parent,j) && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
					unite(rank,parent,i,j);
				}
			}
		}
		set<int>s(parent.begin(),parent.end());
		return n-s.size();
	}
};