#ifndef _ARRAYCODE_H
#define _ARRAYCODE_H

#include "op/op.hpp"


class ArrayCode:public Op{
private:
	
public:
	ArrayCode(Argument *arg):Op(arg, "arraycode", "implement of arraycode"){}
	virtual void exec();
	virtual void help();

private:
	void do_001_twosum();
	void do_015_3sum();
};

#endif
