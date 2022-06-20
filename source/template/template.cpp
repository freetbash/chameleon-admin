#include <template/template.h>
#include <views/views.h>
void render(HttpRequest *request,std::string template_path,std::map<std::string,std::string> args){
    std::string file_path = root+"/"+template_path;
    
    if(FileExists(file_path)){
        std::string origin_html = read_file(file_path);
        std::string new_html = html_translator(origin_html,args);
        HttpResponse(request,new_html);
    }else{
        notfound(request);
    }
}


void file(HttpRequest *request,std::string file_path){
    if(FileExists(root+"/"+file_path)){
        HttpResponse(request,read_file(root+"/"+file_path));
    }else{
        notfound(request);
    }
}