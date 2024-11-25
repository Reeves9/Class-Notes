<?php
	//include connection
	include 'connection.php';
	//check if method is 'post' or 'get'
	session_start();
	if($_SERVER['REQUEST_METHOD']=='POST'){
		if(!isset($_POST['fname']) && !isset($_POST['lname'])){
			echo "invalid form";
			return;
		}else {
			$firstName = $_POST['fname'];
			$lastName = $_POST['lname'];
			$country = $_POST['country'];
			$gender = $_POST['gender'];
			$color = implode(',',$_POST['colors']);
			echo $color;
			//insert query
			$insetQuery = "INSERT INTO users(firstname, lastname, country, gender, color) VALUES('$firstName', '$lastName', '$country', '$gender', '$color')";
			if(mysqli_query($conn, $insetQuery)){
				$_SESSION['user'] = $firstName;
				header('Location: dashboard.php');
				echo "Data Inserted";
			}else {
				echo "Data Insertion Failed";
			}
		}
	}else {
		echo "Invalid Method";
	}
?>
