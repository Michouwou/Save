<?php
    require_once('data_base.php');
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
            $query = 'UPDATE users SET active=1 WHERE username=?;';
            $prep = $pdo->prepare($query);
            $prep->bindValue(1, $_GET['login'], PDO::PARAM_STR);
            $prep->execute();
            $_POST['account_is_validated'] = "Votre compte vient d'être validé, vous pouvez maintenant vous connecter!";
        }
        else
        {
            $_POST['error_key_not_valid'] = "La clé de validation ne correspond pas au login fourni, votre compte ne peut être validé";
        }
    }
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
                echo '<p>'.$_POST['error_unknown_login'].'</p>'.
                        '<p>'.$_POST['account_is_validated'].'</p>'.
                       '<p>'.$_POST['error_key_not_valid'].'</p>' ;
            ?>
        </div>
    </body>
</html>