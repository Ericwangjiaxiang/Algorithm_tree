#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXV = 1010;
struct Node{
	int id;			//����� 
	int layer;		//����� 
}; 

vector<Node> Adj[MAXV];//ʹ���ڽӱ���ͼ
bool inq[MAXV] = {false};//�����Ƿ�������
int BFS(int s, int L){
	int NumFollow = 0;
	queue<Node> q;//�������q
	Node start;//������ʼ�ڵ�
	start.id = s;//��ʼ�ڵ���
	start.layer = 0;
	  
	 q.push(start);
	 inq[start.id] = true;
	while(!q.empty()){//ֻҪ���зǿ�
	 	Node topNode = q.front();
	 	 q.pop();//���׽�����
		 int u = topNode.id;//���׽��ı��
		 for(int i = 0; i < Adj[u].size(); i++){
		 	 Node next = Adj[u][i]; //��u�����ܵ���Ľ��next
			 next.layer = topNode.layer + 1;//next�Ĳ�ŵ��ڵ�ǰ����ż�1
			 if(inq[next.id] == false && next.layer <= L){
				q.push(next);//��next���
				inq[next.id] = true;
				numFollow++;//ת������һ 
			 } 
		 } 
	 } 
	 return numFollow;//����ת���� 
	  
}
int main(void){
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d%d", &n, &m);//�ڵ��������������
	for(int i = 1; i <= n; i++){
		user.id = i;//�û����Ϊi
		scanf("%d", &numFollow);//i���û���ע���û����
		Adj[idFollow].push_back(user);// 
	} 

	int numQuery, s;
	scanf("%d", &numQuery);//��ѯ����
	for(int i = 0; i < numQuery; i++){
		memset(inq, false, sizeof(inq));//inq�����ʼ��
		scanf("%d", &s);
		int numForward = BFS(s, L);//BFS,����ת����
		printf("%d\n", numForward);//���ת���� 
	} 
	return 0;
}

