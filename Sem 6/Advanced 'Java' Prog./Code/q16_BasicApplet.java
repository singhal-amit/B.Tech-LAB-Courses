import java.applet.Applet;
import java.awt.Graphics;

public class q16_BasicApplet extends Applet {
    // Override the paint method to display the message
    @Override
    public void paint(Graphics g) {
        // Display the message on the applet window
        g.drawString("Hi, This is Amit Singhal", 50, 60);
    }
}
