<?php
	require_once("data_base.php");
	if (array_key_exists('comment', $_REQUEST))
	{
		$data = $_REQUEST['comment'];
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
?>