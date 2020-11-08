#include "MultiLine.h"
#include "SingleLine.h"
#include <sstream>


std::vector<std::string> StringUtil::Find::MultiLine::get_strings_between(
	const std::string& parse_string, const std::string& val1, 
	const std::string& val2) const {

	// Returns a vector of values found between val1 and val2.  If val1 and
	// val2 occur more than once per line, each occurrence will be retained.
	// The search is limited to be per line.  This is done for every line in
	// the string

	std::vector<std::string> results;

	std::stringstream ss(parse_string);
	std::string to;

	while (std::getline(ss, to, '\n')) {

		SingleLine single_line_finder;
		std::vector<std::string> line_results{ single_line_finder.get_strings_between(to, val1, val2) };
		if (!line_results.empty()) {
			results.insert(results.end(), line_results.begin(), line_results.end());
		}
	}
	
	return results;
}

std::vector<size_t> StringUtil::Find::MultiLine::get_line_numbers(
	const std::string& parse_string, const std::string& match_value) const {

	// Returns a vector with the line numbers that the matched string was found
	// in.  This is not an exact match, it is a substring match

	std::vector<size_t> results;

	std::stringstream ss(parse_string);
	std::string to;

	int line_num = 1;
	if (!parse_string.empty()) {
		while (std::getline(ss, to, '\n')) {
			if (to.find(match_value) != std::string::npos) {
				results.push_back(line_num);
			}
			line_num++;
		}
	}
	
	return results;
}