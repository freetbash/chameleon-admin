#include <cstdlib>
#include <main.h>
#include <apps/app.h>
#include <utils/toml.h>
#include <utils/tools.h>
#include <utils/colors.h>
#include <conf/vars.h>
void build(std::string include_dir,std::string lib){
    const toml::value data = toml::parse(root+"/chameleon.toml");
    const auto project_data = toml::find(data, "chameleon");

    for (std::string app :toml::find<std::vector<std::string>>(project_data, "apps")){
                App(app).build(include_dir);
        }
    std::string cmd("");
    cmd="ccache g++ "+root+"/temp/*.o "+root+"/main.cpp "
       +" -I./ -I"+include_dir+" -I"+include_dir+"/chameleon"
       +" -L"+lib+" -lchameleon"
       +" -o manage -std=c++11 -O3 -g";
    log("[*] "+cmd);
    log(color("[+]Build ok! {\n\tmanage\n}\n",GREEN));
    check_error(system(cmd.c_str()));



}
