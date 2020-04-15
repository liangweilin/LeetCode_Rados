#include "arraycode.hpp"

void print_array(int nums[], int len){
	for (int i = 0; i< len;i++){
		cout<< nums[i] << ",";
	}
	cout << endl;
}



void ArrayCode::exec(){
	int sub_cmd = argument->get_sub_cmd();
	switch(sub_cmd){
		case SUB_CMD_ARR_TWOSUM:{
			do_001_twosum();
			break;
		}
	}

}


void ArrayCode::help(){
	cout << "Support Commands:" << endl;
	cout << "arraycode twosum" << endl;
	cout << "arraycode 3sum" << endl;

}


void ArrayCode::do_001_twosum(){
	// input param
	int input_list[] = {2,7,11,15};
	int target_num = 9;
	int len = sizeof(input_list)/ sizeof(input_list[0]);
	cout << "input: " << endl;
	print_array(input_list, len);
	cout << target_num << endl;
	cout << "result: " <<endl;
	// begin deal 
	if (len == 0) { cout << "input list is empty!" << endl;}
	map<int, int> tmap;
	for( int i=0 ;i < len ;i++ ){
		tmap.insert(make_pair(target_num-input_list[i], i));
	
	}
	for ( int i = 0 ; i < len; i++){
		map<int, int>::iterator iter = tmap.find(input_list[i]);
		if (iter!= tmap.end() && iter->second != i){ cout << "get it, index is " << i+1 << " and " << (iter->second + 1) << endl;return;}
		
	}
	cout << "can not got it!" << endl;
}	


void ArrayCode::do_015_3sum(){
	

}
