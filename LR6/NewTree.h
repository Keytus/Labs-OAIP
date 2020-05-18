//---------------------------------------------------------------------------

#ifndef NewTreeH
#define NewTreeH
#include"Tree.h"
class NewTree:public Tree
{

	public:
	int* listmass;
	int height;
	NewTree():Tree(){}
	void CountOfLists(Part* root,int level)
	{
		if(root==0)
		{
			return;
		}
		if(level==0)
		{
			listmass=new int;
		}
		if(root->left==0 && root->right==0)
		{
			listmass[level]++;
		}
		CountOfLists(root->left,level+1);
		CountOfLists(root->right,level+1);
		if(level>=height)
		{
		   height=level;
		}
	}
};
//---------------------------------------------------------------------------
#endif
