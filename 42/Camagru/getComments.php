<?php
	require_once('data_base.php');
	$result = "";
	if (array_key_exists('id_picture', $_REQUEST))
	{
		$query1 = "SELECT * FROM comments WHERE id_picture=?;";
		$query2 = "SELECT id, username FROM users";
		$prep1 = $pdo->prepare($query1);
		$prep1->bindValue(1, $_REQUEST['id_picture']);
		$prep1->execute();
		$prep2 = $pdo->prepare($query2);
		$prep2->execute();
		$var2 = $prep2->fetchAll(PDO::FETCH_COLUMN|PDO::FETCH_GROUP);
		if ($var2 != false)
		{
			while (($var1 = $prep1->fetch()) != false)
			{
				$result = "</td></tr>".$result;
				if ($var1['likes'])
					$result = htmlentities($var2[$var1['id_user']][0])." ".($var1['likes'] == 1 ? "a " : " n'a pas ")."aimé cette photo".$result;
				else if ($var1['comment'])
					$result = htmlentities($var2[$var1['id_user']][0])." : ".htmlentities($var1['comment']).$result;
				$result = "<tr><td>".$result;
			}
		}
	}
	echo $result;
?>