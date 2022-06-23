#ifndef CHAMELEON_HTTP_PARSER
#define CHAMELEON_HTTP_PARSER
#include <http/HttpRequest.h>
void parser(HttpRequest *request);
bool check_http(std::string content);
#endif