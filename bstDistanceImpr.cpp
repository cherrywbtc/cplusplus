//sum root to leaf numbers

#include<map>
#include<iostream>
#include<vector>
#include <string>
#include <cmath>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x):val(x), left(NULL), right(NULL), parent(NULL){}
};
class BST{
private:

TreeNode *root;

public:
TreeNode* insert(TreeNode * &curr, TreeNode* parr, int value);

void buildTree(int *values, int n, TreeNode * & n1, TreeNode * &n2, int node1, int node2);
int getDepth(TreeNode *curr);
void printTree(TreeNode *curr);
void printMyTree();
};

void BST::buildTree(int *values, int n, TreeNode * & n1, TreeNode * &n2, int node1, int node2){
	root = new TreeNode(values[0]);
	TreeNode *curr=root;
    for (int i = 1; i<n; i++){
        TreeNode *tmp= insert(curr, NULL, values[i]);
        if (tmp->val==node1)
            n1=tmp;
        if (tmp->val==node2)
            n2=tmp;
    }
    return;
}

TreeNode* BST::insert(TreeNode * &curr, TreeNode* parr, int value){
    if (curr==NULL){
        curr = new TreeNode(value);
        curr->parent = parr;
        return curr;
    }
    if(value>root->val)
        return insert(curr->right, curr, value);
    else
        return insert(curr->left, curr, value);
}

int BST::getDepth(TreeNode *curr){
	int h = 0;
    while(curr!=root){
        h++;
        curr = curr->parent;
    }
    return h;
}

void BST::printTree(TreeNode *curr){
	if (curr){
		cout<<curr->val<<endl;
		printTree(curr->left); 
		printTree(curr->right);
	}
	cout<<"NULL"<<endl;
	return;
}

void BST::printMyTree(){
	if (root){
		printTree(root);
	}
	return;
}

int bstDistance(int *values, int n, int node1, int node2)
{
	if (n==0) return -1;
	TreeNode *n1;
	TreeNode *n2;
	BST mytree;
	mytree.buildTree(values, n, n1, n2, node1, node2);
	//mytree.printMyTree();
	int count = 0;
	if (!n1||!n2) return -1;
	int h1 = 0;
	int h2 = 0;
	h1 = mytree.getDepth(n1);
	h2 = mytree.getDepth(n2);
	if (h1>h2){
	    while(h1>h2){
	        n1=n1->parent;
	        count++;
	        h1--;
	    }
	}
	else if (h2>h1){
	    while(h2>h1){
	        n2=n2->parent;
	        count++;
	        h2--;
	    }
	}
	while(n1!=n2){
	    count+=2;
	    n1=n1->parent;
	    n2=n2->parent;
	}
	return count;
}

int main(){
    int test[]={5,6,3,1,2,4};
    cout<< bstDistance(test, 6, 2, 4)<<endl;
}

