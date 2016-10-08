<!DOCTYPE html>
<html>
<head>
	<title>Reactivation</title>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
	<style>
        	#contain
        	{
        		width: 50%;
    			height: 30%;
    			background: #5b5a5d;
    			margin: auto;
    			color: #9dbfdc;
    			padding: 6%;
    			box-sizing: border-box;
    			line-height: 5%;
    			font-size: 2vmin;
    			border: 1vmin double black;
        	}
        	hr
        	{
        		margin: 4%;
        	}
        	input[type=submit]
        	{
        		width: 15%;
    			margin: auto;
    			display: block;
    			height: 4vmin;
    			border-radius: 8px;
    			background: #9dbfdc;
    			cursor: pointer;
    			position: relative;
    			font-size: 1vmin;
        	}
        	input[type=mail], input[type=text]
        	{
        		height: 20%;
    			width: 35%;
    			font-size: 1.5vmin;
        	}
        	a
        	{
        		margin: auto;
        	}
        </style>
</head>
<body>
        <div id="contain">
            Entrez votre mail : <input id="mail" type="mail" name="mail"/>
            <hr>
        	Entrez votre login : <input id="username" type="text" name="username"/>
        	<hr>
        	
        	<input type=submit id="validate" onclick="send()" name="OK" value="OK"/>
        </div>
        <div style='width:100%;display:flex;'>
			<a href="connexion.php">Retour a la page de connexion</a>
		</div>
        
</body>
<script>
	function send()
	{
		var dmail = document.getElementById('mail').value;
		var dusername = document.getElementById('username').value;
		console.log(dmail);
		console.log(dusername);
		if (mail == "" || username == "" || mail == null || username == null || !dmail || !dusername)
			alert('Les deux champs doivent etre completes pour la reinitialisation du mot de passe...');
		else
		{
			$.ajax(
			{
				type: 'post',
				url: 'forgotten.php',
				dataType: 'text',
				data:
				{
					mail: dmail,
					username: dusername,
				},
				success: function(data)
				{
					alert(data);
					if (data == "Un mail de reactivation vous a ete envoye")
						window.location.href ='connexion.php';
				}
			});
		}
	}

	function plop(message)
	{
		alert(message);
	}
</script>
</html>