#include<stdio.h>
#include<vector>
using namespace std;

struct node{
	int data;//������ 
	node* lchild;//ָ���� 
	node* rchild;
}; 


int main(void){
	int n, data;
	vector<int> origin, pre, prem, post, postm;
	node* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		origin.push_back(data);//��������ջ 
		insert(root, data);		//��data��������� 
	}
	preorder(root, pre);//������
	preorderMirror(root, prem);//��������
	postorder(root, post);//�����
	postorderMirror(root, postm);//�������
	if(origin == pre){
		pirntf("YES\n");
		for(int i = 0; i < post; i++){

		}
	} 

}
