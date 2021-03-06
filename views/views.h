#ifndef CHAMELEON_VIEWS_VIEWS
#define CHAMELEON_VIEWS_VIEWS
#include <http/HttpRequest.h>
#include <http/HttpResponse.h>
#include <template/template.h>
#include <conf/vars.h>
namespace Views{
    void chameleon(HttpRequest *request);
    void handle_static(HttpRequest *request);
    void notfound(HttpRequest *request);
}

#endif 
