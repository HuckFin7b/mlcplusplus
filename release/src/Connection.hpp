
#ifndef __MLCLIENT_CONNECTION__
#define __MLCLIENT_CONNECTION__

#include <cpprest/http_client.h>

#include "MLCPlusPlus.hpp"
#include "Response.hpp"
#include "internals/AuthenticatingProxy.hpp"

namespace mlclient {

class Connection {

public:
    Connection();
    ~Connection();

    void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, const bool usessl);
    void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password);
    // TODO anonymous connection support
    // TODO Kerberos connection support
    // TODO test BASIC and DIGEST and BASIC+DIGEST authentication methods

    // BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
    Response doGet(const std::string& pathAndQuerystring);
    Response doPut(const std::string& pathAndQuerystring,const web::json::value& payload);
    Response doPost(const std::string& pathAndQuerystring,const web::json::value& payload);
    // TODO XML payload
    // TODO multipart payload
    Response doDelete(const std::string& path);


    // Wrapped and supported functions
    Response getDocument(const std::string& uri);
    Response saveDocument(const std::string& uri,const web::json::value& payload);
    // TODO save JSON with directory, no uri
    // TODO optional parameters (collection, security, etc.)
    // TODO save XML with and without URI

    // Multi part MIME saveAll function V7+
    //Response saveAllDocuments(const std::string& uris[], const web::json::value& documents[]);
    // TODO XML save all
    // TODO multiple responses when paging in N number of doc transactions

    // CLASHES WITH QTEXT VERSION Response search(const web::json::value& searchQuery,const std::string& options);
    // TODO search with options document (combined query)
    Response search(const web::json::value& searchQuery,const web::json::value& options);
    Response search(const web::json::value& searchQuery,const std::string& qtext);
    Response search(const web::json::value& searchQuery,const std::string& qtext,const web::json::value& options);
    // TODO search with XML instead of JSON

private:
    std::string _serverUrl;
    internals::AuthenticatingProxy _proxy;

    // prevent compiler automatically defining the copy constructor and assignment operator:-
    //Connection(const Connection&);
    //Connection& operator= (const Connection&);

    Response _dosearch(const web::json::value& combined);
};

}

#endif /* defined __MLCLIENT_CONNECTION__ */