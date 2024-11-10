<?php
	echo "hello world <br>";
	//variable declaration
	$num1 = 10;
	$num2 = 20;
	echo $num1 + $num2;
	echo "<br>";
	//print in list
	echo "<ol>";
	echo "<li>well</li>";
	echo "<li>hello</li>";
	echo "<li>there</li>";
	echo "</ol>";
	
?>
<?php
	//working with numeric array
	$arr = array(1,2,3,4,5); // declare with class
	$larr = [1,2,3,4,5]; //declare with literals
	foreach($arr as $value){
		echo $value."<br>";
	}
	foreach($arr as $key=>$value){
		echo $key."->".$value."<br>"; //$key is the index of the values
	}
	// associative arrays
	$arr2 = array("name"=>"reeves","age"=>"12");
	foreach($arr2 as $key=>$value){
		echo $key."->".$value."<br>";
	}
	//joining array
	$arrayAsString = join("|",$arr); //joins with the charecter in the quotes
	echo $arrayAsString."<br>";
	echo strlen($arrayAsString);
?>
