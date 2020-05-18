//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Tree.h"
#include "NewTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree* tree=new Tree();
NewTree* newtree=new NewTree();
int i,col,sizeofmass,slotcount;
UnicodeString s;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)      //������������ ������� ��������
{
	slotcount=8;
	StringGrid1->RowCount=slotcount;
	StringGrid1->Cells[0][0]="�.�.�";
	StringGrid1->Cells[0][1]="������ ��� �����";
	StringGrid1->Cells[0][2]="����� ��� ����";
	StringGrid1->Cells[0][3]="����� ��� ���";
	StringGrid1->Cells[0][4]="������";
	StringGrid1->Cells[0][5]="�������";
	StringGrid1->Cells[0][6]="������";
	StringGrid1->Cells[0][7]="������";
	StringGrid1->Cells[1][0]="����";
	for(i=1;i<slotcount;i++)
	{
		StringGrid1->Cells[1][i]=rand()%100;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)              //���� ��������
{
	for(i=1;i<slotcount;i++)
	{
		tree->Add(&(tree->root),AnsiString(StringGrid1->Cells[0][i]).c_str(),StrToInt(StringGrid1->Cells[1][i]));
		newtree->Add(&(newtree->root),AnsiString(StringGrid1->Cells[0][i]).c_str(),StrToInt(StringGrid1->Cells[1][i]));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)                //�����
{
	Memo1->Clear();
	Memo1->Lines->Add("� ������� �����������:");
	tree->CentPrint(tree->root,Memo1);
	Memo1->Lines->Add("������:");
	tree->StraightPrint(tree->root,Memo1);
	Memo1->Lines->Add("��������:");
	tree->ReversePrint(tree->root,Memo1);
	newtree->ReversePrint(tree->root,Memo1);
	int kl=-1;
	TreeView1->Items->Clear();
	tree->PrintInTree(tree->root,kl,TreeView1);
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)          //������������
{
	tree->Balance(&(tree->root));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)           //����������
{
	tree->Add(&(tree->root),AnsiString(Edit1->Text).c_str(),StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)             //��������
{
	tree->DeletePart(&(tree->root),StrToInt(Edit3->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)             //������� �� �������
{
	Memo1->Clear();
	newtree->CountOfLists(newtree->root,0);
	for(i=0;i<newtree->height+1;i++)
	{
		s="����� ������ �� ������ ";
		s+=i+1;
		s+=":";
		s+=newtree->listmass[i];
		Memo1->Lines->Add(s);
	}
}
//---------------------------------------------------------------------------

