#include <iostream>
using namespace std;

struct AVLnode
{
	AVLnode *left, *right;
	int ht;
	string keyword, meaning;
};

class AVLTree
{
	public:
		AVLnode *root;
		AVLTree()
		{
			root = NULL;
		}
		
		AVLnode* insert(AVLnode *root, string newkey, string mean);
		int height(AVLnode *);
		AVLnode *LL(AVLnode *);
		AVLnode *RR(AVLnode *);
		AVLnode *LR(AVLnode *);
		AVLnode *RL(AVLnode *);
		AVLnode *rotateleft(AVLnode *);
		AVLnode *rotateright(AVLnode *);
		void inorder(AVLnode *);
		int BF(AVLnode *);
		void create();
};

void AVLTree::create()
{
	char ch;
	string x, y;
	do {
		cout<<"Enter word: ";
		cin>>x;
		cout<<"Enter meaning: ";
		cin>>y;
		root = insert(root, x, y);
		cout<<"Do you want to insert more words?(y/n)";
		cin>>ch;
	}while(ch == 'y');
}

AVLnode* AVLTree::insert(AVLnode *root, string newkey, string mean)
{
	AVLnode *curr;
	int lh, rh;
	if(root == NULL)
	{
		curr = new AVLnode;
		curr->keyword = newkey;
		curr->meaning = mean;
		curr->ht = 0;
		curr->left = NULL;
		curr->right = NULL;
		root = curr;
	}
	else
	{
		if(newkey<root ->keyword)
		{
			root->left = insert(root->left, newkey, mean);
			if(BF(root) == 2)
			{
				if(newkey<root->left->keyword)
				{
					root = LL(root);
				}
				else
				{
					root = LR(root);
				}
			}
		}
		
		else
		{
			if(newkey>root->keyword)
			{
				root->right = insert(root->right, newkey, mean);
				if(BF(root) == -2)
				{
					if(newkey > root->right->keyword)
					{
						root = RR(root);
					}
					else
					{
						root = RL(root);
					}
				}
			}
			else
			{
				cout<<"Duplicate."<<endl;
			}
		}
	}
		root->ht = height(root);
		return root;
}
		
AVLnode * AVLTree::rotateright(AVLnode *x)
{
	AVLnode *y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

AVLnode * AVLTree::rotateleft(AVLnode *x)
{
	AVLnode *y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

AVLnode * AVLTree::LL(AVLnode *T)
{
	cout<<"\nin LL rotation\n";
	T = rotateright(T);
	return T;
}

AVLnode * AVLTree::LR(AVLnode *T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);
	return T;
}

AVLnode * AVLTree::RR(AVLnode *T)
{
	cout<<"\nin RR rotation\n";
	T = rotateleft(T);
	return T;
}

AVLnode * AVLTree::RL(AVLnode *T)
{
	T->left = rotateright(T->left);
	T = rotateleft(T);
	return T;
}

int AVLTree::height(AVLnode *T)
{
	int hl, hr;
	if(T==NULL)
	{
		return 0;
	}
	
	if(T->left == NULL && T->right == NULL)
	{
		return 0;
	}
	
	hl = height(T->left);
	hr = height(T->right);
	if(hl<hr)
	{
		return hr+1;
	}
	else
	{
		return hl+1;
	}
}

int AVLTree::BF(AVLnode *T)
{
	int r, l;
	r = height(T->right);
	l = height(T->left);
	return l-r;
}

void AVLTree::inorder(AVLnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->keyword<<" - "<<root->meaning<<endl;
		inorder(root->right);
	}
}

int main()
{
	AVLTree a;
	int ch = 0;
	while(ch != 4)
	{
		cout<<"--------------------------------------------------------------"<<endl;
		cout<<"1. Add words to dictionary"<<endl;
		cout<<"2. Show data"<<endl;
		cout<<"3. Clear all data"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				a.create();
				break;
			case 2:
				if(a.root == NULL)
				{
					cout<<"Dictionary is empty."<<endl;
				}
				else
				{
					a.inorder(a.root);
				}
				break;
			case 3:
				a.root = NULL;
				cout<<"All data cleared."<<endl;
				break;
			case 4:
				cout<<"Exiting...."<<endl;
				break;
			default:
				cout<<"Invalid choice."<<endl;
				break;
		}
	}
}
