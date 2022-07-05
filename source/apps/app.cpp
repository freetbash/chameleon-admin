#include <apps/app.h>
#include <cstdlib>
#include <utils/tools.h>
#include <conf/vars.h>
App::App(std::string name){
    this->name = name;


}

void App::build(std::string include_dir){
    std::string cmd;
    log("[*]Building ...("+this->name+")");
   for(std::string _:ls(root+"/apps/"+this->name+"/views/")){
        cmd="ccache g++ -c "+root+"/apps/"+this->name+"/views/"+_
            +" -I./ -I"+include_dir+" -I"+include_dir+"/chameleon"
            +" -o "+root+"/temp/"+_+".o -std=c++11 -O3";
        log("[*] "+cmd);
        check_error(system(cmd.c_str()));
   }
        cmd="ccache g++ -c "+root+"/apps/"+this->name+"/urls.cpp"
            +" -I./ -I"+include_dir+" -I"+include_dir+"/chameleon"
            +" -o "+root+"/temp/"+this->name+".urls.cpp.o -std=c++11 -O3";
        log("[*] "+cmd);
        check_error(system(cmd.c_str()));
   




}
