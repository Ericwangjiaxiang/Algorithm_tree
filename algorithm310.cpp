#include<cstdio> 
struct node{
	int data;//������
	node *lchild;
	node *rchild;//ָ����	 
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
		root = newnode(x);		//�½��ڵ� 
		return;
	}
	
	if(root->data == x){			//����˽ڵ��Ѿ����ڷ��� 
		return;
	}else if(root->data > x){		//����ýڵ�С�ڸ��ڵ���ֵ������������� 
		insert(root->lchild, x);
	}else{							//����ýڵ���ڸ��ڵ㣬����������� 
		insert(root->rchild, x);
	}
}
void search(node* root, int x){
	if(root = NULL){//Ϊ����������ʧ��
		printf("search failed\n");
		return; 
	}
	
	if(x == root->data){//���ҳɹ����� 
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
