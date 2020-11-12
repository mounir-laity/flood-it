package atl.messages.g53649.message;

import atl.messages.g53649.users.User;
import java.io.Serializable;

/**
 * Represents the message sent to a user or to the server
 */
public interface Message extends Serializable {

    /**
     * Return the message type.
     *
     * @return the message type.
     */
    Type getType();

    /**
     * Return the message author.
     *
     * @return the message author.
     */
    User getAuthor();

    /**
     * Return the message recipient.
     *
     * @return the message recipient.
     */
    User getRecipient();

    /**
     * Return the message content.
     *
     * @return the message content.
     */
    Object getContent();

}
