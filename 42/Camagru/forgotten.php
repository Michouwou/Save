<?php
	require_once("data_base.php");
	$res = "";
	if (array_key_exists('username', $_REQUEST) && array_key_exists('mail', $_REQUEST))
	{
		$query = "SELECT * FROM `users` WHERE username=?";
		$prep = $pdo->prepare($query);
		$prep->bindValue(1, $_REQUEST['username']);
		$prep->execute();
		$arr = $prep->fetch();
		if ($arr && $arr['mail'] == $_REQUEST['mail'])
		{
			$cle = $arr['id'];
            $subject = "Mail de reactivation de compte Camagru";
            $entete = "From : mlevieux42@gmail.com";
            $message = "Voici le lien de reactivation de votre compte Camagru.\n
                        \n\nCliquez sur le lien pour reactiver votre compte :\n
                        http://localhost:8080/Camagru/reset.php?login="
                        .urlencode($arr['username'])."&cle=".urlencode(hash('sha512', $cle)).
                        "\nCeci est un message automatique, merci de ne pas répondre.";
            mail(htmlentities($_REQUEST['mail']), $subject, $message, $entete);
            $res = "1";
		}
		else
			$res = "0";
	}
	echo $res;
?>