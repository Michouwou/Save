<?php
	require_once('data_base.php');
	if (array_key_exists("string_pic", $_REQUEST) && array_key_exists("string_alpha", $_REQUEST) && array_key_exists("id_user", $_REQUEST))
	{
		if ($_REQUEST['jpg'] == "1")
			$image = imagecreatefromjpeg($_REQUEST['string_pic']);
		else
			$image = imagecreatefromstring(base64_decode($_REQUEST["string_pic"]));
		$alpha = imagecreatefrompng($_REQUEST["string_alpha"]);
		$next = imagecreatetruecolor(1000, 1000);
		$img = imagecreatetruecolor(1000, 1000);
		$save = imagecreatetruecolor(200, 200);
		imagealphablending($img, true);
		$transparent = imagecolorallocatealpha($img, 0, 0, 0, 127);
		imagefill($img, 0, 0, $transparent);
		imagefill($next, 0, 0, $transparent);
		imagefill($save, 0, 0, $transparent);
		if (array_key_exists("up", $_REQUEST))
		{
			$res = imagecreatetruecolor(1000, 1000);
			imagefill($res, 0, 0, $transparent);
			$success = imagecopyresized($res, $image, 0, 0, 0, 0, 1000, 1000, imagesx($image), imagesy($image));
			imagedestroy($image);
			$image = $res;
		}
		$success = imagecopyresized($next, $alpha, 0, 0, 0, 0, 1000, 1000, getimagesize($_REQUEST["string_alpha"])[0], getimagesize($_REQUEST["string_alpha"])[1]);
		imagedestroy($alpha);
		if ($img && $image && $success)
		{
			imagecopyresampled($img, $image, 0, 0, 0, 0, 1000, 1000, 1000, 1000); 
			if ($success)
			{
				imagecopyresampled($img, $next, 0, 0, 0, 0, 1000, 1000, 1000, 1000);
				if ($success)
				{
					imagealphablending($img, false);
					imagesavealpha($img, true);
					$success = imagecopyresized($save, $img, 0, 0, 0, 0, 200, 200, imagesx($img), imagesy($img));
					ob_start();
					imagepng($save);
					$base =  ob_get_contents();
					ob_end_clean();
					ob_start();					
					imagepng($img);
					$base2 = ob_get_contents();
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
		imagedestroy($next);
		imagedestroy($image);
		imagedestroy($img);
	}
	else
		$base = "Echec lors de l'envoi des donnees";
	echo base64_encode($base2);
?>