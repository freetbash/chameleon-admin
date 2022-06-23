#ifndef CHAMELEON_HTTP_HTTPRESPONSE
#define CHAMELEON_HTTP_HTTPRESPONSE
#include <http/HttpRequest.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <views/views.h>
#include <sys/socket.h>

#include <unistd.h>
#include <string.h>
#include <conf/vars.h>
#include <utils/tools.h>
class HttpResponse{
public:
    std::string status_code;
    std::map<std::string, std::string> headers;
    std::string content;
    HttpResponse(HttpRequest *request, std::string content);
    std::string toString();
    HttpResponse();
    
    void handle_statuscode_methoad(HttpRequest *request, std::string content);
};
void FileResponse(HttpRequest *request,std::string file_path);
void JsonResponse(HttpRequest *request, std::map<std::string,std::string> d);



#endif