#include <main.h>

#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]){
    std::string _root;
    if(argc>2){
        if(std::string(argv[1])==std::string("new")){
            if(std::string(argv[2])==std::string("app")){
                _root = get_current_dir_name();
                check();
                new_app(argv[3]);
            }else{
                _root = get_current_dir_name();
                new_project(argv[2]);
            }
        }else{
            show_help();
        }
    }else{
        show_help();
    }
    return 0;
}