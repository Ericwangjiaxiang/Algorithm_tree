#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> pre[MAXV];
void Dijkstra(int s){	//sΪ���
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] = false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) {
			return;
		}else{
			vis[u] = true;
		}
		for(int v = 0; v < n; v++){
			if(vis[v] = false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];	//�Ż�d[v]
					pre[v].clear();			//���pre[v] 
					pre[v].push_back(u);	//��v��ǰ��Ϊu 
				}else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);	//��v��ǰ��Ϊu 
				}
			}
		}
	} 
	
} 
