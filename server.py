from http.server import BaseHTTPRequestHandler, HTTPServer

class MyServer(BaseHTTPRequestHandler):
    def _set_response(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
    
    def do_GET(self):
        print("Hola desde el get")
        if ("/sensor1_temp") in self.path:
            sensor1_temp = self.path.split("=")[1]
            print("La temperatura es{}".format(sensor1_temp))
        self._set_response()
        self.wfile.write("Hola este es mi super server. GET request for {}".format(self.path).encode('utf-8'))

port = 7070
server_address = ('', port)
httpd = HTTPServer(server_address, MyServer)
httpd.serve_forever()

