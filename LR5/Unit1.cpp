//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include"Queue.h"
#include"List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Queue* object=new Queue();
List** lists=new List*[2];

int i;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void division()                 //������� �� ����������
{
	part* temp=new part;
	part* sup=new part;
	part* current=new part;
	temp=lists[0]->Head;
	while(temp!=0)
	{
		if(temp->value<0)
		{

			if(lists[1]->Head==0)
			{
				if(temp->prev==0)          //���� ������������� ���� ����� � ������ ������ � ������������� ������ ����
				{
					sup=temp;
					temp=temp->next;
					temp->prev=0;
					lists[0]->Head=temp;
					sup->next=0;
					lists[1]->Head=sup;

				}
				else                    //���� ������������� ������ �����,� ������������� ���� � �������� ��� �����
				{
					temp->prev->next=temp->next;
					if(temp->next!=0)   //���� �� � �����
					{
					   temp->next->prev=temp->prev;
					}
					sup=temp;
					temp=temp->next;
					sup->prev=0;
					sup->next=0;
					lists[1]->Head=sup;
				}
			}
			else                      //���� ������������� ���� ����� � ������ ������ � ������������� ������ �� ����
			{
				if(temp->prev==0)
				{
					sup=temp;
					temp=temp->next;
					temp->prev=0;
					lists[0]->Head=temp;
					current=lists[1]->Head;
					while(current->next!=0)
					{
						current=current->next;
					}
					sup->next=0;
					sup->prev=current;
					current->next=sup;
				}
				else                   //���� ������������� ������ �� ����,� ������������� ���� � �������� ��� �����
				{
					temp->prev->next=temp->next;
					if(temp->next!=0)   //���� �� � �����
					{
					   temp->next->prev=temp->prev;
					}
					sup=temp;
					temp=temp->next;
					current=lists[1]->Head;
					while(current->next!=0)
					{
						current=current->next;
					}
					sup->next=0;
					sup->prev=current;
					current->next=sup;
				}
			}
		}
		else
		{
			temp=temp->next;
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)      //���������� ������
{
	for(i=0;i<2;i++)
	{
		lists[i]=new List();
	}
	StringGrid1->Cells[0][0] ="�������";
	for(i=1;i<6;i++)
	{
		StringGrid1->Cells[0][i] =rand();
	}
	StringGrid2->Cells[0][0] ="������";
	for(i=1;i<10;i++)
	{
		StringGrid2->Cells[0][i] =rand()%100-50;
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)              //���������� ������� � �����
{
	for(i=1;i<6;i++)
	{
		object->Add(StrToInt(StringGrid1->Cells[0][i]));
	}
	for(i=1;i<10;i++)
	{
		lists[0]->Add(StrToInt(StringGrid2->Cells[0][i]));
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)        //�����
{
	ListBox1->Clear();
	ListBox2->Clear();
	object->Print(ListBox1);
	lists[1]->Print(ListBox2);
	lists[0]->Print(ListBox2);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)    //������� ������ ������� �������
{
	object->RemoveHead();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)       //�������� �� �������
{
	object->Empty(ListBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)        //������� �������
{
	object->RemoveQueue();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)         //��������� ����������
{
	division();
}
//---------------------------------------------------------------------------

