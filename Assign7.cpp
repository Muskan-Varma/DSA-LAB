#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define Max 15

struct node
{
	int data;
	node *next;
};

class graph
{
	int admatrix[Max][Max], visited[Max];
	node *adlist[Max];
	string places[20];
	int n;
	public:
		
		graph() //Constructor
		{
			n = 0;
			for(int i=0; i<Max; i++)
			{
				for(int j=0; j<Max; j++)
				{
					admatrix[i][j] = 0;
				}
			}
			places[0]="Gate";
			places[1]="Ground";
			places[2]="Main Building";
			places[3]="Polytechnic";
			places[4]="Pharmacy";
			places[5]="Canteen";
			
			for(int i=0; i<Max; i++)
			{
				adlist[i] = new node;
				adlist[i]->data = i;
				adlist[i]->next = NULL;
			}
		}
		void read();
		void readfromfile();
		void insertnode(int x, int y);
		void display();
		void displayList();
		void dfs(int i);
		void initvisited();
		void bfs();
};

void graph::insertnode(int x, int y)
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
	curr2->next = NULL;
	temp->next = curr2;
}

void graph::read()
{
	char ch;
	cout<<"Enter number of nodes: ";
	cin>>n;
	int x, y;
	cout<<"Do you want to add an edge?(y/n)";
	cin>>ch;
	while(ch=='y')
	{
		cout<<"Enter end vertices of edge: ";
		cin>>x>>y;
		admatrix[x][y] = 1;
		admatrix[y][x] = 1;
		insertnode(x, y);
		cout<<"Do you want to add an edge?(y/n)";
		cin>>ch;
	}
}

void graph::readfromfile()
{
	char ch;
	ifstream f1("g1.dat");
	f1>>n;
	int x, y;
	f1>>ch;
	while(ch=='y')
	{
		f1>>x;
		f1>>y;
		admatrix[x][y] = 1;
		admatrix[y][x] = 1;
		insertnode(x, y);
		f1>>ch;
	}
}

void graph::display()
{
	cout<<"------------------------------------"<<endl;
	cout<<"Adjacency Matrix: "<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<admatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"------------------------------------"<<endl;
}

void graph::dfs(int i)
{
	visited[i] = 1;
	cout<<places[i]<<" - ";
	for(int k = 0; k<n; k++)
	{
		if(admatrix[i][k] && !visited[k])
			dfs(k);
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
		cout<<places[i]<<" : ";
		while(temp->next != NULL)
		{
			temp = temp->next;
			cout<<places[temp->data]<<" - ";
		}
		cout<<endl;
	}
	cout<<"---------------------------------"<<endl;
}

void graph::bfs()
{
	initvisited();
	cout<<"BFS: ";
	queue<node*> s;
	node *temp;
	s.push(adlist[0]);
	visited[0] = 1;
	while(!s.empty())
	{
		temp = adlist[s.front()->data];
		s.pop();
		cout<<places[temp->data]<<" - ";
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
	
	
	
void graph::initvisited()
{
	for(int i = 0; i<n; i++)
	{
		visited[i] = 0;
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
				cout<<"1. Display Adjacency Matrix"<<endl;
				cout<<"2. Display Adjacency List"<<endl;
				cout<<"3. Depth First Search"<<endl;
				cout<<"4. Breadth First Search"<<endl;
				cout<<"5. Exit"<<endl;
				cout<<"Enter Choice: ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						{
							a.display();
							break;
						}
					case 2:
						{
							a.displayList();
							break;
						}
					case 3:
						{
							int b;
							a.initvisited();
							cout<<"Enter Starting Node:";
							cin>>b;
							a.dfs(b);
							cout<<endl;
							break;
						}
					case 4:
						{
							a.bfs();
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

	
	
	
