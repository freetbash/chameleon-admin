#include <urls/urls.h>
#include <views/views.h>
#include <tool/tools.h>
#include <conf/vars.h>
#include <string>
#include <map>
#include <regex>
void UrlPatterns::match(HttpRequest *request){

    std::string mode = contain(request,url_patterns);
    if(mode!="chameleon_not_found"){
        void *fuck = url_patterns->patterns[mode];
        ((void (*)(HttpRequest *))fuck)(request);
    }else{
        notfound(request);
    }
}

std::string contain(HttpRequest *request,UrlPatterns *url_patterns){
    std::smatch results;
	std::string path=request->path;//"/asec/<asdasd>/<name>/<id>/";// --> /asec/(.*?)/(.*?)             /asec/qwexqwc/2
	// url path /asec/<name>  -> /asec/(.*?)
    for(auto _:url_patterns->patterns){
	    std::string url_p=_.first;
	    std::regex dp("<([\\w-\\.]+)>");
	    std::vector<std::string> headers;
	    std::vector<std::string> values;
	    std::string t=url_p;
	    t=std::regex_replace(t,dp,"([\\w-\\.]+)");
	    for (std::sregex_iterator it(url_p.begin(), url_p.end(), dp), end_it; it != end_it; ++it){
		    headers.push_back((*it)[1]);
	    }
	    std::regex cs(t);
        if(std::regex_match(path,results,cs)){
            if(results.size()-1 == headers.size()){
                for(int i=1;i<results.size();i++){
                    values.push_back(results[i]);
                }
            }
            for(int j=0;j<headers.size();j++){
                request->path_data[headers[j]]=values[j];
            }
            return url_p;
        }
    }
    return "chameleon_not_found";
}