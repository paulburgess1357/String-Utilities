#pragma once
#include "../Find/SubString.hpp"
#include "../Load/IncludesResource.hpp"
#include <string>
#include <vector>

// Locate include line
// check if its a valid path
// read data
// replace that particular line


class ProcessIncludes {

public:

	ProcessIncludes(const std::string& original_string)
		:m_processed_string{ original_string }{
		
	}

	void load_includes() const{

		std::vector<size_t> include_locations = SubString::find_all_starting_indices(m_processed_string, "#include");

		for(const auto& index: include_locations){

			// need to find first and 2nd index using 'index' from the loop above.  This is just reading the same section of the string each loop
			
			const size_t first_index = SubString::find_index(m_processed_string, "\"", 1);
			const size_t second_index = SubString::find_index(m_processed_string, "\"", 2);

			const std::string include_path = SubString::find_string_btwn_indices(m_processed_string, first_index + 1, second_index - 1);
			IncludesResource::load(include_path);
		}		
	}
	
private:		
	std::string m_processed_string;	
};
