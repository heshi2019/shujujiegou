#include "stdio.h"
#include "stdlib.h"
int count = 0;
typedef struct BiTNode
{
	char data;//节点保存的数据
	struct BiTNode* lchild, * rchild;//指向左子树和右子树的指针
}BiTNode, * BiTree;//二叉树的节点类型
//先序遍历二叉树
int PreOrderTraverse(BiTree Tree)
{
	if (Tree != NULL) {
		printf("%c", Tree->data);
		PreOrderTraverse(Tree->lchild);
		PreOrderTraverse(Tree->rchild);
	}
	return 1;
}
//中序遍历二叉树
int InOrderTraverse(BiTree Tree)
{
	if (Tree != NULL) {
		InOrderTraverse(Tree->lchild);
		printf("%c", Tree->data);
		InOrderTraverse(Tree->rchild);
	}
	return 1;
}
//后序遍历二叉树
int PostOrderTraverse(BiTree Tree)
{
	if (Tree != NULL) {
		PostOrderTraverse(Tree->lchild);
		PostOrderTraverse(Tree->rchild);
		printf("%c", Tree->data);
	}
	return 1;
}
//叶子节点数
int countleaf(BiTNode *Tree) {
	
	if (Tree == NULL)
		return count;
	
	 if (Tree->lchild == NULL && Tree->rchild == NULL) //如果它的左右孩子都为空就计数
		count=count+1;
	countleaf(Tree->lchild);
	countleaf(Tree->rchild);
	
	return count;

}
//二叉树深度
int treeDepth(BiTree Tree) {
	int Depth = 0;
	if (Tree == NULL)
		return 0;
	else
	{
		int Left = treeDepth(Tree->lchild);
		int Right = treeDepth(Tree->rchild);
		Depth= Left>=Right ? Left + 1 : Right + 1;

	}
	return Depth;

}
//创建二叉树
void CreateBiTree(BiTree& T)
{
	char ch;
	scanf("%c", &ch);
	if ('#' == ch)
		T = NULL;
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

int main()
{
	BiTree T = NULL;
	int a, b;
	printf("请按照先序遍历顺序输入二叉树(#代表为空)\n");
	CreateBiTree(T);
	printf("\n先序遍历二叉树结果为：\n");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树结果为：\n");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树结果为：\n");
	PostOrderTraverse(T);
	printf("\n");
	printf("二叉树的叶子节点数：\n");
	a=countleaf(T);
	printf("%d\n", a);
	printf("二叉树的深度：\n");
	b=treeDepth(T);
	printf("%d", b);
	printf("\n");
	return 0;
}



