#include <http/parser.h>
#include <iostream>
#include <utils/tools.h>
#include <conf/vars.h>
#include <string.h>
#include <vector>
#include <string>
#include <regex>
#include <sys/socket.h>
#include <http/HttpResponse.h>

void parser(HttpRequest *request){
    std::string http_content = request->read();
    if(check_http(http_content)){
        std::string http_headers;

        auto _ = split(http_content,(HTTP_DELIM+HTTP_DELIM));
        http_headers = _.front(); // hreadrs
        // request body except for \r\n\r\n in post body
        _.erase(_.begin());
        for(std::string some :_){
            request->body += some;
        }

        // handle headers
        auto __ = split(http_headers,HTTP_DELIM);
        std::string first_line = __.front();
                // handle first line
                auto ___ = split(first_line," ");
                request->method = ___[0];
                request->path   = ___[1];
        
        __.erase(__.begin());
        for(std::string each_item :__){
            auto temp = split(each_item,": ");
            try{
                if(request->headers.size()==2){
                    request->headers[temp[0]]=temp[1];
                }
            }catch(const std::exception& e){
                request->bad = true;
                std::cerr << e.what() << '\n';
                HttpResponse(request,each_item);
            }
            
        }

}else{
        log("[-] "+request->ip +" is not a http request! ");
        request->rm();
}
}

bool check_http(std::string content){
    // (GET|HEAD|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH|POST)(.+)HTTP
    std::regex re_p("(GET|HEAD|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH|POST)(.+)HTTP.+");
    if(std::regex_search(content,re_p)){
        return true;
    }else{
        return false;
    }
}