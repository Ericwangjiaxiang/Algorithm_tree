#include<cstdio> 
struct node{
	int data;//数据域
	node *lchild;
	node *rchild;//指针域	 
};
int n;
node* newnode(int x){
	node* Node = new node;//or node* Node = (node *)malloc(sizeof(node))
	Node->data = x;
	Node->lchild = NULL;
	Node->rchild = NULL;
	return Node;
} 
void insert(node* &root, x){
	if(root == NULL){
		root = newnode(x);		//新建节点 
		return;
	}
	
	if(root->data == x){			//如果此节点已经存在返回 
		return;
	}else if(root->data > x){		//如果该节点小于根节点数值，则插入左子树 
		insert(root->lchild, x);
	}else{							//如果该节点大于根节点，则插入右子树 
		insert(root->rchild, x);
	}
}
void search(node* root, int x){
	if(root = NULL){//为空树，查找失败
		printf("search failed\n");
		return; 
	}
	
	if(x == root->data){//查找成功访问 
		printf("%d ", root->data);
	}else if(x < root->data){
		search(root->lchild, x);
	} else(x > root->data){
		search(root->rchild, x);
	}
}
int main(void){
	node* root = NULL;
 	scanf("%d", &n);
 	int data[n];
 	for(int i = 0; i < n; i++){
 		scanf("%d", &data[i]);
	 }
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	} 
	for(int i = 0; i < n; i += 2){
		search(root, data[i]);
	}
	
	return 0;
}
