#include "stringcode.hpp"
#include <cstring>


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
	}

}


void StringCode::help(){
	cout << "Support Commands:" << endl;
	cout << "stringcode countandsay" << endl;
	cout << "stringcode decodeways" << endl;

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


