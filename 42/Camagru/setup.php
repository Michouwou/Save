<?php
	require_once("data_base.php");
	$query1 = "DROP TABLE IF EXISTS users;";
	$query2 = "DROP TABLE IF EXISTS gallery;";
	$query3 = "DROP TABLE IF EXISTS comments;";
	$prep1 = $pdo->prepare($query1);
	$prep2 = $pdo->prepare($query2);
	$prep3 = $pdo->prepare($query3);
	$prep1->execute();
	$prep2->execute();
	$prep3->execute();

	$query1 = "CREATE TABLE users
				(
					`id` INT PRIMARY KEY AUTO_INCREMENT,
					`username` VARCHAR(60),
					`password` VARCHAR(1024),
					`mail` VARCHAR(255),
					`active` INT,
					`sexe` INT
				);";
	$query2 = "CREATE TABLE gallery
				(
					`id` INT PRIMARY KEY AUTO_INCREMENT,
					`picture` TEXT(200000),
					`id_user` INT
				);";
	$query3 = "CREATE TABLE comments
				(
					`id_user` INT,
					`id_picture` INT,
					`comment` TEXT(65535),
					`likes` INT
				);";
	$prep1 = $pdo->prepare($query1);
	$prep2 = $pdo->prepare($query2);
	$prep3 = $pdo->prepare($query3);
	$prep1->execute();
	$prep2->execute();
	$prep3->execute();

	$query = "INSERT INTO `users` (username, password, mail, active, sexe) VALUES ('admin', '".hash("sha512", hash("sha512", "admin"))."', 'mlevieux42@gmail.com', 1, 1);";
	$prep = $pdo->prepare($query);
	$prep->execute();
?>