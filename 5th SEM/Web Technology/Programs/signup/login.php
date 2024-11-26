<?php
include 'connection.php';

// Get input from form
$username = $_POST['username'];
$password = $_POST['password'];

// Query to fetch user data
$sql = "SELECT * FROM users WHERE username = '$username'";
$result = mysqli_query($connection, $sql);

if ($result && mysqli_num_rows($result) > 0) {
    $row = mysqli_fetch_assoc($result);
    
    // Verify the password
    if (password_verify($password, $row['password'])) {
        header("Location: main.html");
        exit();
    } else {
        echo "Invalid username or password.";
    }
} else {
    echo "Invalid username or password.";
}

// Close the connection
mysqli_close($connection);
?>
