#include <iostream>
#include <string.h>
using namespace std;

#define max 10

struct phonebook
{
    long int number;
    string name;
};

class HashTable
{
    phonebook HT[max];
    int size;
    public:
        HashTable()
        {
            size = max;
            for(int i=0; i<size; i++)
            {
                HT[i].number = -1;
                HT[i].name = " ";
            }
        }
        void insert(long long key, string name);
        void display();
        int hash(long long key);
        void dlt(long long key);
        void search(long long key);

};

void HashTable::display()
{
    cout<<"Phonebook Records: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<i<<" : "<<HT[i].name<<" "<<HT[i].number<<endl;
    }
}

int HashTable::hash(long long key)
{
    return (key%10);
}

void HashTable::insert(long long key, string name)
{
    int index = hash(key);
    if(HT[index].number == -1)
    {
        HT[index].number = key;
        HT[index].name = name;
    }
    else
    {
        for(int i=(index%size); i%size < size; i = (i+1)%size)
        {
            if(HT[i].number == -1)
            {
                HT[i].number = key;
                HT[i].name = name;
                break;
            }
        }
    }
}

void HashTable::search(long long key)
{
    int index = hash(key);
    int count = 0;
    if(HT[index].number == key)
    {
        cout<<"Number found and belongs to "<<HT[index].name<<"."<<endl;
    }
    else
    {
        for(int i=(index%size); i%size < size; i = (i+1)%size)
        {
            if(HT[i].number == key)
            {
                cout<<"Number found and belongs to "<<HT[i].name<<"."<<endl;
                break;
            }
            count++;
            if(count==10)
            {
                cout<<"Not found."<<endl;
                break;
            }
        }
    }
}

void HashTable::dlt(long long key)
{
    int index = hash(key);
    int count = 0;
    if(HT[index].number == key)
    {
        HT[index].number = -1;
        HT[index].name = " ";
        cout<<"Successfully Deleted."<<endl;
    }
    else
    {
        for(int i=(index%size); i%size < size; i = (i+1)%size)
        {
            if(HT[i].number == key)
            {
                HT[i].number = -1;
                HT[i].name = " ";
                cout<<"Successfully Deleted."<<endl;
            }
            count++;
            if(count==10)
            {
                cout<<"Not found."<<endl;
                break;
            }
        }
    }
}

class HashTableQ
{
    phonebook HT[max];
    int size;
    public:
        HashTableQ()
        {
            size = max;
            for(int i=0; i<size; i++)
            {
                HT[i].number = -1;
                HT[i].name = " ";
            }
        }
        void insert(long long key, string name);
        void display();
        int hash(long long key);
        void dlt(long long key);
        void search(long long key);

};

void HashTableQ::display()
{
    cout<<"Phonebook Records: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<i<<" : "<<HT[i].name<<" "<<HT[i].number<<endl;
    }
}

int HashTableQ::hash(long long key)
{
    return (key%10);
}

void HashTableQ::insert(long long key, string name)
{
    int index = hash(key);
    if(HT[index].number == -1)
    {
        HT[index].number = key;
        HT[index].name = name;
    }
    else
    {
        int i = 1;
        int indnew = index;
        while(HT[indnew].number != -1)
        {
            indnew = (index + (i*i))%size;
            i++;
        }
        HT[indnew].number = key;
        HT[indnew].name = name;
    }
}

void HashTableQ::search(long long key)
{
    int index = hash(key);
    if(HT[index].number == key)
    {
        cout<<"Number found and belongs to "<<HT[index].name<<endl;
    }
    else
    {
        int i = 1;
        int indnew = index;
        while(HT[indnew].number != key && i<size+1)
        {
            indnew = (index + (i*i))%size;
            i++;
        }
        if(i<size+1)
        {
        	cout<<"Number found and belongs to "<<HT[indnew].name<<endl;
		}
		else
		{
			cout<<"Not found."<<endl;
		}
    }
}

