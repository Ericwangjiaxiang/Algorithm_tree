#include<stdio.h>
#include<vector>
using namespace std;

struct node{
	int data;//数据域 
	node* lchild;//指针域 
	node* rchild;
}; 


int main(void){
	int n, data;
	vector<int> origin, pre, prem, post, postm;
	node* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		origin.push_back(data);//将数据入栈 
		insert(root, data);		//将data插入二叉树 
	}
	preorder(root, pre);//求先序
	preorderMirror(root, prem);//求先序镜像
	postorder(root, post);//求后序
	postorderMirror(root, postm);//求后序镜像
	if(origin == pre){
		pirntf("YES\n");
		for(int i = 0; i < post; i++){

		}
	} 

}
