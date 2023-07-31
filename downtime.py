import bisect
n, k = map(int, input().split())

no_servers = 0

l = [int(input()) for _ in range(n)]

# Loop until all requests are processed 
while len(l) != 0:
    no_servers += 1
    
    __k = k
    
    # Simulate processing requests on servers (each server can handle '__k' requests simultaneously)
    while __k != 0:
        # Initialize 'next' to 0 to keep track of the next request index to be processed
        next = 0
        
        # Decrement '__k' indicating a server's capacity is being used to handle a request
        __k -= 1
        
        # Continue processing requests until either all servers are occupied ('__k == 0')
        # or there are no more requests left in the list ('len(l) == 0')
        while next < len(l) and len(l) != 0:
            # Calculate the next index where the request will be processed using 'bisect.bisect_left'
            next = bisect.bisect_left(l, l.pop(next) + 1000)
            
print(no_servers)
