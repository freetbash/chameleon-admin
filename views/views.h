#ifndef CHAMELEON_VIEWS_VIEWS
#define CHAMELEON_VIEWS_VIEWS
#include <http/HttpRequest.h>
#include <http/HttpResponse.h>
#include <template/template.h>
namespace Views{
    void index(HttpRequest *request);
}

void notfound(HttpRequest *request);
#endif 