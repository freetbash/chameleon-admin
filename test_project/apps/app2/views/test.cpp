#include <apps/app2/views.h>
// app2.views.o
void App2::test(HttpRequest *request){
    HttpResponse(request,"test");
}