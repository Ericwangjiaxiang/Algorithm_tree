struct Node{
	int v;//v为边的目标顶点 
	int dis;//dis为边权 
};
const int MAXV  10010;
const int INF 10010;
vector<Node> Adj[MAXV];
int s = 0;//定义起点
int n;//顶点数 
int d[MAXV]; 
fill(d, d + MAXV, INF);
bool vis[MAXV] = {false}; 
for(int i = 0; i < n; i++){
	int u = -1;//定义u = -1用于判断，寻找从起点s到u的边权值最小点 
	int MIN = INF;
	for(int j = 0; j < n; j++){
		if(vis[j] = false && d[j] < MIN){//寻找满足未访问边权最小的u 
			u = j;
			MIN = d[j];
		}
	} 
	if(u == -1){//如果找不到满足要求的u值，说明已经不存在从s到u未访问点的直接途径，也即s和u不连通 
		return; 
	}else{
		vis[u] = true;//说明u已经访问 
	}
	//下面从u作为中继点开始寻找，有没有使已经访问过的途径更短 
	for(int j = 0; j < Adj[u].size(); j++){
		int v = Adj[u][j].v;//通过邻接表直接获得u能到达的顶点v
		if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
			//如果v未访问 && 以u 为中介点可以使d[v]更优
			d[v] = d[u] + Adj[u][j].dis;//优化d[v] 
		} 
	} 
}
