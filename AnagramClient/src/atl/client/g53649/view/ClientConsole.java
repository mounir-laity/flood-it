/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atl.client.g53649.view;

import atl.client.g53649.model.AnagramClient;
import java.io.IOException;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

/**
 *
 * @author laity
 */
public class ClientConsole {

    private final AnagramClient model;
    private DateTimeFormatter formatter;

    public static void main(String[] args) throws IOException {
        AnagramClient client = null;
        String host = "localhost";
        int port = 12345;
        String name = "";
        client = new AnagramClient(host, port);
        ClientConsole console = new ClientConsole(client);
        while (true) {
            console.showCommands();
            console.askCommand();
        }
    }

    public ClientConsole(AnagramClient client) {
        this.model = client;
        formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
        //this.model.addObserver(this);
    }

    private void showCommands() {
        System.out.println("");
        System.out.println("Liste des commandes : ");
        System.out.println("\tProposer un mot\t:\tcheck <MOT>");
        System.out.println("\tPasser le mot courant\t:\tpass");
        System.out.println("\tAfficher la liste de utilisateurs connectés\t:\tlist");
        System.out.println("\tSe deconnecter\t:\tquit");
        System.out.println("");
    }

    private void askCommand() throws IOException {
        Scanner kb = new Scanner(System.in);
        while (true) {
            String command = kb.nextLine();
            String[] array = command.split(" ");
            switch (command) {
                case "quit":
                    System.exit(0);
                    break;
                case "list":
                    System.out.println("---- ---- LISTE DES USERS ---- ----");
                    System.out.println("Nombre d'utiisateurs en lignes : " + model.getNbConnected());
                    System.out.println("ID\tNAME");
                    for (int i = 1; i <= model.getNbConnected(); i++) {
                        System.out.print(model.getUser(i).getId() + "\t");
                        System.out.print(model.getUser(i).getName());
                        System.out.println("");
                    }
                    break;
                default:
                    break;
            }
//           if qqch ici }
        }

    }
}
