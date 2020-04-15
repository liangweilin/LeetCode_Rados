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
};

#endif
