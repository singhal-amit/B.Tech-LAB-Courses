<?php
// Read the contents of the file into an array, each line represents a record
$filename = 'data.txt';
$lines = file($filename, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
// Function to parse each line into an associative array
function parseLine($line)
{
  $data = [];
  preg_match('/Name:\s*(.*?)\s*Password:\s*(.*?)\s*Email:\s*(.*)/', $line, $matches);
  if (count($matches) === 4) {
    $data['name'] = $matches[1];
    $data['password'] = $matches[2];
    $data['email'] = $matches[3];
  }
  return $data;
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>User Information</title>
  <style>
    table {
      width: 100%;
      border-collapse: collapse;
    }

    table,
    th,
    td {
      border: 1px solid black;
    }

    th,
    td {
      padding: 8px;
      text-align: left;
    }
  </style>
</head>

<body>
  <h1>User Information</h1>
  <table>
    <thead>
      <tr>
        <th>Name</th>
        <th>Password</th>
        <th>Email</th>
      </tr>
    </thead>
    <tbody>
      <?php
      // Loop through the lines from the file and parse them into a table
      foreach ($lines as $line) {
        $data = parseLine($line);
        if ($data) {
          echo "<tr>";
          echo "<td>" . htmlspecialchars($data['name']) . "</td>";
          echo "<td>" . htmlspecialchars($data['password']) . "</td>";
          echo "<td>" . htmlspecialchars($data['email']) . "</td>";
          echo "</tr>";
        }
      }
      ?>
    </tbody>
  </table>
</body>

</html>
