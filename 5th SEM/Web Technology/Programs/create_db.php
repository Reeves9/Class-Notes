<?php
    include 'connection.php';
    //create new database 
    $sql = "CREATE DATABASE IF NOT EXISTS WebTech";
    if(mysqli_query($conn, $sql)){
        echo "Database Created<br>";
    }else{
        echo "Database Creation Failed<br>";
    }

?>