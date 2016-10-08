<?php
    require_once('data_base.php');
    session_start();
    if (!isset($_POST['OK']) && isset($_GET['cle']))
    {
        $query = "SELECT * FROM users WHERE username=?";
        $prep = $pdo->prepare($query);
        $prep->bindValue(1, urldecode($_GET['login']), PDO::PARAM_STR);
        $prep->execute();
        $arr = $prep->fetch();
        if ($arr == false)
        {
            $_POST['error_unknown_login'] = "Une erreur inconnue est survenue, veuillez nous excusez";
        }
        else
        {
            $_SESSION['present'] = urldecode($_GET['login']);
            if (urldecode($_GET['cle']) == hash('sha512', $arr['id']))
            {
                $_POST['launch'] = 1;
            }
            else
            {
                $_POST['error_key_not_valid'] = "La clé de validation ne correspond pas au login fourni, votre compte ne peut être reinitialise";
            }
        }
    }
    else if ($_POST['OK'] == "OK")
    {
        $pass = htmlentities($_POST['password1']);
        $passs = htmlentities($_POST['password2']);
        if (preg_match('/[a-z]/', $pass) && preg_match('/[0-9]/', $pass) && preg_match('/[A-Z]/', $pass) && $pass == $passs)
        {
            $query = "SELECT username FROM `users` WHERE password=?;";
            $prep = $pdo->prepare($query);
            $prep->bindValue(1, hash('sha512', $pass), PDO::PARAM_STR);
            $prep->execute();
            $arr = $prep->fetch();
            if (!$arr)
            {
                $query = "UPDATE `users` SET password=? WHERE username=?;";
                $prep = $pdo->prepare($query);
                $prep->bindValue(1, hash('sha512', $pass), PDO::PARAM_STR);
                $prep->bindValue(2, $_SESSION['present'], PDO::PARAM_STR);
                $prep->execute();
                $_POST['reset'] = "Votre mot de passe a bien ete reinitialise, veillez a le noter quelque part pour ne pas l'oublier ;) ".$_SESSION['login'];
            }
            else
            {
                $_POST['error_already_existing'] = "Ce mot de passe existe deja!";
            }
            $_POST['error_passwords_not_identical'] = "";
            $_POST['error_not_secure'] = "";
        }
        else
        {
            if ($pass != $passs)
                $_POST['error_passwords_not_identical'] = "Les deux mots de passe ne sont pas identiques, veuillez reiterer!";
            if (!preg_match('/[a-z]/', $pass) || !preg_match('/[0-9]/', $pass) || !preg_match('/[A-Z]/', $pass))
                $_POST['error_not_secure'] = "Le mot de passe choisi doit contenir au moins une lettre minuscule, une lettre majuscule et un chiffre!";    
        }
        $_POST['password1'] = NULL;
        $_POST['password2'] = NULL;
    }
    else
        redirect('index.php');
?>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <link rel='stylesheet' type='text/css' href='activation.css'>
        <title>Activation</title>
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
            input[type=password]
            {
                height: 20%;
                width: 35%;
                font-size: 1.5vmin;
            }
            a
            {
                margin: auto;
            }
            p
            {
                line-height: 4vmin;
            }
        </style>
</head>
<body>
        <div id="contain">
            <?php
                echo "<form method='post' action='reset.php'> Veuillez choisir un nouveau mot de passe* : <hr>Mot de passe : <input ";
                if ($_POST['error_already_existing'] != "" || $_POST['error_passwords_not_identical'] != "" || $_POST['error_not_secure'] != "")
                    echo "style='background:#F5A9A9;'";
                echo "type='password' name='password1' min=8 max=60 require='required'/>
                <hr>Mot de passe : <input type='password' name='password2' min=8 max=60 require='required'/>
                <hr><input type='submit' value='OK' name='OK'/></form>
                <p>".$_POST['error_not_secure']."</p><p>".$_POST['error_passwords_not_identical']."</p><p>".$_POST['error_already_existing']."</p><p>".$_POST['reset']."</p>";
            ?>
        </div>
        <div style='width:100%;display:flex;'>
            <a href="connexion.php">Retour a la page de connexion</a>
        </div>
    </body>
</html>