#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXV = 1010;
struct Node{
	int id;			//结点编号 
	int layer;		//结点层号 
}; 

vector<Node> Adj[MAXV];//使用邻接表储存图
bool inq[MAXV] = {false};//顶点是否加入队列
int BFS(int s, int L){
	int NumFollow = 0;
	queue<Node> q;//定义队列q
	Node start;//定义起始节点
	start.id = s;//起始节点编号
	start.layer = 0;
	  
	 q.push(start);
	 inq[start.id] = true;
	while(!q.empty()){//只要队列非空
	 	Node topNode = q.front();
	 	 q.pop();//队首结点出队
		 int u = topNode.id;//队首结点的编号
		 for(int i = 0; i < Adj[u].size(); i++){
		 	 Node next = Adj[u][i]; //从u出发能到达的结点next
			 next.layer = topNode.layer + 1;//next的层号等于当前结点层号加1
			 if(inq[next.id] == false && next.layer <= L){
				q.push(next);//将next入队
				inq[next.id] = true;
				numFollow++;//转发数加一 
			 } 
		 } 
	 } 
	 return numFollow;//返回转发数 
	  
}
int main(void){
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d%d", &n, &m);//节点个数，层数上限
	for(int i = 1; i <= n; i++){
		user.id = i;//用户编号为i
		scanf("%d", &numFollow);//i号用户关注的用户编号
		Adj[idFollow].push_back(user);// 
	} 

	int numQuery, s;
	scanf("%d", &numQuery);//查询个数
	for(int i = 0; i < numQuery; i++){
		memset(inq, false, sizeof(inq));//inq数组初始化
		scanf("%d", &s);
		int numForward = BFS(s, L);//BFS,返回转发数
		printf("%d\n", numForward);//输出转发数 
	} 
	return 0;
}

