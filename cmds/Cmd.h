#ifndef CHAMELEON_CMDS_CMD
#define CHAMELEON_CMDS_CMD
#include <string>
#include <vector>
class Cmd{
public:
    std::string config_path;
    int port;
    Cmd(int argc,char *argv[]);
    void init();
private:
    void start();
    void compare();

};
#endif