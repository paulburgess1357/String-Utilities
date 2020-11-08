#include "SingleLine.h"


std::vector<std::string> StringUtil::Find::SingleLine::get_strings_between(const std::string& parse_string, const std::string& val1, const std::string& val2) const {

	// Returns a vector of values for the substring

	size_t first_index = parse_string.find(val1);
	size_t second_index = parse_string.find(val2, val1.size());

	std::vector<std::string> results;

	while ((first_index != std::string::npos) & (second_index != std::string::npos)) {
		results.emplace_back(parse_string.substr(first_index + val1.size(), second_index - first_index - val1.size()));
		first_index = parse_string.find(val1, first_index + 1);
		second_index = parse_string.find(val2, second_index + 1);
	}

	return results;

}