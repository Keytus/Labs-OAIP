//---------------------------------------------------------------------------
#include"Stack.h"
#ifndef HashTableH
#define HashTableH
class HashTable
{
	int hashTableSize;
	int countOfElements;
	int* keys;
	Stack** stacks;
	public:
	HashTable(int tsize,int esize,int* keymass)
	{
		hashTableSize=tsize;
		countOfElements=esize;
		keys=keymass;
		stacks=new Stack*[hashTableSize];
		for(int i=0;i<hashTableSize;i++)
		{
			stacks[i]=new Stack();
		}
	}
	Stack* GetStack(int i)
	{
		return stacks[i];
    }
	void AddKey(int element)
	{
		countOfElements++;
		keys=new int[countOfElements];
		keys[countOfElements-1]=element;
		stacks[this->myHash(keys[countOfElements-1],hashTableSize)]->Add(keys[countOfElements-1]);
	}
	int FindElement(int element)
	{
		Node* temp=stacks[this->myHash(element,hashTableSize)]->GetNode();
		for(;temp!=0;)
		{
			if(temp->data==element)
			{
				return myHash(element,hashTableSize)+1;
			}
			temp=temp->next;
		}
		return -1;
	}
	void Full()
	{
		for(int i=0;i<countOfElements;i++)
		{
			stacks[this->myHash(keys[i],hashTableSize)]->Add(keys[i]);
		}
	}
	void Print(TMemo *Memo)
	{
		 UnicodeString str;
		 Node* temp;
		 int i;
		 temp=stacks[0]->GetNode();
		 for(int i=0;i<hashTableSize;i++)
		 {
			 str+=IntToStr(i+1)+":";
			 temp=stacks[i]->GetNode();
			 for(;temp!=0;)
			 {
				 str+=IntToStr(temp->data)+"->";
				 temp=temp->next;
			 }
			 Memo->Lines->Add(str);
			 str="";
		 }
	}
	void FreeHeadOfStack(int need)
	{
		if(need>0 && need<=hashTableSize)stacks[need-1]->DeleteHead();
	}
	void FreeStack(int need)
	{
		if(need>0 && need<=hashTableSize)stacks[need-1]->DeleteStack();
	}
	void Free()
	{
		for(int i=0;i<hashTableSize;i++)
		{
			stacks[i]->DeleteStack();
		}
		delete(keys);
	}
	int  myHash(int key,int size)
	{
		return (key%size);
	}
};
//---------------------------------------------------------------------------
#endif
