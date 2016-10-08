<?php
	require_once("data_base.php");
	$res = "";
	if (array_key_exists('username', $_REQUEST) && array_key_exists('mail', $_REQUEST))
	{
		$query = "SELECT * FROM `users` WHERE username=?;";
		$query2 = "SELECT * FROM `users` WHERE mail=?;";
		$prep = $pdo->prepare($query);
		$prep2 = $pdo->prepare($query2);
		$prep->bindValue(1, htmlentities($_REQUEST['username']));
		$prep2->bindValue(1, htmlentities($_REQUEST['mail']));
		$prep->execute();
		$prep2->execute();
		$arr = $prep->fetch();
		$arr2 = $prep2->fetch();
		if ($arr && $arr2 && $arr['mail'] == $_REQUEST['mail'] && $arr2['username'] == $_REQUEST['username'])
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
            echo "Un mail de reactivation vous a ete envoye";
		}
		else
			echo "Les deux champs ne correspondent pas!";
	}
	else
		echo "Une erreur est survenue";
?>