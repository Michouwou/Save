<?php
    require_once("data_base.php");
	if (array_key_exists('imageData',$_REQUEST))
		$data = $_REQUEST['imageData'];
	$query = "INSERT INTO gallery (picture) VALUES (?);";
	$prep = $pdo->prepare($query);
	$fd = fopen("test.jpeg", 'w+');
	fwrite($fd, base64_decode($data));
	fclose($fd);
    $prep->bindValue(1, $data, PDO::PARAM_STR);
    $prep->execute();
?>