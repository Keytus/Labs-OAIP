//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
#include<System.hpp>
class List
{
	public:
	struct Stack
	{
		char info;
		Stack *next;
	};
	Stack *head;
	double mas[201];
	List():head(NULL){}
	int Prior(char a)
	{
		switch(a)
		{
		   case'*':
		   case'/':return 3;
		   case'-':
		   case'+':return 2;
		   case'(':return 1;
		}
	}
	Stack* InStack(Stack *p, char in)
	{
		Stack *t = new Stack;
		t -> info = in;
		t -> next = p;
		return t;
	}
	Stack* OutStack(Stack* p, char *out)
	{
		Stack *t = p;
		*out = p -> info;
		p = p -> next;
		delete t;
		return p;
	}
	double Rezult(String Str)
	{
		char ch, ch1, ch2;
		double op1, op2, rez;
		char znak[5]={'+','-','*','/'};
		char chr = 'z'+1;
		for (int i=1; i <= Str.Length(); i++)
		{
			ch=Str[i];
			if (ch!=znak[0] && ch!=znak[1] && ch!=znak[2] && ch!=znak[3])
			{
				 head = InStack(head, ch);
			}
			else
			{
				 head = OutStack(head,&ch1);
				 head = OutStack(head,&ch2);
				 op1 = mas[int (ch1)];
				 op2 = mas[int (ch2)];
				 switch (ch)
				 {
					  case '+' :rez=op2+op1; break;
					  case '-' : rez=op2-op1; break;
					  case '*' : rez=op2*op1; break;
					  case '/' : rez=op2/op1; break;
				 }
			mas[int (chr)] = rez;
			head = InStack(head,chr);
			chr++;
			}
		}
		return rez;
	}
};

//---------------------------------------------------------------------------
#endif
