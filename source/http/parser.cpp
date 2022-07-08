#include <http/parser.h>
#include <iostream>
#include <utils/tools.h>
#include <utils/bashhttp.h>
#include <conf/vars.h>
#include <string>
#include <http/HttpResponse.h>

void parser(HttpRequest *request){
    std::string http_content = request->read();
    if(check_http(http_content)){
        request->path = get_http_path(http_content);
        request->method = get_http_method(http_content);
        request->body = get_http_body(http_content);
        request->headers = get_http_headers(http_content);
        
    }else{
        HttpResponse(request,"ERROR YOUR REQUEST!");
        log("[-] "+request->ip +" is not a http request! ");
        request->rm();
    }
}
