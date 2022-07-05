#include <main.h>
#include <iostream>
#include <string>
#include <exception>

using namespace std;
int main(int argc, char *argv[]){
    root = get_current_dir_name();
    if(argc>2){
        if(std::string(argv[1])==std::string("new")){
            if(std::string(argv[2])==std::string("app")){
                check();
                new_app(argv[3]);
            }else{
                new_project(argv[2]);
            }
        }else if(std::string(argv[1])==std::string("build")){
            check();
                try{
                    std::string include_dir(argv[2]);
                    std::string lib(argv[3]);
                    build(include_dir,lib);
                } catch (std::logic_error e1){
                    build("~/Projects","~/Projects/chameleon/bin");
                }
        }
    }else{
        show_help();
    }
    return 0;
}
