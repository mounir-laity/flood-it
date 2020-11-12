/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atl.server.g53649.model;

import atl.server.g53649.server.AbstractServer;
import atl.server.g53649.server.ConnectionToClient;
import java.io.IOException;

/**
 *
 * @author laity
 */
public class AnagramServer extends AbstractServer{
    
    private static final int PORT = 12345;
   // private final Members members;
    private int clientId;

    public AnagramServer(int port) {
        super(port);
    }

    @Override
    protected void handleMessageFromClient(Object msg, ConnectionToClient client) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
    public AnagramServer() throws IOException {
        super(PORT);
       // members = new Members();
        clientId = 0;
        this.listen();
    }
}
