#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

class Op;
class Argument;


class Command{
private:
	Argument *argument;
	std::map<int, Op*> ops;
public:
	Command(Argument *_argument);
	~Command();
	void execute();
private:
	void usage();
	void help();

};


#endif
