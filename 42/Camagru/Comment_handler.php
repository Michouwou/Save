<?php
	require_once("data_base.php");
	if (array_key_exists('comment', $_REQUEST))
	{
		$data = htmlentities($_REQUEST['comment']);
		$field = "comment";
		$param = PDO::PARAM_STR;
	}
	else if (array_key_exists('like', $_REQUEST))
	{
		$data = intval($_REQUEST['like']);
		$field = "likes";
		$param = PDO::PARAM_INT;
	}

	$query = "INSERT INTO comments (id_user, id_picture, ".$field.") VALUES (?, ?, ?);";
	$prep = $pdo->prepare($query);
    $prep->bindValue(1, $_REQUEST['id_user'], PDO::PARAM_INT);
    $prep->bindValue(2, $_REQUEST['id_picture'], PDO::PARAM_INT);
    $prep->bindValue(3, $data, $param);
    $prep->execute();

    if ($field == "comment")
    {
    	$query = "SELECT users.mail, users.id, users.username FROM `users`, `gallery` WHERE gallery.id=? AND users.id=gallery.id_user;";
    	$prep = $pdo->prepare($query);
    	$prep->bindValue(1, $_REQUEST['id_picture'], PDO::PARAM_INT);
    	$prep->execute();
	
    	$arr = $prep->fetch();
    	$subject = "Il y a un nouveau commentaire sur une de vos photos!";
    	$entete = "From : mlevieux42@gmail.com";
    	$message = "Quelqu'un a commente une de vos photos! Depechez vous de vous connecter pour voir ce commentaire et y repondre!".
    				"\nhttp://localhost:8080/Camagru/";
    	mail($arr['mail'], $subject, $message, $entete);
	}
?>