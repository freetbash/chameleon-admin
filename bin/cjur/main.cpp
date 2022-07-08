
#include <config/setting.h>
// init urls  -IBASE_DIR

int main(int argc, char *argv[]){
    Cmd *cmd = new Cmd(argc,argv);
    cmd->init();
    // urls init
    {
        chameleon_urls_init();
        test_app_urls_init();
    }
    cmd->compare();

    return 0;
}
