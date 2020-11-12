package atl.messages.g53649.users;

import java.io.Serializable;

/**
 * The <code> User </code> represents a connected user.
 */
public class User implements Serializable {

    /**
     * Represents the administrator.
     */
    public static final User ADMIN = new User(0, "ADMIN");
    public static final User EVERYBODY = new User(0, "EVERYBODY");

    private final int id;
    private String name;
    
    public User(int id, String name) {
        this.id = id;
        this.name = name;
    }

    
    public String getName() {
        return name;
    }

    boolean sameUser(int id) {
        return this.id == id;
    }

    /**
     * Return the userID.
     *
     * @return the userID.
     */
    public int getId() {
        return id;
    }

    void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name + "(" + id + ")";
    }

}
