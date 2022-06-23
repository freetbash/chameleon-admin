#include <main.h>

void new_app(std::string app_name){
    std::string app_dir = _root+"/apps/"+app_name;
    c_mkdir(app_dir);
    c_mkdir(app_dir+"/views");
    std::ofstream views;
    views.open(app_dir+"/views.h",std::ios::out);
{views<<R""(#ifndef PROJECT_APP1_VIEWS
#define PROJECT_APP1_VIEWS
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
// urls.cpp
void app1_urls_init();

namespace App1
{
    void test(HttpRequest *request);
} // namespace App1


#endif)"";

}views.close();


    std::ofstream test;
    test.open(app_dir+"/views/test.cpp",std::ios::out);
{test<<R""(#include <apps/app1/views.h>
// app1.views.o
void App1::test(HttpRequest *request){
    HttpResponse(request,"test");
})"";

}test.close();

    std::ofstream urls;
    urls.open(app_dir+"/urls.cpp",std::ios::out);
{urls<<R""(#include <app/views.h>
#include <chameleon/conf/vars.h>

void app1_urls_init(){
url_patterns
            ->path("/app1",(void *)App1::test)
    ;
}

)"";

}urls.close();


    std::ofstream models;
    models.open(app_dir+"/models.cpp",std::ios::out);
{models<<R""()"";

}models.close();

    log("Please insert "+app_name+" into chameleon.toml[apps]]");
}