//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include "Unit1.h"
#include "Part.h"
class Tree
{
	public:
	Part* root;
	int size;
	Tree():root(0),size(0){}
	void Add(Part** current,string text,int key)
	{
		if(*current==0)
		{
			size++;
			*current=new Part(text,key);
		}
		else
		{

			if((*current)->key>key)
			{

				Add(&((*current)->left),text,key);
			}
			else
			{
				if((*current)->key<key)
				{

					Add(&((*current)->right),text,key);
				}
			}
		}
	}
	void PrintInTree(Part* root,int kl,TTreeView *TreeView)
	{
		if(root==0)
		{
			return;
		}
		if(kl==-1)
		{
			Form1->TreeView1->Items->AddFirst(NULL,IntToStr(root->key));
		}
		else
		{
			TreeView->Items->AddChildFirst(TreeView->Items->Item[kl],IntToStr(root->key));
		}
		kl++;
		PrintInTree(root->left,kl,TreeView);
		PrintInTree(root->right,kl,TreeView);
		kl--;
	}
	void CentPrint(Part* root,TMemo *Memo)
	{
		if(root==0)
		{
			return;
		}

		CentPrint(root->left,Memo);
		UnicodeString as=root->key;
		as+="-";
		as+=root->text.c_str();
		Memo->Lines->Add(as);
		CentPrint(root->right,Memo);
	}
	void StraightPrint(Part* root,TMemo *Memo)
	{
        if(root==0)
		{
			return;
		}
		UnicodeString as=root->key;
		as+="-";
		as+=root->text.c_str();
		Memo->Lines->Add(as);
		StraightPrint(root->left,Memo);
		StraightPrint(root->right,Memo);
	}
	void ReversePrint(Part* root,TMemo *Memo)
	{
		if(root==0)
		{
			return;
		}
		ReversePrint(root->left,Memo);
		ReversePrint(root->right,Memo);
		UnicodeString as=root->key;
		as+="-";
		as+=root->text.c_str();
		Memo->Lines->Add(as);
	}
	void Size(TMemo *Memo)
	{
		Memo->Lines->Add(size);
	}
	void Balance(Part** current)
	{
		Part **mass=new Part*[size];
		int sizeofmass=size;
		int col=0;
        Balancemass(*current,&col,mass);
		BalanceTree(current,mass,sizeofmass);
		for(int i=0;i<sizeofmass;i++)
		{
		   delete(mass[i]);
		}
		delete(mass);
	}
	void Balancemass(Part* root,int* i,Part** mass)
	{
		if(root==0)
		{
			return;
		}
		Balancemass(root->left,i,mass);
		mass[*i]=new Part(root->text,root->key);
		*i=*i+1;
		Balancemass(root->right,i,mass);
	}
	void BalanceTree(Part** current,Part** mass,int sizeofmass)
	{
		DeleteTree(current);
		CentElem(current,mass,sizeofmass,0);
		for(int i=0;i<sizeofmass;i++)
		{
			Add(current,mass[i]->text,mass[i]->key);
		}
	}
	void CentElem(Part** current,Part** mass,int sizeofmass,int startposition)
	{
		if(sizeofmass<3)
		{
			return;
		}
		Add(current,mass[startposition+(sizeofmass/2)]->text,mass[startposition+(sizeofmass/2)]->key);
		CentElem(&((*current)->left),mass,sizeofmass/2,startposition);
		CentElem(&((*current)->right),mass,sizeofmass/2,startposition+(sizeofmass/2)+1);
	}
	void DeletePart(Part** current,int key)
	{
		if((*current)->key==key)
		{
			Part* temp=*current;

			if((*current)->left==0 && (*current)->right==0)
			{
				*current=0;
				delete temp;
			}
			else
			{
				if((*current)->left==0)
				{
					*current=(*current)->right;
					delete temp;
				}
				else
				{
					if((*current)->right==0)
					{
						*current=(*current)->left;
						delete temp;
					}
					else
					{
						Part* predmaxleft=*current;
						Part* maxleft=((*current)->left);
						int i=0;
						predmaxleft=maxleft;
						while(maxleft->right!=0)
						{
							predmaxleft=maxleft;
							maxleft=maxleft->right;
							i=1;
						}

						*current=maxleft;
						predmaxleft->right=maxleft->left;
						maxleft->right=temp->right;
						if(i!=0)
						{
							maxleft->left=predmaxleft;
						}
						delete temp;
                    }
                }
            }
		}
		else
		{
			if((*current)->key>key)
			{
				DeletePart(&((*current)->left),key);
			}
			else
			{
				if((*current)->key<key)
				{
					DeletePart(&((*current)->right),key);
                }
            }
        }
    }
	void DeleteTree(Part** current)
	{
		if(*current==0)
		{
			return;
		}
		DeleteTree(&(*current)->left);
		DeleteTree(&(*current)->right);
		delete(*current);
		*current=0;
		size=0;
	}
};
//---------------------------------------------------------------------------
#endif
