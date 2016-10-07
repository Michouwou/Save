<?php
	require_once('data_base.php');
	session_start();
	if ($_SESSION['logged_in'] == false)
		redirect("connexion.php");
	$query = "SELECT * from `gallery` WHERE id_user=?;";
	$prep = $pdo->prepare($query);
	$prep->bindValue(1, $_SESSION['id_user']);
	$prep->execute();
	$images = "";
	while ($arr = $prep->fetch())
		$images = $images."<img id='".$arr['id']."' src='data:image/png;charset=utf-8;base64,".$arr['picture']."' onclick='select_image(".$arr['id'].")'/>";
?>
<!DOCTYPE html>
<html>
<head>
	<title>Mes images</title>
	<link rel="stylesheet" type="text/css" href="my_images.css"/>
</head>
<body>
	<div id="header">
            <div id="fast_access">
                <a href="log_out.php">Se déconnecter</a>
                <a href="camagru.php">Camagru</a>
                <a href="galery.php">Gallerie</a>
            </div>
    </div>
    <div id="commentaries">
    	<div id="buttons">
    		<button id="delete" class="button" onclick="delete_image()">Effacer l'image</button>
    		<button id="reset" class="button" onclick="reset_image()">Effacer les likes et les commentaires</button>
    	</div>
    </div>
    <div id="pictures">
    	<?php
    		echo $images;
    	?>
    </div>
    <div id="footer">
    </div>
</body>
<script type="text/javascript">
	var select = 0;

	function select_image(id)
	{
		if (select != 0)
			document.getElementById(select).className = "";
		select = id;
		document.getElementById(select).className = "selection";
	}
</script>
</html>