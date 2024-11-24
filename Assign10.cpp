#include <iostream>
using namespace std;

#define MAX 50

class heap
{
	public:
		int a[MAX], n;
		heap()
		{
			n = 0;
		}
		void reheapDown(int i);
		void insert(int val);
		void reheapUp(int i);
		void buildHeap();
		void reheapDownMin(int i);
		void insertMin(int val);
		void reheapUpMin(int i);
		void buildHeapMin();
		void heapSort();
		void showHeapContents();
		void showMinHeapContents();
		void getMax()
		{
			buildHeap();
			cout<<"Maximum marks: "<<a[0]<<endl;
		}
		void getMin()
		{
			buildHeapMin();
			cout<<"Minimum marks: "<<a[0]<<endl;
		}
};

void heap::showHeapContents()
{
	buildHeap();
	cout<<"Contents of Max Heap are: ";
	for(int i = 0; i<n; i++)
	{
		cout<<a[i]<<" - ";
	}
	cout<<endl;
}

void heap::showMinHeapContents()
{
	buildHeapMin();
	cout<<"Contents of Min Heap are: ";
	for(int i = 0; i<n; i++)
	{
		cout<<a[i]<<" - ";
	}
	cout<<endl;
}

void heap::reheapUp(int i)
{
	while(i>0 && a[i] > a[(i-1)/2])
	{
		int temp = a[i];
		a[i] = a[(i-1)/2];
		a[(i-1)/2] =  temp;
		i = (i-1)/2;
	}
}

void heap::insert(int val)
{
	a[n] = val;
	reheapUp(n);
	n++;
}

void heap::reheapDown(int i)
{	
	int j, temp;
	while((2*i + 1) < n)
	{
		j = 2*i + 1;
		if(j+1 < n && a[j+1] > a[j])
		{
			j = j + 1;
		}
		if(a[i] > a[j])
		{
			break;
		}
		else
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i = j;
		}
	}
}

void heap::buildHeap()
{
	for(int i = (n-2)/2; i>= 0; i--)
	{
		reheapDown(i);
	}
}

void heap::reheapUpMin(int i)
{
	while(i>0 && a[i] < a[(i-1)/2])
	{
		int temp = a[i];
		a[i] = a[(i-1)/2];
		a[(i-1)/2] =  temp;
		i = (i-1)/2;
	}
}

void heap::insertMin(int val)
{
	a[n] = val;
	reheapUpMin(n);
	n++;
}

void heap::reheapDownMin(int i)
{	
	int j, temp;
	while((2*i + 1) < n)
	{
		j = 2*i + 1;
		if(j+1 < n && a[j+1] < a[j])
		{
			j = j + 1;
		}
		if(a[i] < a[j])
		{
			break;
		}
		else
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i = j;
		}
	}
}

void heap::buildHeapMin()
{
	for(int i = (n-2)/2; i>= 0; i--)
	{
		reheapDownMin(i);
	}
}

int main()
{
	heap h;
	int ch = 0;
	while(ch != 6)
	{
		cout<<"----------------------------------------------------"<<endl;
		cout<<"1. Add more marks"<<endl;
		cout<<"2. Get maximum marks"<<endl;
		cout<<"3. Get minimum marks"<<endl;
		cout<<"4. Show contents of max heap"<<endl;
		cout<<"5. Show contents of min heap"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					char yn;
					do
					{
						int j;
						cout<<"Enter marks: ";
						cin>>j;
						h.insert(j);
						cout<<"Do you want to add more? (y/n)";
						cin>>yn;
					}while(yn == 'y');
					break;
				}
			case 2:
				h.getMax();
				break;
			case 3:
				h.getMin();
				break;
			case 4:
				h.showHeapContents();
				break;
			case 5:
				h.showMinHeapContents();
				break;
			case 6:
				cout<<"Exiting...."<<endl;
				break;
			default:
				cout<<"Invalid choice."<<endl;
				break;
		}
	}
}
