#include <template/template.h>

#include <fstream>
#include <sstream>



std::string read_file(std::string file_path){
    std::ifstream in(file_path);
    std::ostringstream tmp;
    tmp << in.rdbuf();
    return tmp.str();
}