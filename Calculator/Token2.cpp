// Token2.cpp: implementation of the Token class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Calculator.h"
#include "Token2.h"
#include "Data.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Token::Token()
{

}

Token::~Token()
{

}

double Token::expression()
{
	double C=0,R=0;
	while(a[i+1].ch==' ')
	{
		switch(a[i+1].ch)
		{
		case'+':if(a[i+1].ch!='*'||a[i+1].ch!='*'){
			C+=a[i].volue;
			break;}
		case'-':if(a[i+1].ch!='*'||a[i+1].ch!='*'){
					C-=a[i].volue;
					break;}
        case'*':if(a[i+1].ch!='+'||a[i+1].ch!='-'){
			R*=a[i].volue;
			break;}
		case'/':if(a[i+1].ch!='+'||a[i+1].ch!='-'){
			R/=a[i].volue;
			break;}
		return R+C;
		}
	}

}

double Token::term()
{

}

double Token::primary()
{

}
