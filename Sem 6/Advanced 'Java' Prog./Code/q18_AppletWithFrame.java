import javax.swing.*;
import java.awt.*;

public class q18_AppletWithFrame extends JPanel {

    public q18_AppletWithFrame() {
        JFrame myFrame = new JFrame("Applet with Frame");

        // Create a Label in the Frame
        JLabel label = new JLabel("Hello, I am inside a Frame!", SwingConstants.CENTER);

        // Add the label to the frame
        myFrame.add(label);

        // Set frame size and make it visible
        myFrame.setSize(300, 200);
        myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myFrame.setVisible(true);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawString("This is a Applet!", 50, 50);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet with Frame");
        q18_AppletWithFrame panel = new q18_AppletWithFrame();

        frame.add(panel);
        frame.setSize(400, 250);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

/*
  import java.applet.Applet;
  import java.awt.*;

  @SuppressWarnings("removal")
  public class q18_AppletWithFrame extends Applet {

      @Override
      public void init() {
          // Create a Frame
          Frame myFrame = new Frame("Applet with Frame");

          // Create a Label in the Frame
          Label label = new Label("Hello, I am inside a Frame!");

          // Set layout and add label
          myFrame.setLayout(new FlowLayout());
          myFrame.add(label);

          // Set frame size and make it visible
          myFrame.setSize(300, 200);
          myFrame.setVisible(true);
      }

      @Override
      public void paint(Graphics g) {
          g.drawString("This is an Applet!", 50, 50);
      }
  }
 */

 /*
  <html>
      <body>
          <applet code="q18_AppletWithFrame.class" width="400" height="250"></applet>
      </body>
  </html>
  */
