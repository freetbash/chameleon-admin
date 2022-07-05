#ifndef __CHAMELEON_MASTER_H
#define __CHAMELEON_MASTER_H
#include <string>
#include <fstream>
#include <conf/vars.h>
#include <utils/tools.h>
void new_project(std::string project_name);
void new_app(std::string app_name);
void show_help();
void build(std::string include_dir,std::string lib);
void check();
extern std::string project_name;
#endif
