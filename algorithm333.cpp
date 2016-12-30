#include<stdio.h>
const int N = 110;
int father[N];//存放父亲节点
bool isRoot[N];//记录每个结点是否作为某个集合的根节点
 
int find_Father(int x){//查找x所在集合的根节点
	int a = x;
	while(x != father[x]){
		x = father[x];
	} 
	//此时x为根节点
	//以下为路径压缩算法，可以不写
	while(a != father[a]){
		int temp = a;//找一个暂存变量保存a的值，防止a被覆盖掉 
		a = father[a];//a继续回溯父亲节点
		father[temp] = x; //将原先结点a的父亲改为根节点x 
	} 
	return x;//返回根节点 
}
void Union(int a, int b){//合并a和b所在的集合
	int faA = find_Father(a);
	int faB = find_Father(b);
	if(faA != faB){
		father[faA] = faB;
	} 
} 
void init(int n){//初始化father[i]为i，且flag[i]为false
	for(int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = false;
	} 
}
int main(void){
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	init(n);//要记得初始化 
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b); 
		Union(a, b);//合并a和b所在的集合 
	}
	for(int i = 1; i <= n; i++){
		isRoot[find_Father(i)]= true; //i的根节点是findFather[i] 
	} 
	int ans = 0;//记录集合数目
	for(int i = 1; i <= n; i++){
		ans += isRoot[i];
	} 
	printf("%d\n", ans);
	return 0;
	
}
