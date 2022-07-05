#ifndef CHAMELEON_PUBLIC_VARS
#define CHAMELEON_PUBLIC_VARS
#define MAX_SIZE 8192
#define MAX_CLIENTS 512

#include <string>
#include <utils/mimetype.h>
#include <utils/httpcode.h>
#include <utils/httptime.h>
#include <cmds/Cmd.h>

extern MimeType mimetype;
extern HttpCode httpcode;

extern std::string SERVER;
extern std::string HTTP_VERSION;
extern std::string HTTP_DELIM;

#include <urls/urls.h>
extern UrlPatterns *url_patterns;


#include <http/HttpServer.h>
extern HttpServer *server;

#include <apps/app.h>
#include <vector>
extern std::vector<App> INSTALLED_APPS;

extern int port;
extern std::string TEMPLATE_DIR;
extern std::string STATIC_ROOT;
extern std::string STATIC_DIR;
extern std::string BASE_DIR;
extern std::string root;
extern bool DEBUG;
#endif
