<?php
    require_once('data_base.php');
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
            if (urldecode($_GET['cle']) == hash('sha512', $arr['id']))
            {
                $_POST['reset'] = 1;
            }
            else
            {
                $_POST['error_key_not_valid'] = "La clé de validation ne correspond pas au login fourni, votre compte ne peut être reinitialise";
            }
        }
    }
    else if (isset($_POST['OK']))
    {
        $pass = htmlentities($_POST['password1']);
        if (preg_match('[a-z]', $pass) && preg_match('[0-9]', $pass) && preg_match('[A-Z]', $pass) && $pass == htmlentities($_POST['password2']))
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
                $prep->bindValue(2, urldecode($_GET['login']), PDO::PARAM_STR);
                $prep->execute();
                $_POST['reset'] = "Votre mot de passe a bien ete reinitialise, veillez a le noter quelque part pour ne pas l'oublier ;)";
            }
            else
            {
                $_POST['error_already_existing'] = "Ce mot de passe existe deja!";
            }
        }
        else
        {
            if ($pass != htmlentities($_POST['password2']))
                $_POST['error_passwords_not_identical'] = "Les deux mots de passe ne sont pas identiques, veuillez reiterer!";
            if (!preg_match('[a-z]', $pass) || !preg_match('[0-9]', $pass) || !preg_match('[A-Z]', $pass))
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
    </head>
    <body>
        <div id="activ">
            <?php
                if ($_POST['reset'] == 1)
                {
                    echo "<form type='post' action='reset.php'> Veuillez choisir un nouveau mot de passe* : <input ";
                    if (isset($_POST['error_already_existing']) || isset($_POST['error_passwords_not_identical']) || isset($_POST['error_not_secure']))
                        echo "style='background:#F5A9A9';";
                    echo "type='password' name='password1' min=8 max=60 require='required'/>
                    <input type='password' name='password2' min=8 max=60 require='required'/>
                    <input type='submit' value='OK' name='OK'/></form>";
                }
                else
                {
                    echo $_POST['reset']."<br/>".$_POST['error_not_secure']."<br/>".$_POST['error_already_existing']."<br/>".$_POST['error_passwords_not_identical'];
                }
            ?>
        </div>
    </body>
</html>