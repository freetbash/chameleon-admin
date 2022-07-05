#ifndef CHAMELEON_TEST_PROJECT
#define CHAMELEON_TEST_PROJECT


#include <chameleon/conf/vars.h>

#include <config/urls.cpp>


std::string TEMPLATE_DIR = BASE_DIR + "/template";
std::string STATIC_DIR = BASE_DIR + "/static";
std::string STATIC_ROOT = "/static/";



// Apps
std::vector<App> INSTALLED_APPS = {
    App("test_app"),
};

#endif