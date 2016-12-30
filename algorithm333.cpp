#include<stdio.h>
const int N = 110;
int father[N];//��Ÿ��׽ڵ�
bool isRoot[N];//��¼ÿ������Ƿ���Ϊĳ�����ϵĸ��ڵ�
 
int find_Father(int x){//����x���ڼ��ϵĸ��ڵ�
	int a = x;
	while(x != father[x]){
		x = father[x];
	} 
	//��ʱxΪ���ڵ�
	//����Ϊ·��ѹ���㷨�����Բ�д
	while(a != father[a]){
		int temp = a;//��һ���ݴ��������a��ֵ����ֹa�����ǵ� 
		a = father[a];//a�������ݸ��׽ڵ�
		father[temp] = x; //��ԭ�Ƚ��a�ĸ��׸�Ϊ���ڵ�x 
	} 
	return x;//���ظ��ڵ� 
}
void Union(int a, int b){//�ϲ�a��b���ڵļ���
	int faA = find_Father(a);
	int faB = find_Father(b);
	if(faA != faB){
		father[faA] = faB;
	} 
} 
void init(int n){//��ʼ��father[i]Ϊi����flag[i]Ϊfalse
	for(int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = false;
	} 
}
int main(void){
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	init(n);//Ҫ�ǵó�ʼ�� 
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b); 
		Union(a, b);//�ϲ�a��b���ڵļ��� 
	}
	for(int i = 1; i <= n; i++){
		isRoot[find_Father(i)]= true; //i�ĸ��ڵ���findFather[i] 
	} 
	int ans = 0;//��¼������Ŀ
	for(int i = 1; i <= n; i++){
		ans += isRoot[i];
	} 
	printf("%d\n", ans);
	return 0;
	
}
