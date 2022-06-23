#include <apps/app1/views.h>
// app1.views.o
void App1::test(HttpRequest *request){
    HttpResponse(request,"test");
}