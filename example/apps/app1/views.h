#ifndef PROJECT_APP1_VIEWS
#define PROJECT_APP1_VIEWS
#include <chameleon/http/HttpRequest.h>
#include <chameleon/http/HttpResponse.h>
// urls.cpp
void app1_urls_init();

namespace App1
{
    void test(HttpRequest *request);
} // namespace App1


#endif