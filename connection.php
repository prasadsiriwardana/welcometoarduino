<?php
$username = "root";
$pass = "prasad";
$host = "localhost";
$db_name = "ethernet";
$con = mysqli_connect ($host, $username, $pass);
$db = mysqli_select_db ( $con, $db_name );
?>