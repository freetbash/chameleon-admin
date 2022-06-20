#include <views/views.h>
#include <conf/vars.h>


void initUrls(){
    url_patterns//->path("/",(void *)Views::index)
                ->path("/chameleon",(void *)Views::index)// /linux/x86_64/star_name/0/star_name-0.tar.gz
    ;
}