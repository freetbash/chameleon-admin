#include <views/views.h>
#include <string>
void Views::index(HttpRequest *request){
    HttpResponse(request,"Chameleon !");
}
// /star_name/version/star_name-version.tar.gz