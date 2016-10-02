<?php
require_once('data_base.php');
	if (array_key_exists("string_pic", $_REQUEST) && array_key_exists("string_alpha", $_REQUEST) && array_key_exists("id_user", $_REQUEST))
	{
		$image = imagecreatefrompng(base64_decode($_REQUEST["string_pic"]));
		$alpha = imagecreatefrompng($_REQUEST["string_alpha"]);
		$result = imagecreate(500, 500);
		$next = imagecreate(500, 500);
		$success =imagecopyresized ($next, $alpha, 0, 0, 0, 0, 500, 500, getimagesize($_REQUEST["string_alpha"])[0], getimagesize($_REQUEST["string_alpha"])[1]);
		if ($result && $image && $success)
		{
			$success = imagecopy($result, $image, 0, 0, 0, 0, 500, 500);
			if ($success)
			{
				$success = imagecopymerge($result, $next, 0, 0, 0, 0, 500, 500, 100);
				if ($success)
				{
					ob_start();
					imagepng($result);
					$base =  ob_get_contents();
					ob_end_clean();
					$query = "INSERT INTO gallery (picture, id_user) VALUES (?, ?);";
					$prep = $pdo->prepare($query);
    				$prep->bindValue(1, base64_encode($base), PDO::PARAM_STR);
    				$prep->bindValue(2, intval($_REQUEST['id_user']), PDO::PARAM_INT);
    				$prep->execute();
				}
				else
					$base = "Echec lors de la superposition des images";
			}
			else
				$base = "Echec lors de la copie de photo";
		}
		else
			$base = "Echec lors de la creation des images";
	}
	else
		$base = "Echec lors de l'envoi des donnees";
	echo base64_encode($base);
?>