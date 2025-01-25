<?php
    include 'connection.php';
    session_start();
    if(!isset($_SESSION['user'])){
        header('Location: index.html');
    }
    $sql = "SELECT * FROM `users`";
    $result = mysqli_query($conn, $sql);
    echo "<b>Welcome</b><br>";
    echo $_SESSION['user'];
    echo "<br>Available useers are:";
    if ($result) {
        while ($row = mysqli_fetch_assoc($result)) {
        echo $row['firstname'].' ';
    }
    }else{
        echo 'data not found';
    }
    session_destroy();
?>