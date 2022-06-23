#include <apps/app2/views.h>
#include <chameleon/conf/vars.h>

void app2_urls_init(){
url_patterns
            ->path("/app2",(void *)App2::test)
    ;
}

