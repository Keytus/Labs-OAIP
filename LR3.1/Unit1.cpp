//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include"Product.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
using namespace std;
int i,j,t,line;
List first(0,nullptr);
string s;
UnicodeString as;
//---------------------------------------------------------------------------
void __fastcall TForm1::output(TObject *Sender)                 //функция для вывода
{
	Memo2->Clear();
	for(i=0;i<first.getsize();i++)
	{
		as=first.getname(i).c_str();
		Memo2->Lines->Add(as);
		Memo2->Lines->Add(first.getcount(i));
		Memo2->Lines->Add(first.getcode(i));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)                //загрузіть
{
	TStringList *STR= new TStringList;
	STR->CommaText=Memo1->Text;
	line=Memo1->Lines->Count;
	for(i=0;i<line;i=i+3)
	{
		s=AnsiString(STR[0][i]).c_str();
		first.add(s,StrToInt(STR[0][i+1]),StrToInt(STR[0][i+2]));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)       //поиск по номеру цеха
{
	Memo2->Clear();
	int need=StrToInt(Edit1->Text);
	for(i=0;i<first.getsize();i++)
	{
		if(first.getcode(i)==need)
		{
			as=first.getname(i).c_str();
			Memo2->Lines->Add(as);
			Memo2->Lines->Add(first.getcount(i));
			Memo2->Lines->Add(first.getcode(i));
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)         //поиск по продукции
{
	Memo2->Clear();
	int need=StrToInt(Edit2->Text);
	for(i=0;i<first.getsize();i++)
	{
		if(first.getcount(i)>=need)
		{
			as=first.getname(i).c_str();
			Memo2->Lines->Add(as);
			Memo2->Lines->Add(first.getcount(i));
			Memo2->Lines->Add(first.getcode(i));
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)              //удалить
{
	int need=StrToInt(Edit3->Text);
	if(need>0)first.remove(need-1);
	output(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)             //вывод
{
	output(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)            //добавіть
{
	s=AnsiString(Edit4->Text).c_str();
	first.add(s,StrToInt(Edit5->Text),StrToInt(Edit6->Text));
	output(Sender);
}
//---------------------------------------------------------------------------
