//---------------------------------------------------------------------------

#ifndef ProductH
#define ProductH
#define nullptr 0
#include <string>
using namespace std;
class List
{
	private:
	class Prod
	{
		public:
		string name;
		int count;
		int code;
		Prod *pNext;
		Prod(string name,int count,int code,Prod *pNext=nullptr)
		{
			this->name=name;
			this->count=count;
			this->code=code;
			this->pNext=pNext;
		}
	};
	int size;
	Prod *head;
	public:
	List(int size,Prod *head){size=0;head=nullptr;}
	void add(string name,int count,int code)
	{
		if(head==nullptr)
		{
			head=new Prod(name,count,code);
		}
		else
		{
			Prod* current=this->head;
			while(current->pNext!=nullptr)
			{
				current=current->pNext;
			}
			current->pNext=new Prod(name,count,code);
		}
		size++;
	}
	void remove(int index)
	{
		if(index==0)
		{
			removehead();
		}
		else
		{
			Prod *prev=this->head;
			for(int i=0;i<index-1;i++)
			{
				prev=prev->pNext;
			}
			Prod *toDelete=prev->pNext;
			prev->pNext = toDelete->pNext;
			delete toDelete;
			size--;
        }
	}
	void removehead()
	{
		Prod *temp=head;
		head=head->pNext;
		delete temp;
		size--;
    }
	int getsize(){return size;}
	int getcount(const int index)
	{
		int counter = 0;
		Prod *current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				 return current->count;
			}
		current = current->pNext;
		counter++;
		}
	}
	int getcode(const int index)
	{
		int counter = 0;
		Prod *current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				 return current->code;
			}
		current = current->pNext;
		counter++;
		}
	}
	string getname(const int index)
	{
        int counter = 0;
		Prod *current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				 return current->name;
			}
		current = current->pNext;
		counter++;
		}
    }
};
//---------------------------------------------------------------------------
#endif
