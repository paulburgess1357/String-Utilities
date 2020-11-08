#include "LineWarning.h"
#include <iostream>


void StringUtil::Edit::LineWarning::check_line_num(size_t max_line_num, size_t edit_line_num){
	if (edit_line_num > max_line_num) {
		std::cout << "Warning: Max line count is: " << max_line_num
			<< ".  User defined edit line number is: " << edit_line_num
			<< ".  No edits have been made to the file.  " << std::endl;
	}
}

