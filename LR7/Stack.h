//---------------------------------------------------------------------------
#include <vcl.h>
#include"Node.h"
#ifndef StackH
#define StackH
class Stack
{
	Node* Head;
	public:
	Stack(){Head=0;}
	int GetData()
	{
		return this->Head->data;
	}
	Node* GetNode()
	{
		return Head;
	}
	void Add(int data)
	{
		Node* temp=new Node;
		temp->data=data;
		if(this->Head==0)
		{
			temp->next=0;
			this->Head=temp;
		}
		else
		{
			temp->next=this->Head;
			this->Head=temp;
		}
	}
	void Print(TMemo *Memo)
	{
		Node*temp=this->Head;
		for(;temp!=0;)
		{
			Memo->Lines->Add(temp->data);
			temp=temp->next;
		}
	}
	void DeleteHead()
	{
		if(Head!=0)
		{
			Node*temp=Head;
			Head=Head->next;
			delete(temp);
		}
	}
	void DeleteStack()
	{
		for(;Head!=0;)
		{
            DeleteHead();
		}
	}
};
//---------------------------------------------------------------------------
#endif
