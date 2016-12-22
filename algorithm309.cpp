#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 101;
struct Node{
	int weight;//������ 
	vector<int> child;//ָ���� 
}node[maxn];//������� 
int N, M, S;//��������/����/������ 
int path[maxn];//��¼·�� 

bool cmp(int a, int b){
	return node[a].weight > node[b].weight;//��������Ȩ��ֵ�ɴ�С���� 
}
//index Ϊ��ǰ�ڵ�����ֵ��numNodeΪ�ݹ������sumΪ��ǰȨ�غ� 
void DFS(int index, int numNode, int sum){
	 if(sum > S){  //Ȩ�غʹ���Ԥ��Ȩ��˵���ﲻ��Ҫ�󷵻أ� 
	 	return;
	 }
	 if(sum == S){//Ȩ�غʹﵽҪ�� 
	 	if(node[index].child.size() != 0){//�ж��Ƿ�ΪҶ�ӽڵ㣬��������򷵻� 
	 		return;
		 }else{
		 	for(int i = 0; i < numNode; i++){
		 		printf("%d", node[path[i]].weight);
		 		if(i < numNode - 1){
		 			printf(" ");
				 }else{
				 	printf("\n");
				 }
			 }
			 return; 
		 }
	 }
	 //���û�дﵽҪ����н�һ���ݹ飬 
	 for(int i = 0; i < node[index].child.size(); i++){//ö�����е��ӽڵ� 
	 	int child = node[index].child[i];//���index�ĵ�i���ӽ���� 
		path[numNode] = child; //�����child�ӵ�·��pathĩβ 
	 	DFS(child, numNode + 1, sum + node[child].weight);//�ݹ������һ�� 
	 } 
}
int main(void){
	scanf("%d %d %d", &N, &M, &S);
	for(int i = 0; i < N; i++){
		scanf("%d", &node[i].weight);
	}
	int id, k, child;//����Ϊ����ţ� �ӽ������� �ӽ���ֵ�� 
	for(int i = 0; i < M; i++){
		scanf("%d%d", &id, &k);//����š����Ӹ��� 
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);//childΪ�ڵ�id�ĺ��� 
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);//���� 
	} 
	path[0] = 0;
	DFS(0, 1, node[0].weight); //DFS��� 
	return 0; 
} 
