#include <template/template.h>
#include <views/views.h>
void render(HttpRequest *request,std::string template_path,std::map<std::string,std::string> args){
    std::string file_path = TEMPLATE_DIR+"/"+template_path;
    
    if(FileExists(file_path)){
        std::string origin_html = read_file(file_path);
        std::string new_html = html_translator(origin_html,args);
        HttpResponse(request,new_html);
    }else{
        Views::notfound(request);
    }
}


void file(HttpRequest *request,std::string file_path){
    if(FileExists(STATIC_DIR+"/"+file_path)){
        HttpResponse(request,read_file(STATIC_DIR+"/"+file_path));
    }else{
        Views::notfound(request);
    }
}
