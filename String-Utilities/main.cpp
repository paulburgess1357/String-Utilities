#include <iostream>
#include "Load/ILoadString.hpp"
#include "Load/LoadFileToString.hpp"
#include "Find/FindSubstring.h"
#include <vector>

template<typename T>
void print(T val){
	std::cout << val << std::endl;
}

template<typename T>
void print(std::vector<T> val){
	for(const auto& value : val ){
		print(value);
	}
}

void load_file_to_string() {
	const std::shared_ptr<ILoadString> string_loader = std::make_shared<LoadFileToString>("c:/users/paulb/desktop/test_string_file.glsl");
	const std::string loaded_string = string_loader->load();
	print(loaded_string);
}

void find_starting_indices(){
	const std::shared_ptr<ILoadString> string_loader = std::make_shared<LoadFileToString>("c:/users/paulb/desktop/test_string_file.glsl");
	const std::string loaded_string = string_loader->load();
	std::vector<size_t> all_indices = FindSubstring::find(loaded_string, "#include");
	print(all_indices);
}

int main(){

	find_starting_indices();
}