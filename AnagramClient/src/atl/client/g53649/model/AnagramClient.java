/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atl.client.g53649.model;

import atl.client.g53649.client.AbstractClient;
import atl.messages.g53649.users.User;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author laity
 */
public class AnagramClient extends AbstractClient{
    
    private final List<User> members = new ArrayList<>();

    public AnagramClient(String host, int port) {
        super(host, port);
    }

    @Override
    protected void handleMessageFromServer(Object msg) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    public void quit() throws IOException {
        closeConnection();
    }

    public int getNbConnected() {
        return members.size();
    }

    public Object getMembers() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    public User getUser(int index) {
        if(index > members.size() || index < 0) {
            throw new IllegalArgumentException("Incorrect index" + index);
        }
        return members.get(index);
    }
    
}
