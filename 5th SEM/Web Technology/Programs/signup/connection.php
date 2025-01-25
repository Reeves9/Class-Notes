<?php
    $username = "root";
    $password = "";
    $database = "Users";
    $server = "localhost";
    $connection = mysqli_connect($server, $username, $password, $database);
    if (!$connection) {
        die("Connection failed: " . mysqli_connect_error());
    }else{
        echo "Connected successfully";
    }
?>