#ifndef PROJECT_test_app_VIEWS
#define PROJECT_test_app_VIEWS
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
// urls.cpp
void test_app_urls_init();

namespace test_app{
    void test(HttpRequest *request);
    void test1(HttpRequest *request);
}

#endif
