# C++ String Utilities
> Header only library with common string functions.

This String Utilities library provides an easy interface for common string functions.  The motivation behind the library creation was to create a simple way to process GLSL shaders.  As time went on, it became a more generalized string library.  

## Installation

- Clone the repo
- Copy the StringUtilities folder to wherever your include directory is located

## Usage example

#### Load file to string
```
std::string loaded_file = StringUtil::LoadFileToString::load("C:/Users/paulb/Desktop/examples/cube_colored.glsl");
```
  
  
#### Process Includes
Use include directives in your glsl (or any other string) code:

C++ Call:
```
std::string loaded_shader = StringUtil::LoadFileToString::load("C:/Users/paulb/Desktop/examples/cube_colored.glsl");
loaded_shader = StringUtil::ProcessIncludes::process(loaded_shader);
```
Example shader:
```
#version 330 core
#include "C:/users/paulb/desktop/examples/structs.glsl"

out vec4 fragment_color;
uniform vec3 cube_color;

void main() {
    fragment_color = vec4(cube_color, 1.0);
}
```
Result:
```
#version 330 core
struct DirectionalLight {
    vec3 direction;
};

struct SceneLight {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular; 
};

out vec4 fragment_color;
uniform vec3 cube_color;

void main() {
    fragment_color = vec4(cube_color, 1.0);
}
```
  
  
#### SubString
Substring functions for finding and extracting string values:
```
std::string search_string = "Lets find all the starting indices of the word: the!";
std::string find_string = "the";

// Find all starting indices:
std::vector<size_t> starting_indices = StringUtil::SubString::find_all_starting_indices(search_string, find_string); // 14, 38, 48	

// Find a specific index:
size_t second_index = StringUtil::SubString::find_index(search_string, find_string, 2); // 38

// Extract the substring between 2 values (both values are inclusive):
std::string btwn_string = StringUtil::SubString::find_string_btwn_indices(search_string, 5, 8); // find
```
  
  
#### FileSystem:
Simple file/folder functions:
```
std::string path = "C:/Users/paulb/Desktop/examples/cube_colored.glsl";
StringUtil::FilePath::get_filename(path);  // cube_colored.glsl
StringUtil::FilePath::get_directory(path); // C:/users/paulb/Desktop/examples/
StringUtil::FilePath::get_extension(path); // glsl
```
  
  
### Output:
```
std::string output_string { "Hello World!" };
StringUtil::WriteToFile::write(output_string, "C:/users/paulb/desktop/hello.txt");
```
  
  
## Release History

* 0.0.1
    * Initial Release

## Meta

Paul Burgess – paulburgess1357@gmail.com

Distributed under the MIT license. See ``LICENSE`` for more information.
https://github.com/paulburgess1357/String-Utilities/blob/master/LICENSE
