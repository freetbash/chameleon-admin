
#include <config/setting.cpp>
// init urls  -IBASE_DIR

int main(int argc, char *argv[]){
    Cmd *cmd = new Cmd(argc,argv);
    // urls init
    {
        test_app_urls_init();
    }
    cmd->init();

    return 0;
}