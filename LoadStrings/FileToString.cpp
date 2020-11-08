#include "FileToString.h"
#include "../Exceptions/LoadFromFile.h"
#include <fstream>
#include <sstream>
#include <iostream>


StringUtil::Load::FileToString::FileToString(const std::string& filepath)
	:m_filepath{filepath}{	
}

std::string StringUtil::Load::FileToString::load_string() const{

	std::stringstream ss;
	std::ifstream file;

	try {
		file.open(m_filepath);
		if (!file.fail()) {
			ss << file.rdbuf();
		} else {
			throw StringUtil::Exceptions::LoadFromFile(m_filepath);			
		}
		file.close();
	}
	catch (StringUtil::Exceptions::LoadFromFile& load_error) {
		std::cerr << load_error.what() << std::endl;
		exit(1);
	}
	return ss.str();	
}
