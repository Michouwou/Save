<?php
	require_once('data_base.php');
	if (array_key_exists('action', $_REQUEST))
	{
		if ($_REQUEST['action'] != 'all' && array_key_exists('picture_id', $_REQUEST))
		{
			if ($_REQUEST['action'] == 'delete')
				$query = "DELETE FROM `gallery` WHERE id=".$_REQUEST['picture_id'].";";
			else if ($_REQUEST['action'] == 'reset')
				$query = "DELETE FROM `comments` WHERE id_picture=".$_REQUEST['picture_id'].";";
			else
				$query = "";
		}
		else if ($_REQUEST['action'] == 'all' && array_key_exists('user_id', $_REQUEST))
		{
			$query = "SELECT id FROM `gallery` WHERE id_user=".$_REQUEST['user_id'].";";
			$prep = $pdo->prepare($query);
			$prep->bindValue(1, $_REQUEST['user_id']);
			$prep->execute();
			while ($arr = $prep->fetch())
			{
				$query = "DELETE FROM `comments` WHERE id_picture=".$arr['id'].";";
				$prep2 = $pdo->prepare($query);
				$prep2->execute();
			}
			$query = "DELETE FROM `gallery` WHERE id_user=".$_REQUEST['user_id'].";";
		}
		else
			$query = "";
	}
	if ($query != "")
	{
		$prep = $pdo->prepare($query);
		$prep->execute();
	}
?>