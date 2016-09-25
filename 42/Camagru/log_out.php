<?php
	require_once('data_base.php');
	if ($_SESSION['logged_in'] != false)
	{
		session_destroy();
		redirect('connexion.php');
	}

?>