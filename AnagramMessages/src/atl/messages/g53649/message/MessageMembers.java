/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atl.messages.g53649.message;

import atl.messages.g53649.users.User;
import java.util.List;

/**
 *
 * @author laity
 */
public class MessageMembers implements Message {

    private final List<User> members;

    public MessageMembers(List<User> members) {
        this.members = members;
    }

    @Override
    public Type getType() {
        return Type.MEMBERS;
    }

    @Override
    public User getAuthor() {
        return User.EVERYBODY;
    }

    @Override
    public User getRecipient() {
        return User.ADMIN;
    }

    @Override
    public Object getContent() {
        return members;
    }

}
