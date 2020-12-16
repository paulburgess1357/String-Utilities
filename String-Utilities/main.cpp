#include <iostream>
#include "Load/ILoadString.hpp"
#include "Load/LoadFileToString.hpp"
#include "Process/ProcessIncludes.hpp"
#include "Find/SubString.hpp"
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
	const std::vector<size_t> all_indices = SubString::find_all_starting_indices(loaded_string, "#include");
	print(all_indices);
}

void load_includes(){
	
	const std::shared_ptr<ILoadString> string_loader = std::make_shared<LoadFileToString>("c:/users/paulb/desktop/test_string_file.glsl");
	const std::string loaded_string = string_loader->load();
	ProcessIncludes process_includes{ loaded_string };
	process_includes.load_includes();

	
}

int main(){

	load_includes();
}