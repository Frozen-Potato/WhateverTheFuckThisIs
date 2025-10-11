# Day 4 – gRPC

---

## Main Purposes:
- Understanding and Implementing simple log service with gRPC using existing MongoDB logger.
---

## Objectives
- Installing protobuf(snap)/proto-compiler(apt)
- Create gRPC proto schema and gernerate code from it using **protoc**
- Implement gRPC server.
---

## Others
- mindmap for gRPC

---

## GRPCURL

```bash
grpcurl -plaintext localhost:50051 list
grpcurl -plaintext -d '{"level": "INFO"}' localhost:50051 library.LogService/GetLogs
```


