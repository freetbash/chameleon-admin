#include <http/HttpResponse.h>
#include <conf/vars.h>
#include <utils/tools.h>

HttpResponse::HttpResponse(){}

HttpResponse::HttpResponse(HttpRequest *request, std::string content){

    this->headers["Content-type"]=mimetype.find(split(request->path,"\\.").back());
    this->headers["Content-Length"]=std::to_string(content.length());
    this->headers["Date"]=http_gmtime();
    
    this->handle_statuscode_methoad(request,content);
    request->write(this->toString());
    log(" ["+request->method+"] "+request->ip+" ------------------><"+this->status_code+">("+request->path+")| "+this->headers["Content-type"]);

    request->rm();
}

std::string HttpResponse::toString(){
    return std::string(
        // first line
        HTTP_VERSION + " "+this->status_code+" "+httpcode.find(this->status_code)+HTTP_DELIM
        // headers
        +SERVER+HTTP_DELIM
        +"Content-type: "+this->headers["Content-type"]+HTTP_DELIM
        +"Content-Length: "+this->headers["Content-Length"]+HTTP_DELIM
        +"Date: "+this->headers["Date"]+HTTP_DELIM
        +HTTP_DELIM
        // content
        +this->content
    );
}

void HttpResponse::handle_statuscode_methoad(HttpRequest *request, std::string content){
    
    if(request->method == "GET"){
        this->status_code="200";
        this->content = content;

    }
    else if(request->method == "HEAD"){
        this->status_code="200";
        this->content = "";

    }
    else{
        this->status_code="501";
        this->content = this->status_code +" "+httpcode.find(this->status_code);
        this->headers["Content-Length"]=std::to_string(content.length());
        
    }
}