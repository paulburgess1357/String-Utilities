#pragma once
#include <string>
#include <vector>

class ReplaceInclude{

public:

	ReplaceInclude(const std::string& original_string)
		:m_original_string{ original_string }{
		
	}

		// Locate include line
		// check if its a valid path
		// read data
		// replace that particular line

	
private:
	void get_include_start_incies(){



		
	}


	
	std::string m_original_string;
	std::vector<size_t> m_include_start_indices;

	
};
