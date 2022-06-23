#include <conf/vars.h>

MimeType mimetype;
HttpCode httpcode;

std::string SERVER="Server: Chameleon. by Freet";
std::string HTTP_VERSION="HTTP/1.1";
std::string HTTP_DELIM="\r\n";

int port;
bool DEBUG;
std::string TEMPLATE_DIR;
std::string STATIC_ROOT;
std::string STATIC_DIR;
std::string BASE_DIR;
UrlPatterns *url_patterns= new UrlPatterns;

HttpServer *server;