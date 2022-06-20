#ifndef CHAMELEON_TEMPLATE_TEMPLATE
#define CHAMELEON_TEMPLATE_TEMPLATE
#include <http/HttpRequest.h>
#include <http/HttpResponse.h>
#include <string>
#include <map>
#include <utils/tools.h>
#include <conf/vars.h>

void render(HttpRequest *request,std::string template_path,std::map<std::string,std::string> args);
void file(HttpRequest *request,std::string file_path);

std::string read_file(std::string file_path);
std::string html_translator(std::string html,std::map<std::string,std::string> args);



#endif 