void HashTableQ::dlt(long long key)
{
    int index = hash(key);
    if(HT[index].number == key)
    {
        HT[index].number = -1;
        HT[index].name = " ";
    }
    else
    {
        int i = 1;
        int indnew = index;
        while(HT[indnew].number != key && i<size+1)
        {
            indnew = (index + (i*i))%size;
            i++;
        }
        if(i<size+1)
        {
        	HT[indnew].number = -1;
        	HT[indnew].name = " ";
        	cout<<"Deleted successfully."<<endl;
		}
		else
		{
			cout<<"Not found."<<endl;
		}
    }
}

int main()
{
	int main_choice = 0;
	while(main_choice!=3)
	{
		cout<<"---------------------------------------------------------------------------------"<<endl;
		cout<<"--------------------------------MODE SELECTION MENU------------------------------"<<endl;
		cout<<"---------------------------------------------------------------------------------"<<endl;
		cout<<"1. Linear probing"<<endl;
		cout<<"2. Quadratic probing"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>main_choice;
		switch(main_choice)
		{
			case 1:
				{
					HashTable a;
    				long long key;
    				string name;
    				int choice = 0;
    				while(choice != 5)
    				{
        				cout<<"--------------------------------LINEAR PROBING-----------------------------------"<<endl;
        				cout<<"1. Insert"<<endl;
        				cout<<"2. Display"<<endl;
        				cout<<"3. Search"<<endl;
        				cout<<"4. Delete"<<endl;
        				cout<<"5. Change Mode"<<endl;
        				cout<<"Enter choice: ";
        				cin>>choice;
        				switch(choice)
        				{
            				case 1:
            				{
                				cout<<"Phone number to insert: ";
                				cin>>key;
                				cout<<"Name: ";
                				cin>>name;
                				a.insert(key, name);
                				break;
            				}
            				case 2:
            				{
            				    a.display();
                				break;
            				}
            				case 3:
            				{
                				cout<<"Phone number to search: ";
                				cin>>key;
                				a.search(key);
                				break;
            				}
            				case 4:
            				{
                				cout<<"Phone number to delete: ";
                				cin>>key;
                				a.dlt(key);
                				break;
            				}
            				case 5:
            				{
                				break;
            				}
            				default:
            				{
                				cout<<"Invalid choice."<<endl;
                				break;
            				}
        				}
    				}
    				break;
				}
			case 2:
				{
					HashTableQ aq;
    				long long keyq;
    				string nameq;
    				int choiceq = 0;
    				while(choiceq != 5)
    				{
        				cout<<"--------------------------------QUADRATIC PROBING--------------------------------"<<endl;
        				cout<<"1. Insert"<<endl;
        				cout<<"2. Display"<<endl;
        				cout<<"3. Search"<<endl;
        				cout<<"4. Delete"<<endl;
        				cout<<"5. Change Mode"<<endl;
        				cout<<"Enter choice: ";
        				cin>>choiceq;
        				switch(choiceq)
        				{
            				case 1:
            				{
                				cout<<"Phone number to insert: ";
                				cin>>keyq;
                				cout<<"Name: ";
                				cin>>nameq;
                				aq.insert(keyq, nameq);
                				break;
            				}
            				case 2:
            				{
            				    aq.display();
                				break;
            				}
            				case 3:
            				{
                				cout<<"Phone number to search: ";
                				cin>>keyq;
                				aq.search(keyq);
                				break;
            				}
            				case 4:
            				{
                				cout<<"Phone number to delete: ";
                				cin>>keyq;
                				aq.dlt(keyq);
                				break;
            				}
            				case 5:
            				{
                				break;
            				}
            				default:
            				{
                				cout<<"Invalid choice."<<endl;
                				break;
            				}
        				}
    				}
    				break;
				}
			case 3:
				{
					cout<<"Exiting..."<<endl;
					break;
				}
			default:
				{
					cout<<"Invalid choice...."<<endl;
					break;
				}
		}
	}
}
