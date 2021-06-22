#include <stdio.h>
int v1, v2;
struct Tree {
	int lChild;
	int rChild;
	int root;
	int weight;
}tree[130];
void min(Tree tree[], int k) {
	for (int i = 0; i < k; ++i) {
		if (tree[i].root == -1) {
			v1 = i;
			break;
		}
	}
	for (int i = v1 + 1; i < k; i++){
		if (tree[i].root == -1 && tree[i].weight < tree[v1].weight)
			v1 = i;
	}
	for (int i = 0; i < k; i++){
		if (tree[i].root == -1 && v1 != i) {
			v2 = i;
			break;
		}
	}
	for (int i = v2 + 1; i < k; i++){
		if (tree[i].root == -1 && tree[i].weight < tree[v2].weight&&i != v1)
			v2 = i;
	}
}
void Huffman(Tree tree[], int a[],int n,int k) {
	for (int i = 0; i < k; i++){
		tree[i].root = -1;
		tree[i].lChild = -1;
		tree[i].rChild = -1;
	}
	for (int i = 0; i < n; i++)
		tree[i].weight = a[i];
	for (int i = n; i < k; i++) {
		min(tree, i);
		tree[i].weight = tree[v1].weight + tree[v2].weight;
		tree[v1].root = i;
		tree[v2].root = i;
		tree[i].lChild = v1;
		tree[i].rChild = v2;
	}
}
int main(){
	int i;
	int a[] = { 5,5,10,10,10,15,20,25 };
	Huffman(tree, a, 8, 15);
	printf("weight root lChild rChild\n");
	for (i = 0; i < 15; ++i) {
		printf("%6d", tree[i].weight);
		printf("%6d", tree[i].root);
		printf("%6d", tree[i].lChild);
		printf("%6d\n", tree[i].rChild);
	}
}
