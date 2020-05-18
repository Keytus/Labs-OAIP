//---------------------------------------------------------------------------

#ifndef PartH
#define PartH
#include <string>
using namespace std;
class Part
{
	public:
	string text;
	int key;
	unsigned char height;
	Part* left;
	Part* right;
	Part(string t,int k):text(t),key(k),height(1),left(0),right(0){}

};

//---------------------------------------------------------------------------
#endif
