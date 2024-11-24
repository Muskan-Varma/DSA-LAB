#include <iostream>
#include <string.h>
using namespace std;

struct node
{
	string word;
	string mean;
	node *next;
};

class dict
{
	node *arr[26];
	public:
		dict()
		{
			int x = 97;
			for(int i = 0; i<26; i++)
			{
				arr[i] = new node;
				arr[i]->word = char(x);
				arr[i]->mean = " ";
				arr[i]->next = NULL;
				x++;
			}
		}
		void display();
		void search(string word);
		void insert(string word, string mean);
		void dlt(string word);
		int hash(string word)
		{
			int x = (int(word[0]) - 97);
			return x;
		}
};

void dict::insert(string word, string mean)
{
	node *temp, *curr;
	curr = new node;
	curr->word = word;
	curr->mean = mean;
	temp = arr[hash(word)];
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = curr;
	curr->next = NULL;
	cout<<"Added Successfully."<<endl;
}

void dict::display()
{
	node *temp;
	for(int i = 0; i<26; i++)
	{
		temp = arr[i];
		while(temp!=NULL)
		{
			cout<<temp->word<<" : "<<temp->mean<<" --- ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

void dict::search(string word)
{
	int x = hash(word);
	bool flag = false;
	node *temp = arr[x];
	while(temp->next != NULL)
	{
		if(temp->next->word == word)
		{
			cout<<"Word "<<temp->next->word<<" has meaning "<<temp->next->mean<<"."<<endl;
			flag = true;
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if(flag == false)
	{
		cout<<"Word not present in dictionary."<<endl;
	}
}

void dict::dlt(string word)
{
	int x = hash(word);
	bool flag = false;
	node *temp = arr[x];
	while(temp->next != NULL)
	{
		if(temp->next->word == word)
		{
			node *curr;
			curr = temp->next;
			temp->next = curr->next;
			delete curr;
			flag = true;
			cout<<"Deleted successfully."<<endl;
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if(flag == false)
	{
		cout<<"Word not present in dictionary."<<endl;
	}
}
int main()
{	
	dict a;
	string word, mean;
	int ch = 0;
	while(ch!=5)
	{
		cout<<"1. Insert"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"Word: ";
					cin>>word;
					cout<<"Meaning: ";
					cin>>mean;
					a.insert(word, mean);
					break;
				}
			case 2:
				{
					cout<<"Dictionary: "<<endl;
					a.display();
					break;
				}
			case 3:
				{
					cout<<"Word: ";
					cin>>word;
					a.search(word);
					break;
				}
			case 4:
				{
					cout<<"Word: ";
					cin>>word;
					a.dlt(word);
					break;
				}
			case 5:
				{
					cout<<"Exiting..."<<endl;
					break;
				}
			default:
				{
					cout<<"Invalid choice.";
					break;
				}
		}
	}
}
