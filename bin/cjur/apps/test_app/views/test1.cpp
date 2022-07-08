
#include <apps/test_app/views.h>
void test_app::test1(HttpRequest *request){
    FileResponse(request, "template/index.html");   
}
