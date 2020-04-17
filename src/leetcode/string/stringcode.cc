#include "stringcode.hpp"
#include <cstring>
#include <list>

void StringCode::exec(){
	int sub_cmd = argument->get_sub_cmd();
	switch(sub_cmd){
		case SUB_CMD_STR_COUNTANDSAY:{
			do_038_countandsay();
			break;
		}
		case SUB_CMD_STR_DECODEWAYS:{
			do_012_decodeways();
			break;
		}
		case SUB_CMD_STR_GENPARENTHESES:{
			do_022_generateparentheses();
			break;
		}
		case SUB_CMD_STR_IMPLEMENTSTR:{
			do_28_implementstrstr();			
			break;
		}
		case SUB_CMD_STR_LOFLASTWORD:{
			do_58_lengthoflastword();
			break;
		}
		case SUB_CMD_STR_COMBIOFPHNUMBER:{
			do_017_combinationofphonenumber();
			break;
		}
		case SUB_CMD_STR_LONGESTCOMMONPREFIX:{
        		do_014_longestcommonprefix();
			break;
		}
		case SUB_CMD_STR_LONGESTPALINDROMICSUBSTRING:{
        		do_005_longestpalindromicsubstring();
			break;
		}
		case SUB_CMD_STR_LONGESTSUBSTRINGWIHTOUTREPEATCHAR:{
	   		do_395_longestsubstringwithoutrepeatchar();
			break;
		}
		case SUB_CMD_STR_RESTOREIPADDRESS:{
        		do_093_restoreipaddress();
			break;
		}
		case SUB_CMD_STR_REVERSEWORDINSTRING:{
        		do_151_reversewordsinstring();
			break;
		}
		case SUB_CMD_STR_SIMPLIFYPATH:{
		        do_071_simplifypath();
			break;
		}
		case SUB_CMD_STR_VALIDPALINDROME:{
        		do_125_validpalindrome();
			break;
		}
		case SUB_CMD_STR_VALIDPARENTHESES:{
        		do_020_validparentheses();
			break;
		}



	}

}


void StringCode::help(){
	cout << "Support Commands:" << endl;
	cout << "stringcode countandsay" << endl;
	cout << "stringcode decodeways" << endl;
	cout << "stringcode generateparentheses" << endl;
	cout << "stringcode implementstrstr" << endl;
	cout << "stringcode lenoflastword" << endl;
	cout << "stringcode combineofphonenum" << endl;
	cout << "stringcode longestcommonprefix" << endl;
	cout << "stringcode longestpalindromicsubstring" << endl;
	cout << "stringcode longestsubstringwithoutrepeatchar" << endl;
	cout << "stringcode restoreipaddress" << endl;
	cout << "stringcode reversewordinstring" << endl;
	cout << "stringcode simplifypath" << endl;
	cout << "stringcode validpalindrome" << endl;
	cout << "stringcode validparentheses" << endl;
	cout << "stringcode " << endl;
}


string CountAndSay(string init){
	const char *str = init.c_str();
//	strcpy(str, init.c_str());
	string s = "";
	int len = init.length();
	int count = 1;
	char last = str[0];

	for ( int p=1; p < len; p++){
		if (str[p] == last){
			count ++;
		}else{
			s += ""+ to_string(count) +last;
			count=1;
			last = str[p];
		}
	}
	s += "" + to_string(count) + last;
	return s;

}

void StringCode::do_038_countandsay(){
	// input param
	int n = 10;
	cout << "input: " << endl;
        cout << n << endl;
        cout << "result: " <<endl;
        // begin deal
        string init = "1";
	int i = 1;
	cout << "initial round:  " << init << endl;
	for(; i<n;i++){
		init = CountAndSay(init);
		cout << i+1 << " round:         " << init << endl;
	}
}


void StringCode::do_012_decodeways(){
	// input param
	string str = "234213413341209";
//	string str = "0231212";
	cout << "input: " << endl;
        cout << str << endl;
	cout << "result: " <<endl;
	if (str.empty())
		cout << "empty input!" << endl;
	int len = str.length();
	int* count = new int[len+1]{0};
	
	count[0] = 1;
	count[1] = 0;
	if (str[0] != '0'){
		count[1] = 1;
	}
	
	for ( int i = 2; i < len + 1; i++){
		//  count[i] = count[i-1] + count[i-2];
		if (str[i-1] != '0'){
			count[i] += count[i-1];
		}
		if (str[i-2] != '0'){
			if ( (str[i-2]-'0')*10 + (str[i-1]-'0') <= 26 )
				{
					count[i] += count[i-2];
				}
		}
	}
	cout << count[len] << endl;
}	


void GenerateParentheses(string item,int open_free, int close_free, list<string> &result){
	if ( open_free > close_free ) return;
	if (open_free == 0 && close_free == 0){
		result.push_back(item);
	}
	// if ( open < close ) return;
	//
	if(open_free > 0){GenerateParentheses(item+'(', open_free-1, close_free,  result);}
	if(close_free > 0){GenerateParentheses(item+')', open_free, close_free - 1,  result);}
}

void StringCode::do_022_generateparentheses(){
	// input param
	int n = 3;
	cout << "input: " << endl;
	cout << n << endl;
	cout << "result: " << endl;
	list<string> result;
	GenerateParentheses("",n,n,result);
	list<string>::iterator iter = result.begin();
        for (;iter!=result.end();iter++){
                cout << *iter << endl;
        }	
}

void StringCode::do_28_implementstrstr(){
	// input param 
	cout << "input: " << endl;
	string str = "  hellohello hello  ";
	string substring = "el";
	cout << "str: " << str << endl;
	cout << "substring: " << substring << endl;
	cout << "result: " << endl;
	//deal 
	for (int i = 0 ;i< str.length(); i++){
		if (str.substr(i,substring.size()) == substring){
			cout << "index is " << i << endl;
		}
	}
}

void StringCode::do_58_lengthoflastword(){
	// input param
	cout << "input: " << endl;
	string str = "how do you do!  ";
	string lastword = "";
	cout << str << endl;
	int count = 0;
	int i = str.size();
	while (str[i-1] == ' ' && i > 0){
		i--;
	}

	while (str[i-1] != ' ' && i > 0){
		lastword = str[i-1] + lastword;
		count++ ;
		i--;
	}
	cout << "last word is:" <<endl;
	cout << lastword << endl;
	cout << "len of last word is:" <<endl;
	cout << count << endl;
}

void StringCode::do_017_combinationofphonenumber(){
}


void StringCode::do_014_longestcommonprefix(){
}


void StringCode::do_005_longestpalindromicsubstring(){
}

void StringCode::do_395_longestsubstringwithoutrepeatchar(){
}

void StringCode::do_093_restoreipaddress(){
}

void StringCode::do_151_reversewordsinstring(){
}

void StringCode::do_071_simplifypath(){
}

void StringCode::do_125_validpalindrome(){}

void StringCode::do_020_validparentheses(){}


