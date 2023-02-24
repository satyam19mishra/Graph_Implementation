#include<bits/stdc++.h> 
using namespace std;

class graph{
public:
	int v;
	int e;
	int **edges;

	graph(int v,int e){
		this->v = v;
		this->e = e;

		edges = new int*[this->v];

		for(int i=0;i<v;i++){
			edges[i] = new int[v];
			for(int j=0;j<v;j++){
				edges[i][j] = 0;
			}
		}
	}

	void add_edges(int x, int y){
		edges[x][y]=1;
		edges[y][x]=1;
	}

	void call_dfs(int node,bool *vis){
		vis[node] = true;
		cout <<  node << " ";
		for(int i=0;i<v;i++){
			if(!vis[i] and edges[i][node]==1){
				call_dfs(i,vis);
			}
		}
	}
	void print_dfs(){
		bool *visited = new bool[v];

		for(int i=0;i<v;i++){
			visited[i] = false;
		}
		call_dfs(0,visited);
	}
	void call_bfs(int node,bool *vis){
		vis[node] = true;
		queue<int> q;
		q.push(node);
		while(!q.empty()){
			int curr_node = q.front();
			q.pop();
			cout << curr_node << " ";
			for(int i=0;i<v;i++){
				if(edges[i][node]==1 and !vis[i]){
					vis[i] = true;
					q.push(i);
				}
			}
		}
	}
	void print_bfs(){
		bool *visited = new bool[v];
		for(int i=0;i<v;i++){
			visited[i] = false;
		}
		call_bfs(0,visited);
	}

};

int main(){
	int n ,e;
	cin >> n >> e;
	graph s(n,e);
	for(int i=0;i<e;i++){
		int u,v;
		cin >> u >> v;
		s.add_edges(u,v);
	}
	cout << " the dfs traverse of the graph is " << endl;
	s.print_dfs() ;
	cout << endl;
	cout << " the bfs traverse of the graph is " << endl;
	s.print_bfs();
	return 0;
}