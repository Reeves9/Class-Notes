<?php
    include 'connection.php';
    //create new table
    $sql_query = "CREATE TABLE IF NOT EXISTS WebTech.users(
        id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        firstname VARCHAR(30) NOT NULL,
        lastname VARCHAR(30) NOT NULL,
        country VARCHAR(50) NOT NULL,
        gender VARCHAR(10) NOT NULL,
        color VARCHAR(50) NOT NULL
    )";
    if(mysqli_query($conn, $sql_query)){
        echo "Table Created<br>";
    }else{
        echo "Table Creation Failed<br>";
    }

?>