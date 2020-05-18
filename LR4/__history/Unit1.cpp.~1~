//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include"List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int Kol = 8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text = "a/(b*(c+d))-e";
	Edit2->Text = "";
	char a = 'a';
	StringGrid1->Cells[0][0] ="Имя";
	StringGrid1->Cells[1][0] ="Знач.";
	for(int i = 1; i<Kol; i++)
	{
		StringGrid1->Cells[0][i] = a++;
		StringGrid1->Cells[1][i] = i;
	}
}
//---------------------------------------------------------------------------
