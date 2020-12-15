#pragma once
#include "ILoadString.hpp"
#include "LoadFileToStringException.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

class LoadFileToString : public ILoadString{

	public:
		LoadFileToString(const std::string& file_path)
			:m_filepath{ file_path }{
			
		}
	
		std::string load() const override {

			std::stringstream ss;
			std::ifstream file;

			try {
				file.open(m_filepath);
				if (!file.fail()) {
					ss << file.rdbuf();
				} else {
					throw LoadFileToStringException(m_filepath);
				}
				file.close();
			}
			catch (LoadFileToStringException& load_error) {
				std::cerr << load_error.what() << std::endl;
				exit(1);
			}
			return ss.str();
		}

	private:
		std::string m_filepath;
		
};