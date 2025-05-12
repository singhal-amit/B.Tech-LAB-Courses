// WAP to implement a moving banner in java using applet and threads.

import javax.swing.*;
import java.awt.*;

public class q17_MovingBanner extends JPanel implements Runnable {
    private String message = "Welcome to Java Programming!"; // Message to display
    private int xPos = 100; // Initial position of the text
    private int yPos = 50; // Y-coordinate of the text
    private Thread thread;

    public q17_MovingBanner() {
        thread = new Thread(this);
        thread.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawString(message, xPos, yPos);
    }

    @Override
    public void run() {
        while (true) {
            xPos -= 2; // Move the text to the left

            // If the text moves completely off screen, reset its position
            if (xPos < -getFontMetrics(getFont()).stringWidth(message)) {
                xPos = getWidth();
            }

            repaint(); // Redraw the panel

            try {
                Thread.sleep(50); // Control the speed of movement
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Moving Banner Example");
        q17_MovingBanner panel = new q17_MovingBanner();

        frame.add(panel);
        frame.setSize(400, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

/*
  import java.applet.Applet;
  import java.awt.*;

  public class q17_MovingBanner extends Applet implements Runnable {
    private String message = "Welcome to Java Programming!";
    private int xPos = 100; // Initial position of the text
    private int yPos = 50; // Y-coordinate of the text
    private Thread thread;

    @Override
    public void init() {
      thread = new Thread(this);
      thread.start();
    }

    @Override
    public void run() {
      while (true) {
        xPos -= 2; // Move the text to the left

        // If the text moves completely off screen, reset its position
        if (xPos < -getFontMetrics(getFont()).stringWidth(message)) {
          xPos = getWidth();
        }

        repaint(); // Redraw the applet

        try {
          Thread.sleep(50); // Control the speed of movement
        } catch (InterruptedException e) {
          Thread.currentThread().interrupt();
        }
      }
    }

    @Override
    public void paint(Graphics g) {
      g.drawString(message, xPos, yPos);
    }

    @Override
    public void stop() {
      thread = null; // Stop the thread when applet is stopped
    }
  }
*/

/*
  <html>
      <body>
          <applet code="q17_MovingBanner.class" width="400" height="150"></applet>
      </body>
  </html>
 */
