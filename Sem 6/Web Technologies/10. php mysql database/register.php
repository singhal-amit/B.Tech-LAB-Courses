<!DOCTYPE html>
<html lang="en">

  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Registration</title>
  </head>

  <body>
    <h2>User Registration</h2>
    <form action="register.php" method="POST">
      <label for="name">Name:</label>
      <input type="text" id="name" name="name" required><br><br>

      <label for="address">Address:</label>
      <textarea id="address" name="address" required></textarea><br><br>

      <label for="email">Email:</label>
      <input type="email" id="email" name="email" required><br><br>

      <label for="mobile">Mobile No:</label>
      <input type="text" id="mobile" name="mobile" required><br><br>

      <input type="submit" value="Register">
    </form>

    <?php
    // Database config
    $host = "localhost";
    $username = "root";
    $password = "";
    $dbname = "user_registration";

    // Connect to DB
    $conn = new mysqli($host, $username, $password, $dbname);
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    // Handle form submission
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $name = $_POST['name'];
      $address = $_POST['address'];
      $email = $_POST['email'];
      $mobile = $_POST['mobile'];

      $sql = "INSERT INTO users (name, address, email, mobile) VALUES (?, ?, ?, ?)";
      $stmt = $conn->prepare($sql);
      $stmt->bind_param("ssss", $name, $address, $email, $mobile);

      if ($stmt->execute()) {
        echo "<p>Registration successful!</p>";
      } else {
        echo "<p>Error: " . $stmt->error . "</p>";
      }

      $stmt->close();
    }

    // Display all users
    $sql = "SELECT id, name, address, email, mobile FROM users";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
      echo "<h2>User Information</h2>";
      echo "<table border='1'><tr><th>ID</th><th>Name</th><th>Address</th><th>Email</th><th>Mobile</th></tr>";

      while ($row = $result->fetch_assoc()) {
        echo "<tr>
      <td>{$row['id']}</td>
      <td>{$row['name']}</td>
      <td>{$row['address']}</td>
      <td>{$row['email']}</td>
      <td>{$row['mobile']}</td>
    </tr>";
      }

      echo "</table>";
    } else {
      echo "<p>No users found.</p>";
    }

    $conn->close();
    ?>
  </body>

</html>
