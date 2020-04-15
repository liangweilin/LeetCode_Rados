#ifndef _OP_H
#define _OP_H

#include <string>
#include "common/common.hpp"

class Op{
protected:
	Argument *argument;
	std::string name;
	std::string description;
public:
	Op(Argument *_argument):argument(_argument),name("help"),description("show this message"){}
	Op(Argument *_argument, std::string _name, std::string _description):argument(_argument),
										name(_name),
										description(_description){}

	virtual ~Op(){}

	std::string get_name(){ return name;}
	virtual void usage();
	virtual void exec() = 0;
	virtual void help() = 0;

};

#endif
