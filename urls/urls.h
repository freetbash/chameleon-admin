#ifndef CHAMELEON_URLS_URLS
#define CHAMELEON_URLS_URLS
#include <map>
#include <string>
#include <http/HttpRequest.h>

class UrlPatterns{
public:
    std::map<std::string, void *> patterns;
    static void match(HttpRequest *request);
    UrlPatterns *const path(std::string path,void *fuck);
};
std::string contain(HttpRequest *request,UrlPatterns *url_patterns);
void initUrls();






#endif