// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ProxyServer.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <curl/curl.h>
#include "cache.h"
#include <iostream>
#include <cstdio>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::RPC;

/////////////////////////////////////////////////////////////////////
//       complementary structures,functions,classes                // 
/////////////////////////////////////////////////////////////////////
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
  webpage *wp_ptr = (webpage *)userp;
  while(wp_ptr->len + (size * nmemb) >= wp_ptr->size) {
    wp_ptr->data = (char*)realloc(wp_ptr->data, wp_ptr->size*2);
    wp_ptr->size*=2;
  }
  memcpy(wp_ptr->data + wp_ptr->len, buffer, size * nmemb);
  wp_ptr->len+=size*nmemb;

  return size * nmemb;
}

bool download_webpage(const std::string &url, webpage &wp){
  CURL *curl;
  CURLcode res;
      
  memset(&wp, 0, sizeof(wp));
  curl = curl_easy_init();
    
  if(NULL != curl) {
    wp.size = 1024;
    wp.data = (char*)malloc(wp.size);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &wp);
    res = curl_easy_perform(curl);
    
    if(res != CURLE_OK){
      fprintf(stderr, "curl_easy_perform() failed.\n");
      return false;
    }
    
    curl_easy_cleanup(curl);
    return true;
  }
  else {
    fprintf(stderr, "Error: could not get CURL handle.\n");
    return false;
  }
}

int total_hit=0;

/////////////////////////////////////////////////////////////////////
//                   Proxy Server Handler                          // 
/////////////////////////////////////////////////////////////////////
class ProxyServerHandler : virtual public ProxyServerIf {
 public:
  Cache cache;
  
  /* constructor */
  ProxyServerHandler() : cache(1 << 20) { }//20->18

  /*  member functions */
  void getPage(sendData& _return, const std::string& url) {    
    webpage wp;
    bool hit = cache.get(url, wp); printf("%d\n", hit);
    if(hit) { 
      _return.webcontent = std::string(wp.data, wp.len);
      _return.doesSucceed = true;
      cache.printCache();
      total_hit++;
    } 
    else { // not found 
      bool doesSucceed = download_webpage(url, wp);
      if ( doesSucceed ){
	_return.webcontent = std::string(wp.data, wp.len);
	_return.doesSucceed = true; 
	cache.put(url, wp); 
      }
      else {
	_return.doesSucceed = false;
      }
      //free(wp.data); // do not free here
      cache.printCache();
    }
    printf("total hit till now:%d\n",total_hit);
  }
};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ProxyServerHandler> handler(new ProxyServerHandler());
  shared_ptr<TProcessor> processor(new ProxyServerProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

