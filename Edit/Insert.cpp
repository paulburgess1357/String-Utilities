#include "Insert.h"
#include "LineWarning.h"
#include <sstream>


std::string StringUtil::Edit::Insert::insert_above(
	const std::string& parse_string, const std::string& concat_string, 
	const size_t edit_line_num) {

	std::stringstream ss(parse_string);
	std::string to;
	std::ostringstream results;

	size_t line_num = 1;
	while (std::getline(ss, to, '\n')) {

		if (line_num == edit_line_num) {
			results << insert_above(to, concat_string);
		} else {
			results << to;
		}

		if (ss.good()) {
			results << '\n';
			line_num++;
		}
	}

	StringUtil::Edit::LineWarning::check_line_num(line_num, edit_line_num);
	return results.str();
}

std::string StringUtil::Edit::Insert::insert_above(const std::string& parse_string, 
const std::string& concat_string) {
	return concat_string + '\n' + parse_string;
}

std::string StringUtil::Edit::Insert::insert_below(
	const std::string& parse_string, const std::string& concat_string, 
	const size_t edit_line_num) {

	std::stringstream ss(parse_string);
	std::string to;
	std::ostringstream results;

	size_t line_num = 1;
	while (std::getline(ss, to, '\n')) {

		if (line_num == edit_line_num) {
			results << insert_below(to, concat_string);
		} else {
			results << to;
		}

		if (ss.good()) {
			results << '\n';
			line_num++;
		}
	}

	StringUtil::Edit::LineWarning::check_line_num(line_num, edit_line_num);
	return results.str();
}

std::string StringUtil::Edit::Insert::insert_below(const std::string& parse_string, 
	const std::string& concat_string) {
	return parse_string + '\n' + concat_string;
}

std::string StringUtil::Edit::Insert::insert_front(
	const std::string& parse_string, const std::string& concat_string, 
	const size_t edit_line_num) {

	std::stringstream ss(parse_string);
	std::string to;
	std::ostringstream results;

	size_t line_num = 1;
	while (std::getline(ss, to)) {

		if (line_num == edit_line_num) {
			results << insert_front(to, concat_string);
		} else {
			results << to;
		}

		if(ss.good()){
			results << '\n';
			line_num++;
		}
	}

	StringUtil::Edit::LineWarning::check_line_num(line_num, edit_line_num);
	return results.str();
}

std::string StringUtil::Edit::Insert::insert_front(const std::string& parse_string, 
	const std::string& concat_string) {
	return concat_string + parse_string;
}

std::string StringUtil::Edit::Insert::insert_back(
	const std::string& parse_string, const std::string& concat_string, 
	const size_t edit_line_num) {

	std::stringstream ss(parse_string);
	std::string to;
	std::ostringstream results;

	size_t line_num = 1;
	while (std::getline(ss, to, '\n')) {

		if (line_num == edit_line_num) {
			results << insert_back(to, concat_string);
		} else {
			results << to;
		}

		if (ss.good()) {
			results << '\n';
			line_num++;
		}				
	}

	StringUtil::Edit::LineWarning::check_line_num(line_num, edit_line_num);
	return results.str();
}

std::string StringUtil::Edit::Insert::insert_back(const std::string& parse_string, 
	const std::string& concat_string) {
	return parse_string + concat_string;
}