# Scout: Protocol-Agnostic DNS Resolve
Scout is a modular C networking utility designed to bridge the gap between human-readable hostnames and raw binary network addresses. Built with a focus on low-level memory discipline and protocol independence.

<br>


## 🛡️ Technical Highlights
### Protocol Agnostic
Leverages the Berkeley Sockets API (getaddrinfo) to handle both IPv4 and IPv6 seamlessly without hardcoded families.

### Modular Architecture 
Clean separation of concerns with a dedicated scout engine and a separate driver logic.

### Memory Discipline
Implements manual management of addrinfo linked lists and prevents memory leaks through careful scope handling.


### Low-Level Precision
Utilizes pointer typecasting to overlay specific socket structures (sockaddr_in/in6) onto generic memory blocks. 

<br>

## Usage
Compile the program using command<br>
```make```
<br><br>Run the Program<br>
```scout <domain/hostname> <ip/service>```
