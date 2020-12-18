#pragma once
#include "LoadFileToString.hpp"
#include "IncludeNotLoadedException.hpp"
#include <string>
#include <unordered_map>

class IncludesResource{

	// Loads and stores include path data

public:
	static void load(const std::string& include_path){
		if(!is_loaded(include_path)){
			std::cout << "Loading: " + include_path << std::endl;
			const std::shared_ptr<ILoadString> string_loader = std::make_shared<LoadFileToString>(include_path);
			m_includes_cache[include_path] = string_loader->load();
		}
	}

	static std::string get(const std::string& include_path){

		try{
			if (!is_loaded(include_path)) {
				throw IncludeNotLoadedException(include_path);
			}
			return m_includes_cache.at(include_path);
		}

		catch (IncludeNotLoadedException& load_error) {
			std::cerr << load_error.what() << std::endl;
			exit(1);
		}		
	}

	
private:
	IncludesResource() = default;
	
	static bool is_loaded(const std::string& include_path){
		const auto it = m_includes_cache.find(include_path);
		if (it == m_includes_cache.end()) {
			return false;
		}
		return true;
	}
	
	// <include path, include data>
	static std::unordered_map<std::string, std::string> m_includes_cache;
	
};

std::unordered_map<std::string, std::string> IncludesResource::m_includes_cache;