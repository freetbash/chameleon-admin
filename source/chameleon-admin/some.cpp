#include <main.h>

std::string cwd;
std::string project_name;

void check(){
    if(FileExists(cwd+"/chameleon.toml")){
        ;
    }else{
        log(color("It it not a project!",RED));
        exit(1);
    }
}
