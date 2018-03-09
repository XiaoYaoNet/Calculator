// Token2.h: interface for the Token class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOKEN2_H__E4A90C87_D406_45D2_A0DD_4BF1E796B680__INCLUDED_)
#define AFX_TOKEN2_H__E4A90C87_D406_45D2_A0DD_4BF1E796B680__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Token  
{
public:
	char ch;
	double num;
	double primary();
	double term();
	double expression();
	Token();
	virtual ~Token();

};

#endif // !defined(AFX_TOKEN2_H__E4A90C87_D406_45D2_A0DD_4BF1E796B680__INCLUDED_)
