//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include"Stack.h"
#include"HashTable.h"
#include"TaskHashTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HashTable* hashtable;
TaskHashTable* task;
int hashTableSize,countOfElements,i;
int* keys;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo3->Clear();
	Memo2->Clear();
	hashtable->Print(Memo3);
	task->Print(Memo2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	hashtable->FreeStack(StrToInt(Edit3->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	hashTableSize=StrToInt(Edit1->Text);
	countOfElements=StrToInt(Edit2->Text);
	keys=new int[countOfElements];
	for(i=0;i<countOfElements;i++)
	{
		keys[i]=rand();
		Memo1->Lines->Add(keys[i]);
    }
	hashtable=new HashTable(hashTableSize,countOfElements,keys);
	task=new TaskHashTable(hashTableSize,countOfElements,keys);
	hashtable->Full();
	task->Full();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	hashtable->AddKey(StrToInt(Edit4->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int position=hashtable->FindElement(StrToInt(Edit5->Text));
	if(position>0)
	{
		Memo3->Text="Ёлемент "+Edit5->Text+" расположен в "+IntToStr(position)+" стеке.";
	}
	else
	{
		Memo3->Text="Ёлемент не найден.";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	hashtable->FreeHeadOfStack(StrToInt(Edit3->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    Memo2->Clear();
	task->Task(Memo2);
}
//---------------------------------------------------------------------------
