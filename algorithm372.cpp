struct Node{
	int v;//vΪ�ߵ�Ŀ�궥�� 
	int dis;//disΪ��Ȩ 
};
const int MAXV  10010;
const int INF 10010;
vector<Node> Adj[MAXV];
int s = 0;//�������
int n;//������ 
int d[MAXV]; 
fill(d, d + MAXV, INF);
bool vis[MAXV] = {false}; 
for(int i = 0; i < n; i++){
	int u = -1;//����u = -1�����жϣ�Ѱ�Ҵ����s��u�ı�Ȩֵ��С�� 
	int MIN = INF;
	for(int j = 0; j < n; j++){
		if(vis[j] = false && d[j] < MIN){//Ѱ������δ���ʱ�Ȩ��С��u 
			u = j;
			MIN = d[j];
		}
	} 
	if(u == -1){//����Ҳ�������Ҫ���uֵ��˵���Ѿ������ڴ�s��uδ���ʵ��ֱ��;����Ҳ��s��u����ͨ 
		return; 
	}else{
		vis[u] = true;//˵��u�Ѿ����� 
	}
	//�����u��Ϊ�м̵㿪ʼѰ�ң���û��ʹ�Ѿ����ʹ���;������ 
	for(int j = 0; j < Adj[u].size(); j++){
		int v = Adj[u][j].v;//ͨ���ڽӱ�ֱ�ӻ��u�ܵ���Ķ���v
		if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
			//���vδ���� && ��u Ϊ�н�����ʹd[v]����
			d[v] = d[u] + Adj[u][j].dis;//�Ż�d[v] 
		} 
	} 
}
