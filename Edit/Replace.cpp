#include "Replace.h"
#include "LineWarning.h"
#include <sstream>


std::string StringUtil::Edit::Replace::replace_string(
	std::string parse_string, const std::string& replacement_search,
	const std::string& replacement_string){

	// Replaces all occurrences of the found value with the replacement value
	
	size_t pos = 0;
	while ((pos = parse_string.find(replacement_search, pos)) != std::string::npos) {
		parse_string.replace(pos, replacement_search.length(), replacement_string);
		pos += replacement_string.length();
	}
	return parse_string;	
}

std::string StringUtil::Edit::Replace::replace_entire_line(
	const std::string& parse_string, const size_t edit_line_num,
	const std::string& replacement_string){

	// Replaces a single line in a string
	
	std::stringstream ss(parse_string);
	std::string to;
	std::ostringstream results;

	size_t line_num = 1;
	while (std::getline(ss, to, '\n')) {
		if (line_num == edit_line_num) {
			results << replacement_string;
		} else{
			results << to;
		}

		if (ss.good()) {
			results << '\n';
			line_num++;
		}
	}

	LineWarning::check_line_num(line_num, edit_line_num);
	return results.str();
}
