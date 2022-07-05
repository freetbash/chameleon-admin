#include <main.h>

#include <iostream>
#include <string>
#include <exception>

using namespace std;
int main(int argc, char *argv[]){
    if(argc>2){
        if(std::string(argv[1])==std::string("new")){
            if(std::string(argv[2])==std::string("app")){
                cwd = get_current_dir_name();
                check();
                new_app(argv[3]);
            }else{
                cwd = get_current_dir_name();
                new_project(argv[2]);
            }
        }else if(std::string(argv[1])==std::string("build")){
            try{
                std::string include_dir(argv[2]);
                build(include_dir);
            } catch (std::logic_error e1){
                build("~/.ccao/starts/");
            }
        }
    }else{
        show_help();
    }
    return 0;
}
