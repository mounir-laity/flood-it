/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atl.server.g53649.view;

import atl.server.g53649.model.AnagramServer;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author laity
 */
public class ServerConsole implements Observer{
    public static void main(String[] args) {
        try {
            AnagramServer model = new AnagramServer();
            ServerConsole console = new ServerConsole(model);
            model.addObserver(console);
            System.out.println("Serveur démarré");
            System.out.println("");
        } catch (IOException ex) {
            Logger.getLogger(ServerConsole.class.getName()).log(Level.SEVERE, null, ex);
            System.exit(0);
        }
    }
    private final AnagramServer model;

    public ServerConsole(AnagramServer model) {
        this.model = model;
    }

    @Override
    public void update(Observable o, Object arg) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
}
