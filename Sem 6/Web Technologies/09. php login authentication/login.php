<!DOCTYPE html>
<html lang="en">

  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Form</title>
  </head>

  <body>
    <h2>Login</h2>
    <form action="login.php" method="POST">
      <label for="username">Username:</label>
      <input type="text" id="username" name="username" required>
      <br><br>
      <label for="password">Password:</label>
      <input type="password" id="password" name="password" required>
      <br><br>
      <input type="submit" value="Login">
    </form>

    <?php
    // Function to validate the user
    function validate_user($username, $password)
    {
      $file = fopen("users.txt", "r");
      if (!$file) {
        die("Unable to open file!");
      }
      while ($line = fgets($file)) {
        $line = trim($line);
        list($stored_username, $stored_password) = explode(":", $line);
        if ($username === $stored_username && $password === $stored_password) {
          fclose($file);
          return true;
        }
      }
      fclose($file);
      return false;
    }

    // Handle form submission
    if ($_SERVER["REQUEST_METHOD"] === "POST") {
      $username = $_POST["username"];
      $password = $_POST["password"];

      if (validate_user($username, $password)) {
        echo "<p>Login successful! Welcome, " . htmlspecialchars($username) . ".</p>";
      } else {
        echo "<p style='color:red;'>Invalid username or password.</p>";
      }
    }
    ?>
  </body>

</html>
