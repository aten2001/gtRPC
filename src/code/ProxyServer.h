/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ProxyServer_H
#define ProxyServer_H

#include <thrift/TDispatchProcessor.h>
#include "proxy_types.h"

namespace RPC {

class ProxyServerIf {
 public:
  virtual ~ProxyServerIf() {}
  virtual void getPage(std::string& _return, const std::string& addr) = 0;
};

class ProxyServerIfFactory {
 public:
  typedef ProxyServerIf Handler;

  virtual ~ProxyServerIfFactory() {}

  virtual ProxyServerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ProxyServerIf* /* handler */) = 0;
};

class ProxyServerIfSingletonFactory : virtual public ProxyServerIfFactory {
 public:
  ProxyServerIfSingletonFactory(const boost::shared_ptr<ProxyServerIf>& iface) : iface_(iface) {}
  virtual ~ProxyServerIfSingletonFactory() {}

  virtual ProxyServerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ProxyServerIf* /* handler */) {}

 protected:
  boost::shared_ptr<ProxyServerIf> iface_;
};

class ProxyServerNull : virtual public ProxyServerIf {
 public:
  virtual ~ProxyServerNull() {}
  void getPage(std::string& /* _return */, const std::string& /* addr */) {
    return;
  }
};

typedef struct _ProxyServer_getPage_args__isset {
  _ProxyServer_getPage_args__isset() : addr(false) {}
  bool addr :1;
} _ProxyServer_getPage_args__isset;

class ProxyServer_getPage_args {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  ProxyServer_getPage_args(const ProxyServer_getPage_args&);
  ProxyServer_getPage_args& operator=(const ProxyServer_getPage_args&);
  ProxyServer_getPage_args() : addr() {
  }

  virtual ~ProxyServer_getPage_args() throw();
  std::string addr;

  _ProxyServer_getPage_args__isset __isset;

  void __set_addr(const std::string& val);

  bool operator == (const ProxyServer_getPage_args & rhs) const
  {
    if (!(addr == rhs.addr))
      return false;
    return true;
  }
  bool operator != (const ProxyServer_getPage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProxyServer_getPage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ProxyServer_getPage_args& obj);
};


class ProxyServer_getPage_pargs {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};


  virtual ~ProxyServer_getPage_pargs() throw();
  const std::string* addr;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ProxyServer_getPage_pargs& obj);
};

typedef struct _ProxyServer_getPage_result__isset {
  _ProxyServer_getPage_result__isset() : success(false) {}
  bool success :1;
} _ProxyServer_getPage_result__isset;

class ProxyServer_getPage_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  ProxyServer_getPage_result(const ProxyServer_getPage_result&);
  ProxyServer_getPage_result& operator=(const ProxyServer_getPage_result&);
  ProxyServer_getPage_result() : success() {
  }

  virtual ~ProxyServer_getPage_result() throw();
  std::string success;

  _ProxyServer_getPage_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const ProxyServer_getPage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProxyServer_getPage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProxyServer_getPage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ProxyServer_getPage_result& obj);
};

typedef struct _ProxyServer_getPage_presult__isset {
  _ProxyServer_getPage_presult__isset() : success(false) {}
  bool success :1;
} _ProxyServer_getPage_presult__isset;

class ProxyServer_getPage_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~ProxyServer_getPage_presult() throw();
  std::string* success;

  _ProxyServer_getPage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ProxyServer_getPage_presult& obj);
};

class ProxyServerClient : virtual public ProxyServerIf {
 public:
  ProxyServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ProxyServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getPage(std::string& _return, const std::string& addr);
  void send_getPage(const std::string& addr);
  void recv_getPage(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ProxyServerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ProxyServerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ProxyServerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getPage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ProxyServerProcessor(boost::shared_ptr<ProxyServerIf> iface) :
    iface_(iface) {
    processMap_["getPage"] = &ProxyServerProcessor::process_getPage;
  }

  virtual ~ProxyServerProcessor() {}
};

class ProxyServerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ProxyServerProcessorFactory(const ::boost::shared_ptr< ProxyServerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ProxyServerIfFactory > handlerFactory_;
};

class ProxyServerMultiface : virtual public ProxyServerIf {
 public:
  ProxyServerMultiface(std::vector<boost::shared_ptr<ProxyServerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ProxyServerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ProxyServerIf> > ifaces_;
  ProxyServerMultiface() {}
  void add(boost::shared_ptr<ProxyServerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getPage(std::string& _return, const std::string& addr) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getPage(_return, addr);
    }
    ifaces_[i]->getPage(_return, addr);
    return;
  }

};

} // namespace

#endif