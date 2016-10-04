<?php
	require_once("data_base.php");
	if (array_key_exists("nb_page", $_REQUEST))
	{
		$query = "SELECT * FROM `gallery`;";
		$prep = $pdo->prepare($query);
		$prep->execute();
		$number = 0;
		while ($number < intval($_REQUEST['nb_page']))
			$arr = $prep->fetch();
		if ($arr)
		{
			$number = 0;
			while ($number < 30 && $arr)
			{
				$images = "<img id=\"".$arr['id']."\" src=\"data:image/png;charset=utf-8;base64,".
            		addcslashes($arr['picture'], "'\"}")."\" onclick=\"getRightDiv(".$arr['id'].")\"/>\n".$images;
				$arr = $prep->fetch();
				$number++;
            }
		}
		echo $images;
	}
	else
		echo "";
?>