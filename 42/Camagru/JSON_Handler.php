<?php
    require_once("data_base.php");
	if (array_key_exists('imageData', $_REQUEST) && array_key_exists('id_user', $_REQUEST))
	{
		$data = $_REQUEST['imageData'];
		$id = intval($_REQUEST['id_user']);
	}
	$query = "INSERT INTO gallery (picture, id_user) VALUES (?, ?);";
	$prep = $pdo->prepare($query);
    $prep->bindValue(1, $data, PDO::PARAM_STR);
    $prep->bindValue(2, $id, PDO::PARAM_INT);
    $prep->execute();
?>