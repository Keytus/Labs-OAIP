//---------------------------------------------------------------------------
#include"HashTable.h"
#ifndef TaskHashTableH
#define TaskHashTableH
class TaskHashTable:public HashTable
{
	int hashTableSize;
	int countOfElements;
	int* keys;
	Stack** stacks;
	public:
	TaskHashTable(int tsize,int esize,int* keymass):HashTable(tsize,esize,keymass)
	{
		hashTableSize=tsize;
		countOfElements=esize;
		keys=keymass;
	}
	void Task(TMemo *Memo)
	{
		Node* temp;
		int maxkey=0;
		for(int i=0;i<hashTableSize-1;i++)
		{
			temp=this->GetStack(i)->GetNode();
			for(;temp!=0;)
			{
				if(maxkey<temp->data)
				{
					maxkey=temp->data;
				}

				temp=temp->next;
			}
		}
		Memo->Lines->Add("Номер стека,содержащий максимальное значение ключа:"+IntToStr(this->FindElement(maxkey)));
	}
};
//---------------------------------------------------------------------------
#endif
