//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include"List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List first;
int Kol = 6;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)        //настойка
{
	Edit1->Text = "a/(b*(c+d))-e";
	Edit2->Text = "";
	Edit3->Text= "";
	Edit9->Text= "";
	char a = 'a';
	StringGrid1->Cells[0][0] ="Имя";
	StringGrid1->Cells[1][0] ="Знач.";
	for(int i = 1; i<Kol; i++)
	{
		StringGrid1->Cells[0][i] = a++;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)           //преобразование к ОПЗ
{
	first.head = NULL;
	char ss, a;
	String InStr, OutStr;
	OutStr = "";
	Edit2->Text = "";
	InStr = Edit1->Text;
	char znak[5]={'+','-','*','/'};
	int len = InStr.Length(), k;
	for (k = 1; k <= len; k++)
	{
		ss = InStr[k];
		if ( ss == '(' ) first.head = first.InStack(first.head, ss);
		if ( ss == ')' )
		{
			while ( (first.head -> info) != '(' )
			{
				first.head = first.OutStack(first.head,&a);
				OutStr += a;
			}
			first.head = first.OutStack(first.head,&a);
		}
	   if (ss >= 'a' && ss <= 'z' )	   OutStr += ss;
	   if (ss==znak[0] || ss==znak[1] || ss==znak[2] || ss==znak[3])
	   {
			while ( first.head != NULL && first.Prior(first.head -> info) >= first.Prior (ss) )
			{
				first.head = first.OutStack(first.head, &a);
				OutStr += a;
			}
			first.head = first.InStack(first.head, ss);
	   }
	}
	while ( first.head != NULL)
	{
		first.head = first.OutStack(first.head, &a);
		OutStr += a;
	}
	Edit2->Text = OutStr;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)         //расчёт ОПЗ
{
	char ch;
	String OutStr = Edit2->Text;
	for (int i=1; i<Kol; i++)
	{
		ch = StringGrid1->Cells[0][i][1];
		first.mas[int(ch)]=StrToFloat(StringGrid1->Cells[1][i]);
	}
	Edit3->Text=FloatToStr(first.Rezult(OutStr));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)       //ввод
{
	StringGrid1->Cells[1][1] = Edit4->Text;
	StringGrid1->Cells[1][2] = Edit5->Text;
	StringGrid1->Cells[1][3] = Edit6->Text;
	StringGrid1->Cells[1][4] = Edit7->Text;
	StringGrid1->Cells[1][5] = Edit8->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)     //обычный расчёт
{
   double a,b,c,d,e,result;
   a=StrToFloat(StringGrid1->Cells[1][1]);
   b=StrToFloat(StringGrid1->Cells[1][2]);
   c=StrToFloat(StringGrid1->Cells[1][3]);
   d=StrToFloat(StringGrid1->Cells[1][4]);
   e=StrToFloat(StringGrid1->Cells[1][5]);
   result=a/(b*(c+d))-e;
   Edit9->Text=result;
}
//---------------------------------------------------------------------------

