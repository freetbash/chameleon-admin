#include <main.h>
#include <unistd.h>
#include <string>

void new_project(std::string project_name_){
    project_name = project_name_;
    std::string project_dir = _root+"/"+project_name;
    c_mkdir(project_dir);
    c_mkdir(project_dir+"/apps");
    c_mkdir(project_dir+"/config");
    c_mkdir(project_dir+"/template");
    std::ofstream chameleon;
    chameleon.open((project_dir+"/chameleon.toml"),std::ios::out);
{chameleon <<
"[chameleon]"<<std::endl<<"name=\""<<project_name<<"\""
<<
R""(
version="0"
port=3147
debug=true
apps=[
    "app1"
])"";}chameleon.close();


    std::ofstream setting;
    setting.open((project_dir+"/config/setting.cpp"),std::ios::out);
{setting << R""(#ifndef CHAMELEON_TEST_PROJECT
#define CHAMELEON_TEST_PROJECT


#include <chameleon/conf/vars.h>

#include <config/urls.cpp>


std::string TEMPLATE_DIR = BASE_DIR + "/template";
std::string STATIC_DIR = BASE_DIR + "/static";
std::string STATIC_ROOT = "/static/";



// Apps
std::vector<App> INSTALLED_APPS = {
    App("app1"),
};

#endif)"";

}setting.close();

std::ofstream urls;
    urls.open((project_dir+"/config/urls.cpp"),std::ios::out);
{urls << R""(// url
#include <apps/app1/urls.cpp>)"";}urls.close();


std::ofstream main;
    main.open((project_dir+"/main.cpp"),std::ios::out);
{main << R""(
#include <config/setting.cpp>
// init urls  -IBASE_DIR

int main(int argc, char *argv[]){
    Cmd *cmd = new Cmd(argc,argv);
    // urls init
    {
        app1_urls_init();
    }
    cmd->init();

    return 0;
})"";}main.close();

    new_app("app1");
}