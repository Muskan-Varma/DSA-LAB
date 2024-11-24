#include <iostream>
#include <string>
using namespace std;

struct node
{
	string key, value;
	node *right, *left;
};

class bst
{
	public:
		node *root;
		int i;
		int n;
		bool searchflag;
		bst()
		{
			root = NULL;
			i = 0;
			n = 0;
			searchflag = false;
		}
		void insert(string key, string value);
		void search(node *root, string key);
		void ascending(node *root);
		void descending(node *root);
		void update(node* root, string key);
};

void bst::insert(string key, string value)
{
	node* temp, *curr;
	bool flag = false;
	temp = root;
	curr = new node;
	curr->key = key;
	curr->value = value;
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
			if(temp->key > key)
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

void bst::ascending(node *root)
{
	if(root!=NULL)
	{
		ascending(root->left);
		cout<<root->key<<" - "<<root->value<<endl;
		ascending(root->right);
	}
}

void bst::descending(node *root)
{
	if(root!=NULL)
	{
		descending(root->right);
		cout<<root->key<<" - "<<root->value<<endl;
		descending(root->left);
	}
}

void bst::search(node *root, string key)
{
	if(root!=NULL)
	{
		search(root->left, key);
		if(root->key == key)
		{
			cout<<"Word "<<root->key<<" has meaning "<<root->value<<endl;
			searchflag = true;
		}
		search(root->right, key);
	}
}

void bst::update(node *root, string key)
{
	if(root!=NULL)
	{
		update(root->left, key);
		if(root->key == key)
		{
			string value;
			cout<<"Enter updated meaning: ";
			cin>>value;
			root->value = value;
			cout<<"Meaning updated successfully."<<endl;
			searchflag = true;
		}
		update(root->right, key);
	}
}

int main()
{
	bst a;
	string x, y;
	cout<<"Enter word: ";
	cin>>x;
	cout<<"Enter Meaning: ";
	cin>>y;
	a.insert(x,y);
	int choice = 0;
	while(choice!=6)
	{
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
		cout<<"1. Add node"<<endl;
		cout<<"2. Display in ascending order"<<endl;
		cout<<"3. Display in descending order"<<endl;
		cout<<"4. Update meaning"<<endl;
		cout<<"5. Search"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
		switch(choice)
		{
			case 1:
				{
					cout<<"Enter word: ";
					cin>>x;
					cout<<"Enter meaning: ";
					cin>>y;
					a.insert(x,y);
					break;
				}
			case 2:
				{
					a.ascending(a.root);
					break;
				}
			case 3:
				{
					a.descending(a.root);
					break;
				}
			case 4:
				{
					a.searchflag = false;
					cout<<"Enter word whose meaning is to be updated: ";
					cin>>x;
					a.update(a.root, x);
					if(a.searchflag == false)
					{
						cout<<"word not found."<<endl;
					}
					break;
				}
			case 5:
				{
					a.searchflag = false;
					cout<<"Enter word to search: ";
					cin>>x;
					a.search(a.root, x);
					if(a.searchflag == false)
					{
						cout<<"word not found."<<endl;
					}
					else
					{
						a.searchflag = false;
					}
					break;
				}
			case 6:
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
