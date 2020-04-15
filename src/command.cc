#include "command.hpp"
#include "common/common.hpp"

#include "op/op.hpp"
#include "leetcode/array/arraycode.hpp"
#include "leetcode/string/stringcode.hpp"

using namespace std;


Command::Command(Argument *_argument):argument(_argument){
	ops[CMD_LEETCODE_ARRAY] = new ArrayCode(_argument);
	ops[CMD_LEETCODE_STRING] = new StringCode(_argument);
}


Command::~Command(){
	map<int, Op*>::iterator iter = ops.begin();
	for(; iter!= ops.end();iter++){
		delete iter->second;
		iter->second = NULL;
	}
	ops.clear();
}


void Command::execute(){
	int cmd = argument->get_cmd();

	if ( cmd == CMD_USAGE ){
		usage();
		return;
	}

	if ( cmd == CMD_HELP ){
		help();
		return;
	}

	if ( ops.count(cmd) ){
		//ops[cmd]->exec();
		Op *op = ops[cmd];
		op->exec();
	}

}

void Command::usage(){
	map<int,Op*>::iterator iter = ops.begin();
	for (;iter != ops.end(); iter++){
		iter->second->usage();
	}
}

void Command::help(){
	string cmd_name = argument->get_cmd_name();
	map<int ,Op*>::iterator iter = ops.begin();
	for (; iter!=ops.end(); iter++)
	{
		if ( cmd_name == iter->second->get_name() ){
			iter->second->help();
		}
	}

}
