int n;//��¼������� 
const int MAXV = 1010;//maxvΪ��󶥵���� 
const int INF = 1000000000;
int G[MAXV][MAXV];//�ڽӾ���
int d[MAXV];//��㵽���������·������
bool vis[MAXV] = {false};//������飬���ڱ��������û�з��ʹ�,����trueʱ����ʾ�Ѿ����ʹ�
void Dijkstra(int s){//sΪ��� 
	d[s] = 0;		 //���s��������ľ���Ϊ0 
	fill(d, d + MAXV, INF); //fill����������d���鸳ֵΪINF 

	for(int i = 0; i < n; i++){
		int u = -1;
		MIN = INF; 
		for(int j = 0; j < n; j++){//�ҵ�δ���ʵĶ�����,d[]ֵΪ��С�� 
			
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j] 
			} 
		}
		if(u = -1){
			return;//u = -1��˵���Ҳ���С��INF��d[u]��˵�����s��ʣ�ඥ�㶼����ͨ�ˣ�������� 
		} else{
			vis[u] = true;//���uΪ�ѷ��� 
			d[u] = MIN;//��ʡ�ԣ��ò��� 
		} 
		
		for(int v = 0; v < n; v++){
			//���vδ���� && u �ܵ���v && ��uΪ�н�����ʹd[v]���� 
			if(vis[v] = false && d[u] + G[u][v] < d[v] && G[u][v] != INF ){
				d[v] = d[u] + G[u][v];
			}
		} 
	}
} 

 

