#ifndef CHAMELEON_TEST_PROJECT
#define CHAMELEON_TEST_PROJECT


#include <chameleon/conf/vars.h>

#include <config/urls.cpp>


std::string TEMPLATE_DIR = BASE_DIR + "/template";
std::string STATIC_ROOT = "/static/";
std::string STATIC_DIR = TEMPLATE_DIR + "/static";


// Apps
std::vector<App> INSTALLED_APPS = {
    App("app1"),
    App("app2")
};

#endif