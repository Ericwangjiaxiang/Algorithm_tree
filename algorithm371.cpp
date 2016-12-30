int n;//记录顶点个数 
const int MAXV = 1010;//maxv为最大顶点个数 
const int INF = 1000000000;
int G[MAXV][MAXV];//邻接矩阵
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV] = {false};//标记数组，用于标记数组有没有访问过,等于true时，表示已经访问过
void Dijkstra(int s){//s为起点 
	d[s] = 0;		 //起点s到达自身的距离为0 
	fill(d, d + MAXV, INF); //fill函数将整个d数组赋值为INF 

	for(int i = 0; i < n; i++){
		int u = -1;
		MIN = INF; 
		for(int j = 0; j < n; j++){//找到未访问的顶点中,d[]值为最小的 
			
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j] 
			} 
		}
		if(u = -1){
			return;//u = -1，说明找不到小于INF的d[u]，说明起点s与剩余顶点都不联通了，程序结束 
		} else{
			vis[u] = true;//标记u为已访问 
			d[u] = MIN;//可省略，用不到 
		} 
		
		for(int v = 0; v < n; v++){
			//如果v未访问 && u 能到达v && 以u为中介点可以使d[v]最优 
			if(vis[v] = false && d[u] + G[u][v] < d[v] && G[u][v] != INF ){
				d[v] = d[u] + G[u][v];
			}
		} 
	}
} 

 

