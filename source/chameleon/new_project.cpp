#include <main.h>
#include <unistd.h>
#include <string>

void new_project(std::string project_name){
    std::string project_dir = root+"/"+project_name;
    c_mkdir(project_dir);
    c_mkdir(project_dir+"/apps");
    c_mkdir(project_dir+"/temp");
    c_mkdir(project_dir+"/config");
    c_mkdir(project_dir+"/static");
    c_mkdir(project_dir+"/template");
    std::ofstream chameleon;
    chameleon.open((project_dir+"/chameleon.toml"),std::ios::out);
{chameleon <<
"[chameleon]"<<std::endl<<"name=\""<<project_name<<"\""
<<
R""(
port=3147
debug=true
TEMPLATE_DIR="/template"
STATIC_DIR="/static"
STATIC_ROOT="/static"
apps=[
    "test_app"
])"";}chameleon.close();


    std::ofstream setting;
    setting.open((project_dir+"/config/setting.h"),std::ios::out);
{setting << R""(#ifndef CHAMELEON_CONFIG_SETTINGS
#define CHAMELEON_CONFIG_SETTINGS

#include <chameleon/urls/urls.h>
#include <chameleon/conf/vars.h>

#include <config/views_urls.h>

#endif)"";

}setting.close();

std::ofstream urls;
    urls.open((project_dir+"/config/views_urls.h"),std::ios::out);
{urls << R""(#ifndef CHAMELEON_CONFIG_VIEWS_URLS
#define CHAMELEON_CONFIG_VIEWS_URLS
#include <chameleon/views/views.h>
#include <apps/test_app/views.h>


#endif
)"";}urls.close();



std::ofstream main;
    main.open((project_dir+"/main.cpp"),std::ios::out);
{main << R""(
#include <config/setting.h>
// init urls  -IBASE_DIR

int main(int argc, char *argv[]){
    Cmd *cmd = new Cmd(argc,argv);
    cmd->init();
    // urls init
    {
        chameleon_urls_init();
        test_app_urls_init();
    }
    cmd->compare();

    return 0;
})"";}main.close();
    root=project_dir;
    new_app("test_app");
}
