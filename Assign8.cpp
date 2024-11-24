#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

#define Max 15

struct node
{
	int data, dist;
	string city;
	node *next;
};

class graph
{
	int visited[Max];
	node *adlist[Max];
	int n;
	public:
		graph() //Constructor
		{
			n = 0;			
			for(int i=0; i<Max; i++)
			{
				adlist[i] = new node;
				adlist[i]->data = i;
				adlist[i]->next = NULL;
				adlist[i]->dist = 0;
				adlist[i]->city = "";
			}
		}
		void read();
		void readfromfile();
		void insertedge(int x, int y, int w);
		void displayList();
		void initvisited();
		void dfs(int i);
		void flightExist(int x, int y);
		void connected();
};

void graph::insertedge(int x, int y, int w)
{
	node *temp;
	temp = adlist[x];
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	node *curr1;
	curr1 = new node;
	curr1->data = y;
	curr1->dist = w;
	curr1->city = adlist[y]->city;
	curr1->next = NULL;
	temp->next = curr1;
	
	temp = adlist[y];
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	node *curr2;
	curr2 = new node;
	curr2->data = x;
	curr2->dist = w;
	curr2->city = adlist[x]->city;
	curr2->next = NULL;
	temp->next = curr2;
}

void graph::read()
{
	char ch;
	string s1;
	cout<<"Enter number of cities: ";
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cout<<"City "<<i+1<<": ";
		cin>>s1;
		adlist[i]->city = s1;
	}
	cout<<"Cities recorded successfully."<<endl;
	int x, y, w;
	cout<<"Do you want to add an edge?(y/n)";
	cin>>ch;
	while(ch=='y')
	{
		cout<<"Enter end vertices of edge: ";
		cin>>x>>y;
		cout<<"Enter distance: ";
		cin>>w;
		insertedge(x, y, w);
		cout<<"Do you want to add an edge?(y/n)";
		cin>>ch;
	}
}

void graph::readfromfile()
{
	char ch;
	ifstream f1("g8.dat");
	f1>>n;
	char s1[15];
	for(int i = 0; i<n; i++)
	{
		cout<<"City "<<i+1<<": ";
		f1>>s1;
		adlist[i]->city = s1;
	}
	cout<<"Cities recorded successfully."<<endl;
	int x, y, w;
	f1>>ch;
	while(ch=='y')
	{
		f1>>x;
		f1>>y;
		f1>>w;
		insertedge(x, y, w);
		f1>>ch;
	}
}

void graph::displayList()
{
	node *temp;
	cout<<"---------------------------------"<<endl;
	cout<<"Adjecency list: "<<endl;
	for(int i = 0; i<n; i++)
	{
		temp = adlist[i];
		cout<<temp->city<<" : ";
		while(temp->next != NULL)
		{
			temp = temp->next;
			cout<<temp->city<<"("<<temp->dist<<")"<<" - ";
		}
		cout<<endl;
	}
	cout<<"---------------------------------"<<endl;
}	
	
void graph::initvisited()
{
	for(int i = 0; i<n; i++)
	{
		visited[i] = 0;
	}
}

void graph::dfs(int i)
{
	initvisited();
	cout<<"DFS: ";
	stack<node*> s;
	node *temp;
	s.push(adlist[i]);
	visited[i] = 1;
	while(!s.empty())
	{
		temp = adlist[s.top()->data];
		s.pop();
		cout<<temp->city<<" - ";
		while(temp->next != NULL)
		{
			temp = temp->next;
			if(!visited[temp->data])
			{
				s.push(temp);
				visited[temp->data] = 1;
			}
		}
	}
	cout<<endl;
}

void graph::flightExist(int x, int y)
{
	node *temp = adlist[x];
	while(temp->next!=NULL)
	{
		temp = temp->next;
		if(temp->data == y)
		{
			cout<<"Flight exists between "<<adlist[x]->city<<" & "<<adlist[y]->city<<"."<<endl;
			cout<<"Length of flight is "<<temp->dist<<"Kms"<<endl;
			return;
		}
	}
	cout<<"No flight exists between "<<adlist[x]->city<<" & "<<adlist[y]->city<<"."<<endl;
}

void graph::connected()
{
	int number = 0;
	initvisited();
	stack<node*> s;
	node *temp;
	s.push(adlist[0]);
	visited[0] = 1;
	while(!s.empty())
	{
		temp = adlist[s.top()->data];
		s.pop();
		number++;
		while(temp->next != NULL)
		{
			temp = temp->next;
			if(!visited[temp->data])
			{
				s.push(temp);
				visited[temp->data] = 1;
			}
		}
	}
	if(number == n)
	{
		cout<<"Graph is connected."<<endl;
	}
	else
	{
		cout<<"Graph is not connected."<<endl;
	}
}
	
int main()
{
	int mode, ch = 0;
	graph a;
	cout<<"Select Mode: "<<endl;
	cout<<"1. Manual Input"<<endl;
	cout<<"2. Input From File"<<endl;
	cout<<"Enter Choice: ";
	cin>>mode;
	if(mode == 1)
	{
		a.read();
		cout<<"Graph recorded successfully."<<endl;
	}
	else if(mode == 2)
	{
		a.readfromfile();
		cout<<"Graph recorded successfully."<<endl;
	}
	else
	{
		cout<<"Invalid Choice."<<endl;
	}
	if(mode == 1 || mode == 2)
	{
		while(ch!=5)
			{
				cout<<"-----------------------------------------------------------------------------------------"<<endl;
				cout<<"1. Display Graph"<<endl;
				cout<<"2. Check Connectivity"<<endl;
				cout<<"3. Depth First Search"<<endl;
				cout<<"4. Check Flight: "<<endl;
				cout<<"5. Exit"<<endl;
				cout<<"Enter Choice: ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						{
							a.displayList();
							break;
						}
					case 2:
						{
							a.connected();
							break;
						}
					case 3:
						{
							int b;
							cout<<"Enter starting city number: ";
							cin>>b;
							a.dfs(b);
							break;
						}
					case 4:
						{
							int x, y;
							cout<<"Enter cities to search flight: ";
							cin>>x>>y;
							a.flightExist(x, y);
							break;
						}
					case 5:
						{
							cout<<"Exiting...."<<endl;
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
}


