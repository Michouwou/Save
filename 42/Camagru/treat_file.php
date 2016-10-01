<?php
	require_once('data_base.php');
	$result = "";
	if (array_key_exists('path', $_REQUEST) && array_key_exists('id_user', $_REQUEST))
	{
		$fd = fopen($_REQUEST['path'], "r");
		
			$file = fread($fd, 100000);
		
		fclose($fd);
	}
	echo $file;
?>