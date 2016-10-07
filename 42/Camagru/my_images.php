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
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
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
    		<button id="delete" class="button" onclick="deletion('delete')">Effacer l'image</button>
    		<button id="reset" class="button" onclick="deletion('reset')">Effacer les likes et les commentaires</button>
    		<button id="delete_all" class="button" onclick="deletion('all')">Effacer toutes mes photos</button>
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
	var glob_id = <?php echo $_SESSION['id_user']?>;

	function select_image(id)
	{
		if (select != 0)
			document.getElementById(select).className = "";
		select = id;
		document.getElementById(select).className = "selection";
	}

	function deletion(action)
	{
		if (select == 0 && action != 'all')
			alert("Vous devez selectionner une image pour appliquer cette action!");
		else
		{
			$.ajax(
			{
				type: 'POST',
				url: "delete.php",
				dataType: 'text',
				data:
				{
					action : action,
					user_id : glob_id,
					picture_id : select,
				},
				success: function (data)
				{
					alert("L'action a ete effectuee avec succes");
					location.reload();
				},
				error: function()
				{
					alert("Une erreur est survenue, veuillez reessayer ulterieurement");
				},
			});
		}
	}
</script>
</html>