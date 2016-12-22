#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 101;
struct Node{
	int weight;//数据域 
	vector<int> child;//指针域 
}node[maxn];//结点数组 
int N, M, S;//给定点数/边数/给定和 
int path[maxn];//记录路径 

bool cmp(int a, int b){
	return node[a].weight > node[b].weight;//按数据域权重值由大到小排序 
}
//index 为当前节点坐标值，numNode为递归层数，sum为当前权重和 
void DFS(int index, int numNode, int sum){
	 if(sum > S){  //权重和大于预定权重说明达不到要求返回； 
	 	return;
	 }
	 if(sum == S){//权重和达到要求 
	 	if(node[index].child.size() != 0){//判断是否为叶子节点，如果不是则返回 
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
	 //如果没有达到要求进行进一步递归， 
	 for(int i = 0; i < node[index].child.size(); i++){//枚举所有的子节点 
	 	int child = node[index].child[i];//结点index的第i的子结点编号 
		path[numNode] = child; //将结点child加到路径path末尾 
	 	DFS(child, numNode + 1, sum + node[child].weight);//递归进入下一层 
	 } 
}
int main(void){
	scanf("%d %d %d", &N, &M, &S);
	for(int i = 0; i < N; i++){
		scanf("%d", &node[i].weight);
	}
	int id, k, child;//定义为结点编号， 子结点个数， 子结点的值， 
	for(int i = 0; i < M; i++){
		scanf("%d%d", &id, &k);//结点编号。孩子个数 
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);//child为节点id的孩子 
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);//排序 
	} 
	path[0] = 0;
	DFS(0, 1, node[0].weight); //DFS求解 
	return 0; 
} 
