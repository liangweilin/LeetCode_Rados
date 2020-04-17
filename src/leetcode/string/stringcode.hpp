#ifndef _STRINGCODE_H
#define _STRINGCODE_H

#include "op/op.hpp"


class StringCode:public Op{

private:
	
public:
	StringCode(Argument *arg):Op(arg, "stringcode", "implement of stringcode"){}
	virtual void exec();
	virtual void help();

private:
	void do_038_countandsay();
	void do_012_decodeways();
	void do_022_generateparentheses();
	void do_28_implementstrstr();
	void do_58_lengthoflastword();
	void do_017_combinationofphonenumber();
	void do_014_longestcommonprefix();
	void do_005_longestpalindromicsubstring();
	void do_395_longestsubstringwithoutrepeatchar();
	void do_093_restoreipaddress();
	void do_151_reversewordsinstring();
	void do_071_simplifypath();
	void do_125_validpalindrome();
	void do_020_validparentheses();

};

#endif
