/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atl.messages.g53649.message;

import atl.messages.g53649.users.User;

/**
 *
 * @author laity
 */
public class MessageProfile implements Message {

    private final User author;

    public MessageProfile(int id, String name) {
        this.author = new User(id, name);
    }

    @Override
    public Type getType() {
        return Type.PROFILE;
    }

    @Override
    public User getAuthor() {
        return author;
    }

    @Override
    public User getRecipient() {
        return User.ADMIN;
    }

    @Override
    public Object getContent() {
        return author;
    }

}
