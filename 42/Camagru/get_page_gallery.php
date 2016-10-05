<?php
	require_once("data_base.php");
	if (array_key_exists("nb_page", $_REQUEST))
	{
		$query = "SELECT * FROM `gallery`;";
		$prep = $pdo->prepare($query);
		$prep->execute();
		$number = 0;
		while ($number < (intval($_REQUEST['nb_page']) - 1) * 21 + 1)
		{
			$number++;
			$arr = $prep->fetch();
		}
		$number = 0;
		while ($number < 21 && $arr)
		{
			$images = $images."<img id=\"".$arr['id']."\" src=\"data:image/png;charset=utf-8;base64,".addcslashes($arr['picture'], "'\"}")."\" onclick=\"getRightDiv(".$arr['id'].")\"/>\n";
			$arr = $prep->fetch();
			$number++;
        }
		echo $images;
	}
	else
		echo "";
?>