#include <main.h>


void check(){
    if(FileExists(_root+"/chameleon.toml")){
        ;
    }else{
        log(color("It it not a project!",RED));
        exit(1);
    }
}