#include <iostream>
#include "string_util/LoadFileToString.hpp"
#include "string_util//ProcessIncludes.hpp"
#include "string_util//SubString.hpp"
#include "string_util//FilePath.hpp"
#include "string_util//WriteToFile.hpp"
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
	const std::string loaded_string = StringUtil::LoadFileToString::load("c:/users/paulb/desktop/test_string_file.glsl");	
	print(loaded_string);
}

void find_starting_indices(){
	const std::string loaded_string = StringUtil::LoadFileToString::load("c:/users/paulb/desktop/test_string_file.glsl");
	const std::vector<size_t> all_indices = StringUtil::SubString::find_all_starting_indices(loaded_string, "#include");
	print(all_indices);
}

void load_includes(){	
	const std::string loaded_string = StringUtil::LoadFileToString::load("include/Tests/IncludeExamples/fragment_shader.glsl");
	const std::string new_string = StringUtil::ProcessIncludes::process(loaded_string);
	print(new_string);	
}

void filepath(){
	std::string path = "c:/users/paulb/desktop/include_testing/include_test_file.txt";
	std::string result1 = StringUtil::FilePath::get_filename(path);
	std::string result2 = StringUtil::FilePath::get_directory(path);
	std::string result3 = StringUtil::FilePath::get_extension(path);
	print(result1);
	print(result2);
	print(result3);
}

void write(){
	const std::string loaded_string = StringUtil::LoadFileToString::load("include/Tests/IncludeExamples/fragment_shader.glsl");
	const std::string new_string = StringUtil::ProcessIncludes::process(loaded_string);
	StringUtil::WriteToFile::write(new_string, "C:/users/paulb/desktop/paulwashere.txt");
}

int main(){
	filepath();
}