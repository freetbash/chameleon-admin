#include <cmds/Cmd.h>
#include <utils/tools.h>
#include <conf/vars.h>
#include <iostream>
#include <unistd.h>

Cmd::Cmd(int argc,char *argv[]){
    ;
}

void Cmd::init(){
    BASE_DIR = "/";
    port = 80;
    root = get_current_dir_name();

    this->start();
}

void Cmd::start(){
    server =HttpServer::build(port);
    server->Receiver();
}


