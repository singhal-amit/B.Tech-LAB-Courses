class MyThread extends Thread {
    private volatile boolean suspended = false; // Flag to manage suspension

    public void run() {
        try {
            System.out.println(Thread.currentThread().getName() + " started.");

            // Using sleep() to pause the thread for 1 second
            Thread.sleep(1000);
            System.out.println(Thread.currentThread().getName() + " slept for 1 second.");

            // Simulating wait() (but in a synchronized block)
            synchronized (this) {
                wait(1000); // Makes the current thread wait for 1 second
                System.out.println(Thread.currentThread().getName() + " resumed after waiting.");
            }

            // Check if the thread is suspended and wait
            synchronized (this) {
                while (suspended) {
                    wait(); // Wait until resumed
                }
            }
            System.out.println(Thread.currentThread().getName() + " is running after resume.");

        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }

    // Suspend method using a flag
    public void suspendThread() {
        suspended = true;
        System.out.println(Thread.currentThread().getName() + " is suspended.");
    }

    // Resume method to wake up the suspended thread
    public synchronized void resumeThread() {
        suspended = false;
        notify(); // Notify the waiting thread
        System.out.println(Thread.currentThread().getName() + " is resumed.");
    }
}

public class q12_BasicThreadMethods {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();

        // Start both threads using a for loop
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                t1.start();
            } else {
                t2.start();
            }
        }

        // Using join() to ensure the main thread waits for both threads to finish
        try {
            t1.join();
            t2.join();
            System.out.println("Both threads have finished.");
        } catch (InterruptedException e) {
            System.out.println(e);
        }

        // Suspending and resuming thread (demonstration)
        t1.suspendThread();
        try {
            Thread.sleep(2000); // Wait for 2 seconds before resuming
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        t1.resumeThread();
    }
}
