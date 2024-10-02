import requests
import threading


# Function to send GET request
def send_get_request():
    url = "http://127.0.0.1:8080"  # Your local IP address
    response = requests.get(url)
    print(f"Response from {url}: {response.text}")


# Create and start 10 threads to send GET requests
threads = []
for _ in range(10):
    thread = threading.Thread(target=send_get_request)
    threads.append(thread)
    thread.start()

# Wait for all threads to complete
for thread in threads:
    thread.join()
