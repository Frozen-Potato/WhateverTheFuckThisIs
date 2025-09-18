# Chapter 1 Study Notes

## Chapter 1: Introduction

```mermaid
mindmap
  root((Chapter 1: Introduction))
    Protocols
      TCP
      UDP
      SCTP
      IPv4 vs IPv6
    Client/Server Model
      Client initiates
      Server responds
      Iterative servers
      Concurrent servers
    TCP/IP Stack
      Application Layer
      Transport Layer
      Network Layer
      Link Layer
    Error Handling
      System calls may fail
      Wrapper functions
      Signals (SIGPIPE)
    Portability & Standards
      POSIX compliance
      BSD history
      32-bit vs 64-bit
    First Programs
      TCP Daytime Client
      TCP Daytime Server
    Models
      OSI (7 layers)
      TCP/IP (4 layers)
    Environment
      LAN vs WAN
      Routers
      Test hosts (Linux, BSD, Solaris, etc.)

```

---

## 📌 Summary of Chapter 1
- Client/server model is the foundation of network programming.  
- TCP/IP stack is central: Application → Transport → Network → Datalink.  
- Error handling wrappers make code cleaner and safer.  
- Standards (POSIX, BSD history) ensure portability.  
- Real-world systems differ: 32 vs 64-bit, IPv4 vs IPv6, LAN vs WAN.  
