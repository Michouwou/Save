<!DOCTYPE html>
<html>
<head>
	<title>Reactivation</title>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
</head>
<body>
	<form onsubmit="send()">
        <div>
            Entrez votre mail : <input id="mail" type="mail" name="mail"/>
        </div>
        Entrez votre login : <input id="username" type="text" name="username"/>
        <button id="validate" type="submit" name="OK">
        </button>
    </form>
</body>
<script>
	function send()
	{
		var dmail = document.getElementById('mail').value;
		var dusername = document.getElementById('username').value;
		if (mail == "" || username == "")
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
					plop(data);
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