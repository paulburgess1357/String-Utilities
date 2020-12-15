#pragma once
#include <string>
#include <vector>

class FindSubstring{

public:
	static std::vector<size_t> find(const std::string& search_string, const std::string& find_string){

		// Returns a vector of all the starting indices of the substring
		
		std::vector<size_t> string_positions;
		size_t position = search_string.find(find_string);

		while(position != std::string::npos){
			string_positions.push_back(position);
			position = search_string.find(find_string, position + 1);
		}

		return string_positions;
	}
	
};