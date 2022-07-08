#include "conf/vars.h"
#include <main.h>
#include <iostream>
#include <string>
#include <exception>

using namespace std;
int main(int argc, char *argv[]){
    root = get_current_dir_name();
        if(std::string(argv[1])==std::string("new")){
            if(std::string(argv[2])==std::string("app")){
                check();
                new_app(argv[3]);
            }else{
                new_project(argv[2]);
            }
        }else if(std::string(argv[1])==std::string("build")){
            check();
            if(argc==4){
                try{
                    std::string include_dir(argv[2]);
                    std::string lib(argv[3]);
                    build(include_dir,lib);
                } catch (std::logic_error e1){
                    build("/home/bash/Projects","/home/bash/Projects/chameleon/bin");
                }
            }else{
                    build("/home/bash/Projects","/home/bash/Projects/chameleon/bin");
            }
        }
    return 0;
}
