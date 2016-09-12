<?php
    require_once('data_base.php');
    if ($_SESSION[logged_in] == true)
        header('Location : camagru.php');
    if (isset($_POST) && isset($_POST['Username']) && isset($_POST['Password'])
        && $_POST['Username'] != "" && $_POST['Password'] != "")
    {
        $query = "SELECT * FROM users WHERE username=?";
        $prep = $pdo->prepare($query);
        $prep->bindValue(1, $_POST['Username'], PDO::PARAM_STR);
        $prep->execute();
        
        $arr = $prep->fetch();
        echo "array = ".$arr;
        if ($arr == false)
        {
            $_POST['error_no_such_login'] = "Le login entré semble ne pas exister.";
            $_POST['Username'] = NULL;
        }
        else
        {
            if ($arr['password'] == hash('sha512', hash('sha512', $_POST['Password'])))
            {
                if ($arr['active'] == 1)
                {
                    $_SESSION['logged_in'] = true;
                    //header('Location : https://save-michouwou.c9users.io/Save/42/Camagru/camagru.php');
                }
                else
                {
                    $_POST['error_account_not_active'] = "Votre compte n'est pas activé, veuillez l'activer
                        pour pouvoir vous connecter.<br>
                        <a href=send_mail.php>Je souhaite que l'on me renvoie un mail d'activation</a>";
                }
            }
            else
            {
                $_POST['error_connection_failed'] = "Le mot de passe n'existe pas ou ne correspond pas
                    au login entré";
                $_POST['Username'] = NULL;
                $_POST['Password'] = NULL;
            }
        }
    }
?>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="connexion.css">
        <title>
            Connexion
        </title>
    </head>
    <body>
        <div id="inscription">
            <a href="inscription.php">En fait je suis pas encore inscrit...</a>
        </div>
        <div id="connexion">
            <form method="post" action="connexion.php">
                <div id="username">
                    Entrez votre nom d'utilisateur : <input
                    <?php
                        if (isset($_POST['Username']))
                            echo " value='".$_POST['Username']."' ";
                    ?>
                    type="text" name="Username"/>
                </div>
                <div id="password">
                    Entrez votre mot de passe : <input
                    <?php
                        if (isset($_POST['Password']))
                            echo " value='".$_POST['Password']."' ";
                    ?>
                    type="password" name="Password"/>
                </div>
                <button id="validate" type="submit" name="OK">
                    <span id="first">OK</span>
                    <span id="second">C'est Parti!</span>
                    <span id="third">Wouhou!!</span>
                </button>
            </form>
        </div>
    </body>
</html>