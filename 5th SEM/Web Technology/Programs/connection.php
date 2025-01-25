<?php
    //create connection
    $server = 'localhost';
    $user = 'root';
    $password = '';
    $db = 'WebTech'; //only after creating database

    $conn = mysqli_connect($server, $user, $password, $db);
    if(!$conn){
        die("Connection Failed: ".mysqli_connect_error());
    }else{
        echo "Connection Successful<br>";
    }
?>