#include "LoadFromFile.h"
#include <iostream>


StringUtil::Exceptions::LoadFromFile::LoadFromFile(const std::string& file_path)
	:m_error_string{"Unable to load file: " + file_path}{
}

const char* StringUtil::Exceptions::LoadFromFile::what() const{
	return m_error_string.c_str();
}

