#include <app/views.h>
#include <chameleon/conf/vars.h>

void app1_urls_init(){
url_patterns
            ->path("/app1",(void *)App1::test)
    ;
}

