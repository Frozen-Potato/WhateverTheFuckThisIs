# Chapter 2 

## Mind Map

```mermaid
mindmap
  root((Chapter 2: Transport Layer))
    TCP
      Reliable
      Connection-oriented
      Ordered
    UDP
      Fast
      Connectionless
      Unreliable
    SCTP
      Message-oriented
      Multi-streaming
      Multihoming
    Ports
      Well-known ports
      Ephemeral ports
    Performance
      Buffers
      Delayed ACK
```

---

## Flowcharts for Protocols

### 1. TCP — Connection-Oriented & Reliable

```mermaid
sequenceDiagram
    participant Client
    participant Server

    Client->>Server: SYN
    Server->>Client: SYN+ACK
    Client->>Server: ACK
    Client->>Server: send("Hello")
    Server->>Client: send("Hi")
    Client->>Server: close()
    Server->>Client: close()

```

Shows the **3-way handshake**, reliable data transfer with ACKs, and proper termination.  

---

### 2. UDP — Connectionless & Fast

```mermaid
flowchart TD
  A[Client: Send Datagram] --> B[Network]
  B --> C[Server: Receive Datagram]
  C --> D[Process or Drop]
```

No handshake, no guarantees → simple but fast.  

---

### 3. SCTP — Advanced Transport Protocol

```mermaid
flowchart TD
  A[Association Setup] --> B[Multi-Stream Established]
  B --> C[Data Sent Across Multiple Streams]
  C --> D[Handles Message Boundaries]
  C --> E["Supports Multiple IP Paths (Multihoming)"]
  D --> F[Association Termination]
```

Keeps **message boundaries**, avoids head-of-line blocking, and supports multiple IP addresses.  

---

## ✅ Summary
- **TCP** = Reliable phone call (handshake, ACKs, ordered).  
- **UDP** = Quick postcard (fast, but can be lost).  
- **SCTP** = Phone system with multiple lines (advanced features: streams + multihoming).  
