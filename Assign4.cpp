#include <iostream>
using namespace std;

struct node
{
	int data;
	node *right, *left;
};

class bst
{
	public:
		node *root;
		int minarray[100];
		int minval;
		int i;
		int n;
		bool searchflag;
		bst()
		{
			root = NULL;
			i = 0;
			n = 0;
			minval = 10000;
			searchflag = false;
		}
		void insert(int key);
		int longestpath(node *root);
		//void swap(node* root);
		void search(node *root, int key);
		void display(node *root);
		void min(node *root);
};

void bst::insert(int key)
{
	node* temp, *curr;
	bool flag = false;
	temp = root;
	curr = new node;
	curr->data = key;
	curr->right = NULL;
	curr->left = NULL;
	if(temp == NULL)
	{
		root = curr;
		n++;
	}
	else
	{
		while(flag == false)
		{
			if(temp->data > key)
			{
				if(temp->left == NULL)
				{
					temp->left = curr;
					cout<<"Inserted successfully."<<endl;
					n++;
					flag = true;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = curr;
					cout<<"Inserted successfully."<<endl;
					flag = true;
					n++;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}

int bst::longestpath(node* root){
	if (root == NULL) {
	   return 0;
	}
	int leftPath = longestpath(root->left);
	int rightPath = longestpath(root->right);
	return max(leftPath, rightPath) + 1;
}

/*void bst::swap(node* root) {
	if (root == NULL)
    {
        return;
    }
    swap(root->left);
    swap(root->right);

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}*/

void bst::display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<root->data<<" - ";
		display(root->right);
	}
}

void bst::search(node *root, int key)
{
	if(root!=NULL)
	{
		search(root->left, key);
		if(root->data == key)
		{
			cout<<"key found."<<endl;
			searchflag = true;
		}
		search(root->right, key);
	}
}
void bst::min(node *root)
{
	if(root!=NULL)
	{
		min(root->left);
		if(root->data < minval)
		{
			minval = root->data;
		}
		min(root->right);
	}
}

int main()
{
	bst a;
	int x;
	cout<<"Enter root node value: ";
	cin>>x;
	a.insert(x);
	int choice = 0;
	while(choice!=7)
	{
		cout<<"1. Add node"<<endl;
		cout<<"2. Display inorder"<<endl;
		cout<<"3. Nodes in longest path"<<endl;
		cout<<"4. Minimum value in tree"<<endl;
		//cout<<"5. Swap "<<endl;
		cout<<"6. Search"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"Enter node value: ";
					cin>>x;
					a.insert(x);
					break;
				}
			case 2:
				{
					a.display(a.root);
					cout<<endl;
					break;
				}
			case 3:
				{
					cout<<"Longest Path in tree: "<<a.longestpath(a.root)<<endl;
					break;
				}
			case 4:
				{
					a.min(a.root);
					cout<<"Minimum value in tree: "<<a.minval<<endl;
					a.minval = 10000;
					break;
				}
			/*case 5:
				{
					a.swap(a.root);
					break;
				}*/
			case 6:
				{
					cout<<"Enter value to search: ";
					cin>>x;
					a.search(a.root, x);
					if(a.searchflag == false)
					{
						cout<<"Value not found."<<endl;
					}
					else
					{
						a.searchflag = false;
					}
					break;
				}
			case 7:
				{
					cout<<"Exiting..."<<endl;
					break;
				}
			default:
				{
					cout<<"Invalid Choice."<<endl;
					break;
				}
		}
	}
	
}
			
			
			
			
			
			
			
			
			
			
			
			
	
